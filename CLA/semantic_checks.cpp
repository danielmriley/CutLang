// AST semantic checks.
#include "semantic_checks.h"
#include <cassert>

//#define _CLV_

#ifdef _CLV_
#define DEBUG(a) std::cout<<a
#else
#define DEBUG(a)
#endif

namespace adl {

  std::string tolower(std::string s);
  std::string toupper(std::string s);

  FunctionNode* getFunctionNode(Expr* expr) {
    return static_cast<FunctionNode*>(expr);
  }

  VarNode* getVarNode(Expr* expr) {
    return static_cast<VarNode*>(expr);
  }

  NumNode* getNumNode(Expr* expr) {
    return static_cast<NumNode*>(expr);
  }

  DefineNode* getDefineNode(Expr* expr) {
    return static_cast<DefineNode*>(expr);
  }

  BinNode* getBinNode(Expr* expr) {
    return static_cast<BinNode*>(expr);
  }

  astObjectNode* getObjectNode(Expr* expr) {
    return static_cast<astObjectNode*>(expr);
  }

  RegionNode* getRegionNode(Expr* expr) {
    return static_cast<RegionNode*>(expr);
  }

  CommandNode* getCommandNode(Expr* expr) {
    return static_cast<CommandNode*>(expr);
  }

  ITENode* getITENode(Expr* expr) {
    return static_cast<ITENode*>(expr);
  }

  int binOpCheck(Expr* b) {
    assert(b != nullptr && "NULL pointer.");
    if(b->getToken() == "EXPROP" || b->getToken() == "LOGICOP"
        || b->getToken() == "COMPAREOP" || b->getToken() == "FACTOROP") {
      return 0;
    }
    return 1;
  }

  FILE *fp;

  // template for parsing a binnode.

  // if(l) is a binop - do call to binopfunction
  // reconcile the operator.
  // if(r) is a binop - do call to binopfunction
  // then parse remaining binop pieces.

  int printNode(const int uid1, const char* str, const int uid2, const int uid3) {
    fprintf(fp, "%d [label=\"%s\", fontname=\"monospace\", style=filled, fillcolor=mintcream];\n ", uid1, str);
    fprintf(fp, "%d->%d\n", uid2, uid3);

    return 0;
  }

  int printDotOp(Expr* e) {
    VarNode *c = getVarNode(e);
    printNode(c->getUId()+1, (c->getDotOp()).c_str(), c->getUId(), c->getUId()+1);

    return 0;
  }

  int printNum(Expr* n, Expr* b) {
    NumNode* e = getNumNode(b);
    printNode(e->getUId(), (e->getId()).c_str(), n->getUId(), e->getUId());
    return 0;
  }

  int printVar(Expr* n, Expr* b) {
    VarNode *e = getVarNode(b);
    DEBUG("VarNode: " << e->getId() << " ");
    printNode(e->getUId(), (e->getId()).c_str(), n->getUId(), e->getUId());

    std::vector<int> acc = e->getAccessor();
    std::string range = "";
    if(acc.size() > 0) {
      for(int i = 0; i < acc.size(); i++) {
        if(i > 0) range += " : ";
        range += std::to_string(acc[i]);
        DEBUG( "ACCESSOR LOOP\n");
      }
      if(e->getDotOp() != "") {
        printDotOp(e);
      }
      printNode(e->getUId()+1, (range).c_str(), e->getUId(), e->getUId()+1);

      DEBUG( "RANGE: " << range << "\n");
    }
    DEBUG( "fin\n");
    return 0;
  }

  int printFunction(Expr* n, Expr* b) {
    FunctionNode* fn = getFunctionNode(b);
    VarNode *vr = getVarNode(fn->getVar());
    int idr = vr->getUId();
    DEBUG( "DEF FUNC: " << vr->getId() << "\n");
    printVar(n,vr);
    // loop through the function's params.
    ExprVector prms = fn->getParams();
    for(auto e: prms) {
      DEBUG( "PRMS: " << e->getToken() << ", ");
      if(binOpCheck(e) == 0) {
        DEBUG( "BINOP for FUNCTION\n");
        BinNode *bin = getBinNode(e);
        printBinNode(vr, bin);
      }
      else if(e->getToken() == "ID") {
        printVar(vr,e);
      }
    }
    DEBUG( std::endl);
    return 0;
  }

  int printBinNode(Expr* n, BinNode* b) {
    Expr* l = b->getLHS();
    Expr* r = b->getRHS();
    VarNode *vl, *vr;
    NumNode *nl, *nr;
    int idr, idl;

    if(l->getToken() == "ID") { // function needs to have leaves of params
      vl = getVarNode(l);
      idl = vl->getUId();
      printVar(b,l);
    }
    if(l->getToken() == "FUNCTION") {
      FunctionNode* fn = getFunctionNode(l);
      vl = getVarNode(fn->getVar());
      idl = vl->getUId();
      printVar(b,vl);
      // loop through the function's params.
      ExprVector prms = fn->getParams();
      for(auto e: prms) {
        printNode(e->getUId(), (e->getId()).c_str(), idl, e->getUId());
      }

    }
    if(l->getToken() == "INT" || l->getToken() == "REAL") {
      nl = getNumNode(l);
      idl = nl->getUId();
      printNode(idl, (nl->getId()).c_str(), b->getUId(), idl);
    }
    if(binOpCheck(l) == 0) {
      printBinNode(static_cast<Expr*>(b),getBinNode(l));
    }

    fprintf(fp, "%d [label=\"%s\", fontname=\"monospace\", style=filled, fillcolor=mintcream];\n ", b->getUId(), (b->getOp()).c_str());

    if(r->getToken() == "ID") {
      vr = getVarNode(r);
      idr = vr->getUId();
      printVar(b,r);
    }
    if(r->getToken() == "FUNCTION") {
      printFunction(b,r);
    }
    if(r->getToken() == "INT" || r->getToken() == "REAL") {
      nr = getNumNode(r);
      idr = nr->getUId();
      printNode(idr, (nr->getId()).c_str(), b->getUId(), idr);
    }
    if(binOpCheck(r) == 0) {
      printBinNode(static_cast<Expr*>(b),getBinNode(r));
    }

    //fprintf(fp, "%d [label=\"%s\", fontname=\"monospace\", style=filled, fillcolor=mintcream];\n ", b->getUId(), (b->getToken()).c_str());

    fprintf(fp, "%d->%d\n", n->getUId(), b->getUId());
//    fprintf(fp, "%d->%d\n", b->getUId(), b->getUId()+1);
    return 0;
  }

  int printITE(Expr* n, Expr* b) {
    if(b->getToken() == "ITE") {
      ITENode* ite = getITENode(b);
      Expr* i = ite->getCondition();
      Expr* t = ite->getThenBranch();
      Expr* e = ite->getElseBranch();

      if(binOpCheck(i) == 0) {
        printBinNode(n, getBinNode(i));
      }
      if(binOpCheck(t) == 0) {
        printBinNode(n, getBinNode(t));
      }
      if(binOpCheck(e) == 0) {
        printBinNode(n, getBinNode(e));
      }
    }

    return 0;
  }

  int printDefines(Expr* n) {
    VarNode* var = getVarNode(getDefineNode(n)->getVar());
    printVar(n,var);

    Expr* b = getDefineNode(n)->getBody();

    if(binOpCheck(b) == 0) {
      BinNode* bin = getBinNode(getDefineNode(n)->getBody());
      printBinNode(n, bin);
    }
    else if(b->getToken() == "FUNCTION") {
      printFunction(n,b);
    }
    else if(b->getToken() == "ID") {
      printVar(n,b);
    }
    else if(b->getToken() == "INT" || b->getToken() == "REAL") {
      printNum(n,b);
    }

    return 0;
  }

  int printRegions(Expr* n) {
    RegionNode *rn = static_cast<RegionNode*>(n);
    printNode(rn->getVarUId(), (rn->getId()).c_str(), rn->getUId(), rn->getVarUId());

    ExprVector ev = rn->getStatements();
    int stid = rn->getUId()+1; // For STATEMENTS node.
    Expr* stnode = new RegionNode(stid, "STATEMENTS", rn->getVar(), ExprVector());
    printNode(stid, (stnode->getToken()).c_str(), rn->getUId(), stnode->getUId());

    for(auto& stmnt: ev) {
      Expr* cond = static_cast<CommandNode*>(stmnt)->getCondition();
      printNode(stmnt->getUId(), (stmnt->getToken()).c_str(), stnode->getUId(), stmnt->getUId());
      if(binOpCheck(cond) == 0) {
        BinNode* bin = getBinNode(cond);
        printBinNode(stmnt, bin);
      }
      else if(cond->getToken() == "FUNCTION") {
        printFunction(stmnt, cond);
      }
      else if(cond->getToken() == "ID") {
        printVar(stmnt,cond);
      }
      else if(cond->getToken() == "ITE") {
        DEBUG( "NEED TO PRINT ITE NODE\n");
        printITE(stmnt, cond);
      }
    }

    return 0;
  }

  int printObjects(Expr* n) {
    astObjectNode *on = static_cast<astObjectNode*>(n);
    printNode(on->getVarUId(), (on->getId()).c_str(), on->getUId(), on->getVarUId());

    ExprVector ev = on->getStatements();
    int stid = on->getUId()+1; // For STATEMENTS node.
    Expr* stnode = new astObjectNode(stid, "STATEMENTS", on->getVar(), ExprVector());
    printNode(stid, (stnode->getToken()).c_str(), on->getUId(), stnode->getUId());

    for(auto& stmnt: ev) {
      Expr* cond = static_cast<CommandNode*>(stmnt)->getCondition();
      printNode(stmnt->getUId(), (stmnt->getToken()).c_str(), stnode->getUId(), stmnt->getUId());
      if(binOpCheck(cond) == 0) {
        BinNode* bin = getBinNode(cond);
        printBinNode(stmnt, bin);
      }
      else if(cond->getToken() == "FUNCTION") {
        printFunction(stmnt, cond);
      }
      else if(cond->getToken() == "ID") {
        printVar(stmnt,cond);
      }
    }

    return 0;
  }

  int print(ExprVector& _ast) {
    int i = 0;
    for(auto& n: _ast) {
      i++;

      fprintf(fp, "ordering = \"out\"");
      fprintf(fp, "%d [label=\"%s\", fontname=\"monospace\", style=filled, fillcolor=mintcream];\n ", n->getUId(), (n->getToken()).c_str());

      if(n->getToken() == "DEFINE") {
        printDefines(n);
      }
      if(n->getToken() == "REGION") {
        printRegions(n);
      }
      if(n->getToken() == "OBJECT") {
        printObjects(n);
      }
    }
    return 0;
  }

  int printAST(ExprVector& _ast) {
    DEBUG( "\n==== PRINT AST ====\n");
    fp = fopen("ast.dot", "w");
    fprintf(fp, "digraph print {\n ");
    print(_ast);
    fprintf(fp, "}\n ");
    fclose(fp);
    DEBUG( "\n====           ====\n");

    return 0;
  }

  std::string typeCheck(Expr* node, Driver& drv) {
    if(binOpCheck(node) == 0) {
      typeCheck(getBinNode(node)->getLHS(),drv);
      typeCheck(getBinNode(node)->getRHS(),drv);
    }

    DEBUG( "typecheck token: " << node->getToken() << "\n");
    if(node->getToken() == "INT") { DEBUG( " : INTEGER\n"); return node->getToken(); }
    if(node->getToken() == "REAL") { DEBUG( " : DOUBLE\n"); }
    if(node->getToken() == "ID") {
      DEBUG( "VAR := " << node->getId() << " \n");
      VarNode* vn = getVarNode(node);
      if(vn->getType() == "") {
        DEBUG( "vn type empty\n");
        for(auto& obj: drv.objectTable) {
          if(obj.first == vn->getId()) {
            vn->setType(obj.second);
          }
        }
        DEBUG( "Type set: " << vn->getType() << "\n");
      }
      else {
        DEBUG( "Type Found: " << vn->getType() << "\n");
      }
    }
    if(node->getToken() == "FUNCTION") {
      // Here the function input and output should be checked.
      DEBUG( "FUNCTION NODE\n");
    }
    return "UNKNOWN\n";
  }

  int typeCheck(Driver& drv) {
    for(auto& v: drv.ast) {
      std::string token = v->getToken();
      DEBUG( "TypeCheck token: " << token << "\n");
      if(token == "DEFINE") {
        DEBUG( "\n====define====\n");
        DefineNode* define = getDefineNode(v);
        Expr* body = define->getBody();
        if(binOpCheck(body) == 0) {
          BinNode* bin = getBinNode(body);
          typeCheck(bin->getLHS(),drv);
          typeCheck(bin->getRHS(),drv);
        }
        if(body->getToken() == "FUNCTION") {
          typeCheck(body,drv);

        }
      }
      if(token == "REGION") {
        DEBUG( "\n====region====\n");
        RegionNode* region = static_cast<RegionNode*>(v);
        std::vector<Expr*> vv = region->getStatements();
        for(auto& s: vv) {
          Expr* cond = static_cast<CommandNode*>(s)->getCondition();
          if(binOpCheck(cond) == 0) {
            BinNode* bin = getBinNode(cond);
            typeCheck(bin->getLHS(),drv);
            typeCheck(bin->getRHS(),drv);
          }
          if(cond->getToken() == "FUNCTION") {
            typeCheck(cond,drv);

          }
        }
      }
      if(token == "OBJECT") {
        DEBUG( "\n====object====\n");
        astObjectNode* object = static_cast<astObjectNode*>(v);
        std::vector<Expr*> vv = object->getStatements();
        for(auto& s: vv) {
          Expr* cond = static_cast<CommandNode*>(s)->getCondition();
          if(binOpCheck(cond) == 0) {
            BinNode* bin = getBinNode(cond);
            typeCheck(bin->getRHS(),drv);
            typeCheck(bin->getRHS(),drv);
          }
          if(cond->getToken() == "FUNCTION") {
            typeCheck(cond,drv);

          }
        }
      }
    }
    return 0;
  }

  void printError(std::string var) {
    std::cerr << "ERROR: VAR " << var << " IS NOT DECLARED\n";
  }

  int checkTables(Driver& drv, Expr* v) {
    std::string var = v->getId();
    if(drv.checkObjectTable(var) == 0) return 0;
    if(drv.checkDefinitionTable(var) == 0) return 0;
    if(drv.checkRegionTable(var) == 0) return 0;
    printError(var);
    return 1;
  }

  int parseBinNode(Driver& drv, BinNode* b) {
    Expr* lhs = b->getLHS();
    Expr* rhs = b->getRHS();
    DEBUG( "binOp: " << b->getOp() << "\n");
    int res;
    int fres = 0;

    DEBUG( "LHS TOKEN: " << lhs->getToken() << "\n");
    DEBUG( "RHS TOKEN: " << rhs->getToken() << "\n");

    if(binOpCheck(lhs) == 0) {
      res = parseBinNode(drv, getBinNode(lhs));
    }
    if(res == 1) fres = 1;
    if(binOpCheck(rhs) == 0) {
      res = parseBinNode(drv, getBinNode(rhs));
    }
    if(res == 1) fres = 1;

    if(lhs->getToken() == "ID") {
      res = checkTables(drv, lhs);
    }
    if(res == 1) fres = 1;

    if(rhs->getToken() == "ID") {
      res = checkTables(drv, rhs);
    }
    if(res == 1) fres = 1;

    return fres;
  }

  // "Declare before use check"
  int checkDecl(Driver& drv) {
    // Check that the objects and defines in regions have been declared first.
    // Doesn't check function parameters yet...
    int res = 0;
    for(auto v: drv.ast) {
      DEBUG( "RES: " << res << "\n");
      if(res == 1) { return res; }
      std::string token = v->getToken();
      if(token == "OBJECT") {
        DEBUG( "\n==== object sem checks ====\n");
        astObjectNode* object = static_cast<astObjectNode*>(v);
        std::vector<Expr*> stmnts = object->getStatements();
        for(auto s: stmnts) {
          Expr* cond = static_cast<CommandNode*>(s)->getCondition();
          token = s->getToken();
          if(token == "TAKE") {
            // Check the takes for DBU.
            std::string var = cond->getId();
            DEBUG( "var: " << var << "\n");
            if(tolower(var) == "union") {
              DEBUG( "UNION function\n");
            }
            else if(drv.check_object_table(var) == 1 && drv.checkObjectTable(var) == 1) {
              printError(var);
              res = 1;
            }
          }
        }
      }
      if(token == "REGION") {
        DEBUG( "\n==== region sem checks ====\n");
        RegionNode* region = static_cast<RegionNode*>(v);
        DEBUG(" uid: " << region->getUId() << "\n");
        DEBUG( "region->getToken(): " << region->getToken() << "\n");
        DEBUG( "region->getId(): " << region->getId() << "\n");
        std::vector<Expr*> stmnts = region->getStatements();
        for(auto& s: stmnts) {
          DEBUG( "s->getId(): " << s->getId() << "\n");
          DEBUG( "s->getToken(): " << s->getToken() << "\n");
//          if(s->getToken() == "histo") continue;
          Expr* cond = static_cast<CommandNode*>(s)->getCondition();
          DEBUG( "cond->getId(): " << cond->getId() << "\n");
          if(s->getId() == "" || checkTables(drv,cond) == 0) { DEBUG( "continuing\n"); continue; }
          if(binOpCheck(cond) == 0) {
            BinNode* bin = getBinNode(cond);
            res = parseBinNode(drv, bin);
          }
          if(cond->getToken() == "ID") {
            res = checkTables(drv, cond);
          }
        }
      }
      if(token == "DEFINE") {
        DEBUG( "\n==== define sem checks ====\n");
        DefineNode* dn = getDefineNode(v);
        DEBUG(" uid: " << dn->getUId() << "\n");
        DEBUG( "define->getToken(): " << dn->getToken() << "\n");
        DEBUG( "define->getId(): " << dn->getId() << "\n");
        Expr* bdy = dn->getBody();

        if(binOpCheck(bdy) == 0) {
          BinNode* bin = getBinNode(bdy);
          res = parseBinNode(drv, bin);
        }
        if(bdy->getToken() == "ID") {
          res = checkTables(drv,bdy);
        }
        if(bdy->getToken() == "FUNCTION") {
          DEBUG( "Function def\n");
        }
      }
    }
    DEBUG( "\n");

    drv.setDependencyChart();
    return res;
  }

  void collectBinOpers(Expr* body, ExprVector& operands) {
    BinNode* bin = getBinNode(body);
    Expr* rhs = bin->getRHS();
    Expr* lhs = bin->getLHS();

    if(binOpCheck(rhs) == 0) collectBinOpers(rhs, operands);
    if(binOpCheck(lhs) == 0) collectBinOpers(lhs, operands);

    if(rhs->getToken() == "ID") operands.push_back(rhs);
    if(lhs->getToken() == "ID") operands.push_back(lhs);

    if(rhs->getToken() == "FUNCTION") {
      FunctionNode* fn = getFunctionNode(rhs);
      operands.push_back(fn->getVar());
    }
    if(lhs->getToken() == "FUNCTION") {
      FunctionNode* fn = getFunctionNode(lhs);
      operands.push_back(fn->getVar());
    }
  }

  void collectBinOpObjects(std::vector<std::string> &objs, BinNode* cond) {
    Expr* lhs = cond->getLHS();
    Expr* rhs = cond->getRHS();

    if(lhs->getToken() == "ID") {
      objs.push_back(lhs->getId());
    }
    else if(lhs->getToken() == "FUNCTION") {
      FunctionNode* func = static_cast<FunctionNode*>(lhs);
      auto params = func->getParams();
      for(auto &p: params) {
        if(p->getToken() == "ID") {
          objs.push_back(p->getId());
        }
      }
    }
    else if(lhs->getToken() == "INT" || lhs->getToken() == "REAL") { /* skip */ }
    else if(binOpCheck(lhs) == 0) {
      BinNode* lhsBin = static_cast<BinNode*>(lhs);
      collectBinOpObjects(objs, lhsBin);
    }

    if(rhs->getToken() == "ID") {
      objs.push_back(rhs->getId());
    }
    else if(rhs->getToken() == "FUNCTION") {
      FunctionNode* func = static_cast<FunctionNode*>(rhs);
      auto params = func->getParams();
      for(auto &p: params) {
        if(p->getToken() == "ID") {
          objs.push_back(p->getId());
        }
      }
    }
    else if(rhs->getToken() == "INT" || rhs->getToken() == "REAL") { /* skip */ }
    else if(binOpCheck(rhs) == 0) {
      BinNode* rhsBin = static_cast<BinNode*>(rhs);
      collectBinOpObjects(objs, rhsBin);
    }
  }

  int printFlowChart(Driver& drv) {
    DEBUG( "\n==== PRINT FLOW CHART ====\n");
    fp = fopen("fc.dot", "w");
    fprintf(fp, "digraph print {\n");
    fprintf(fp, "ordering = \"out\"");
    // fprintf(fp, "overlap = prism");
    // fprintf(fp, "overlap_scaling = 0.01");
    fprintf(fp, "ratio = 1.618");

    ExprVector _ast = drv.ast;
    std::set<std::string> prints;
    for(auto& n: _ast) {

      if(n->getToken() == "DEFINE") {
        DefineNode* dn = getDefineNode(n);

      }
      if(n->getToken() == "REGION") {
        RegionNode* rn = getRegionNode(n);
        auto stmnts = rn->getStatements();

        std::string regName = rn->getId();
        prints.insert(regName + "[shape= box, color=green]\n");

        for(auto&s: stmnts) {
          Expr* cond = static_cast<CommandNode*>(s)->getCondition();
          std::string var = cond->getId();

          std::vector<std::string> objs;
          if(binOpCheck(cond) == 0) {
            collectBinOpObjects(objs, static_cast<BinNode*>(cond));
            for(auto& o: objs) {
              if(drv.checkDefinitionTable(o) != 0 && drv.checkObjectTable(o) == 0) {
                prints.insert("  " + o + " -> " + rn->getId() + " [color=\"grey\"]\n");
              }
            }
          }
          else if(cond->getToken() == "FUNCTION") {
            FunctionNode* func = static_cast<FunctionNode*>(cond);
            auto params = func->getParams();
            for(auto &p: params) {
              if(p->getToken() == "ID") {
                if(drv.checkObjectTable(cond->getId()) == 0 || drv.checkRegionTable(cond->getId()) == 0)
                  prints.insert("  " + p->getId() + " -> " + regName + " [color=\"grey\"]\n");
              }
            }
          }
          else if(cond->getToken() == "ID") {
            if(drv.checkObjectTable(cond->getId()) == 0 || drv.checkRegionTable(cond->getId()) == 0)
              prints.insert("  " + cond->getId() + " -> " + regName + "[color=\"green\"]");
          }
        }
      }
      if(n->getToken() == "OBJECT") {
        astObjectNode* on = getObjectNode(n);
        auto stmnts = on->getStatements();

        for(auto &s: stmnts) {
          if(s->getToken() == "TAKE") {
            Expr* cond = static_cast<CommandNode*>(s)->getCondition();
            std::string var = cond->getId();
            std::string varDeclType = drv.getObjectDeclType(var);
            if(varDeclType != "NOT FOUND" && varDeclType == "PARENT") {
              prints.insert(var + " [color=\"red\"]\n");
              prints.insert(on->getId() + " [color=\"blue\"]\n");
              prints.insert("  " + var + " -> " + on->getId() + " [color=\"blue\"]\n");
            }
            else if(drv.checkObjectTable(var) == 0) { // Here means its a declared type.
              prints.insert(on->getId() + " [color=\"blue\"]\n");
              prints.insert("  " + var + " -> " + on->getId() + " [color=\"blue\"]\n");
            }
            else {
              DEBUG( "Not an object\n");
            }
          }
        }
      }
    }

    for(auto& p: prints) {
      fprintf(fp, "%s", p.c_str());
    }

    fprintf(fp, "}\n ");
    fclose(fp);
    DEBUG( "\n====                 ====\n");

    return 0;
  }
} // end namespace adl
