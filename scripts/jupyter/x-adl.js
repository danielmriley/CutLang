(function(mod) {
    if (typeof exports == "object" && typeof module == "object") // CommonJS
      mod(require("../../../../lib/codemirror"));
    else if (typeof define == "function" && define.amd) // AMD
      define(["../../../../lib/codemirror"], mod);
    else // Plain browser env
      mod(CodeMirror);
  })(function(CodeMirror) {
  "use strict";
  
  function Context(indented, column, type, info, align, prev) {
    this.indented = indented;
    this.column = column;
    this.type = type;
    this.info = info;
    this.align = align;
    this.prev = prev;
  }
  function pushContext(state, col, type, info) {
    var indent = state.indented;
    if (state.context && state.context.type == "statement" && type != "statement")
      indent = state.context.indented;
    return state.context = new Context(indent, col, type, info, null, state.context);
  }
  function popContext(state) {
    var t = state.context.type;
    if (t == ")" || t == "]" || t == "}")
      state.indented = state.context.indented;
    return state.context = state.context.prev;
  }
  
  function typeBefore(stream, state, pos) {
    if (state.prevToken == "variable" || state.prevToken == "type") return true;
    if (/\S(?:[^- ]>|[*\]])\s*$|\*$/.test(stream.string.slice(0, pos))) return true;
    if (state.typeAtEndOfLine && stream.column() == stream.indentation()) return true;
  }
  
  function isTopScope(context) {
    for (;;) {
      if (!context || context.type == "top") return true;
      if (context.type == "}" && context.prev.info != "namespace") return false;
      context = context.prev;
    }
  }
  
  CodeMirror.defineMode("clike", function(config, parserConfig) {
    var indentUnit = config.indentUnit,
        statementIndentUnit = parserConfig.statementIndentUnit || indentUnit,
        dontAlignCalls = parserConfig.dontAlignCalls,
        keywords = parserConfig.keywords || {},
        types = parserConfig.types || {},
        builtin = parserConfig.builtin || {},
        blockKeywords = parserConfig.blockKeywords || {},
        defKeywords = parserConfig.defKeywords || {},
        atoms = parserConfig.atoms || {},
        hooks = parserConfig.hooks || {},
        multiLineStrings = parserConfig.multiLineStrings,
        indentStatements = parserConfig.indentStatements !== false,
        indentSwitch = parserConfig.indentSwitch !== false,
        namespaceSeparator = parserConfig.namespaceSeparator,
        isPunctuationChar = parserConfig.isPunctuationChar || /[\[\]{}\(\),;\:\.]/,
        numberStart = parserConfig.numberStart || /[\d\.]/,
        number = parserConfig.number || /^(?:0x[a-f\d]+|0b[01]+|(?:\d+\.?\d*|\.\d+)(?:e[-+]?\d+)?)(u|ll?|l|f)?/i,
        isOperatorChar = parserConfig.isOperatorChar || /[+\-*&%=<>!?|\/]/,
        isIdentifierChar = parserConfig.isIdentifierChar || /[\w\$_\xa1-\uffff]/,
        // An optional function that takes a {string} token and returns true if it
        // should be treated as a builtin.
        isReservedIdentifier = parserConfig.isReservedIdentifier || false;
  
    var curPunc, isDefKeyword;
  
    function tokenBase(stream, state) {
      var ch = stream.next();
      if (hooks[ch]) {
        var result = hooks[ch](stream, state);
        if (result !== false) return result;
      }
      if (ch == '"' || ch == "'") {
        state.tokenize = tokenString(ch);
        return state.tokenize(stream, state);
      }
      if (isPunctuationChar.test(ch)) {
        curPunc = ch;
        return null;
      }
      if (numberStart.test(ch)) {
        stream.backUp(1)
        if (stream.match(number)) return "number"
        stream.next()
      }
      if (ch == "/") {
        if (stream.eat("*")) {
          state.tokenize = tokenComment;
          return tokenComment(stream, state);
        }
        if (stream.eat("/")) {
          stream.skipToEnd();
          return "comment";
        }
      }
      if (isOperatorChar.test(ch)) {
        while (!stream.match(/^\/[\/*]/, false) && stream.eat(isOperatorChar)) {}
        return "operator";
      }
      stream.eatWhile(isIdentifierChar);
      if (namespaceSeparator) while (stream.match(namespaceSeparator))
        stream.eatWhile(isIdentifierChar);
  
      var cur = stream.current();
      if (contains(keywords, cur)) {
        if (contains(blockKeywords, cur)) curPunc = "newstatement";
        if (contains(defKeywords, cur)) isDefKeyword = true;
        return "keyword";
      }
      if (contains(types, cur)) return "type";
      if (contains(builtin, cur)
          || (isReservedIdentifier && isReservedIdentifier(cur))) {
        if (contains(blockKeywords, cur)) curPunc = "newstatement";
        return "builtin";
      }
      if (contains(atoms, cur)) return "atom";
      return "variable";
    }
  
    function tokenString(quote) {
      return function(stream, state) {
        var escaped = false, next, end = false;
        while ((next = stream.next()) != null) {
          if (next == quote && !escaped) {end = true; break;}
          escaped = !escaped && next == "\\";
        }
        if (end || !(escaped || multiLineStrings))
          state.tokenize = null;
        return "string";
      };
    }
  
    function tokenComment(stream, state) {
      var maybeEnd = false, ch;
      while (ch = stream.next()) {
        if (ch == "/" && maybeEnd) {
          state.tokenize = null;
          break;
        }
        maybeEnd = (ch == "*");
      }
      return "comment";
    }
  
    function maybeEOL(stream, state) {
      if (parserConfig.typeFirstDefinitions && stream.eol() && isTopScope(state.context))
        state.typeAtEndOfLine = typeBefore(stream, state, stream.pos)
    }
  
    // Interface
  
    return {
      startState: function(basecolumn) {
        return {
          tokenize: null,
          context: new Context((basecolumn || 0) - indentUnit, 0, "top", null, false),
          indented: 0,
          startOfLine: true,
          prevToken: null
        };
      },
  
      token: function(stream, state) {
        var ch = stream.peek();
        /* comments */
        if (ch == "#" && (stream.pos == 0 || /\s/.test(stream.string.charAt(stream.pos - 1)))) {
            stream.skipToEnd();
            return "comment";
        }

        if (stream.match(/^('([^']|\\.)*'?|"([^"]|\\.)*"?)/)) return "string";
        
        var number=/^(?:0x[a-f\d]+|0b[01]+|(?:\d+\.?\d*|\.\d+)(?:e[-+]?\d+)?)(u|ll?|l|f)?/i
        if (stream.match(number)) return "number"



        var ctx = state.context;
        if (stream.sol()) {
          if (ctx.align == null) ctx.align = false;
          state.indented = stream.indentation();
          state.startOfLine = true;
        }
        if (stream.eatSpace()) { maybeEOL(stream, state); return null; }
        curPunc = isDefKeyword = null;
        var style = (state.tokenize || tokenBase)(stream, state);
        if (style == "comment" || style == "meta") return style;
        if (ctx.align == null) ctx.align = true;
  
        if (curPunc == ";" || curPunc == ":" || (curPunc == "," && stream.match(/^\s*(?:\/\/.*)?$/, false)))
          while (state.context.type == "statement") popContext(state);
        else if (curPunc == "{") pushContext(state, stream.column(), "}");
        else if (curPunc == "[") pushContext(state, stream.column(), "]");
        else if (curPunc == "(") pushContext(state, stream.column(), ")");
        else if (curPunc == "}") {
          while (ctx.type == "statement") ctx = popContext(state);
          if (ctx.type == "}") ctx = popContext(state);
          while (ctx.type == "statement") ctx = popContext(state);
        }
        else if (curPunc == ctx.type) popContext(state);
        else if (indentStatements &&
                 (((ctx.type == "}" || ctx.type == "top") && curPunc != ";") ||
                  (ctx.type == "statement" && curPunc == "newstatement"))) {
          pushContext(state, stream.column(), "statement", stream.current());
        }
  
        if (style == "variable" &&
            ((state.prevToken == "def" ||
              (parserConfig.typeFirstDefinitions && typeBefore(stream, state, stream.start) &&
               isTopScope(state.context) && stream.match(/^\s*\(/, false)))))
          style = "def";
  
        if (hooks.token) {
          var result = hooks.token(stream, state, style);
          if (result !== undefined) style = result;
        }
  
        if (style == "def" && parserConfig.styleDefs === false) style = "variable";
  
        state.startOfLine = false;
        state.prevToken = isDefKeyword ? "def" : style || curPunc;
        maybeEOL(stream, state);
        return style;
      },
  
      indent: function(state, textAfter) {
        if (state.tokenize != tokenBase && state.tokenize != null || state.typeAtEndOfLine) return CodeMirror.Pass;
        var ctx = state.context, firstChar = textAfter && textAfter.charAt(0);
        var closing = firstChar == ctx.type;
        if (ctx.type == "statement" && firstChar == "}") ctx = ctx.prev;
        if (parserConfig.dontIndentStatements)
          while (ctx.type == "statement" && parserConfig.dontIndentStatements.test(ctx.info))
            ctx = ctx.prev
        if (hooks.indent) {
          var hook = hooks.indent(state, ctx, textAfter, indentUnit);
          if (typeof hook == "number") return hook
        }
        var switchBlock = ctx.prev && ctx.prev.info == "switch";
        if (parserConfig.allmanIndentation && /[{(]/.test(firstChar)) {
          while (ctx.type != "top" && ctx.type != "}") ctx = ctx.prev
          return ctx.indented
        }
        if (ctx.type == "statement")
          return ctx.indented + (firstChar == "{" ? 0 : statementIndentUnit);
        if (ctx.align && (!dontAlignCalls || ctx.type != ")"))
          return ctx.column + (closing ? 0 : 1);
        if (ctx.type == ")" && !closing)
          return ctx.indented + statementIndentUnit;
  
        return ctx.indented + (closing ? 0 : indentUnit) +
          (!closing && switchBlock && !/^(?:case|default)\b/.test(textAfter) ? indentUnit : 0);
      },
  
      electricInput: indentSwitch ? /^\s*(?:case .*?:|default:|\{\}?|\})$/ : /^\s*[{}]$/,
      blockCommentStart: "/*",
      blockCommentEnd: "*/",
      blockCommentContinue: " * ",
      lineComment: "//",
      fold: "brace"
    };
  });
  
    function words(str) {
        str={str}
        var separators = [' ', '\t', '\n']
        var process = [str]
        for(var a=0;a<process.length;a++){
            for(const [key, value] of Object.entries(process[a])){
                process[a][key]=value.split(new RegExp(separators.join('|'), 'g'))
            }
            for(const [key, value] of Object.entries(process[a])){
                    for(var i=0;i<value.length;i++){
                        if(process[a][key][i]=="" || !process[a][key][i]){
                            delete process[a][key][i]
                        }
                    }
            }
        }
        var obj = {}
        for (var i = 0; i < str.str.length; ++i) if (str.str[i]) obj[str.str[i]] = true;
        return obj;
    }
    function contains(words, word) {
      if (typeof words === "function") {
        return words(word);
      } else {
        return words.propertyIsEnumerable(word);
      }
    }
    
    var ADLKeywords = `
        def define
        cmd cut select command
        obj object
        algo region algorithm



        reject TRGe TRGm

        info experiment id title publication sqrtS lumi arXiv hepdata doi

        counts countsformat stat syst process
        
        systematic
    `
    var ADLBlockKeywords = `
        union alias btag ctag tautag pdgid ptcone etcone status vertext vertexx vertexy vertexz
        vertextr btagdeepb msoftdrop daughters constituents tau1 tau2 tau3
        fmegajets fhemisphere fmr fmtr fmt2 fmtautau minipfrelisoall relisoall pfrelIso03all dxy
        d0 dz dmvanewdm2017v2 softid applyhm iddecaymode idisotight idantieletight
        idantimutight tightid puid genpartidx decaymode HLT_IsoMu17_eta2p1_LooseIsoPFTau20 sieie
        
        phi eta rap abseta pt pz dr dphi deta size count numof nbf fht metmwt mwt met all lepsf btagsf xslumicorrsf
    `
    var ADLAtomsKeywords = `
        ontrue offfalse nvars errors tabletype takeusing histo weight table skiphistos skipeffs gen ele electron
        muo muon tau pho photon jet fjet fatjet qgjet bin numet metlv lep hlt bjet
    `
  
    function def(mimes, mode) {
      if (typeof mimes == "string") mimes = [mimes];
      var words = [];
      function add(obj) {
        if (obj) for (var prop in obj) if (obj.hasOwnProperty(prop))
          words.push(prop);
      }
      add(mode.keywords);
      add(mode.types);
      add(mode.builtin);
      add(mode.atoms);
      if (words.length) {
        mode.helperType = mimes[0];
        CodeMirror.registerHelper("hintWords", mimes[0], words);
      }
  
      for (var i = 0; i < mimes.length; ++i)
        CodeMirror.defineMIME(mimes[i], mode);
    }
  
    def("text/x-adl", {
      name: "clike",
      keywords: words(ADLKeywords),
      typeFirstDefinitions: true,
      blockKeywords: words(ADLBlockKeywords),
      atoms: words(ADLAtomsKeywords)
    });
  
});
  