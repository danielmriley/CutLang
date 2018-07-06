%option noyywrap
%{
#include "stdlib.h"
#include <string>
#include <iostream>
#include "y.tab.h"
int i=0;
%}
integer [0-9]+
exp [eE][+-]?{integer}
real {integer}("."{integer})?{exp}?
varname [a-zA-Z]+{integer}
vardef {varname}" "?":"" "?.*"\n"
%%
"def" return DEF;//case sensitive in this case
"cmd" return CMD;
"ELE" return ELE;
"MUO" return MUO;
"LEP" return LEP;
"PHO" return PHO;
"JET" return JET;
"BJET" return BJET;
"QGJET" return QGJET;
"NUMET" return NUMET;
"METLV" return METLV;
"#".*"\n" ;
[ \t\n] ;
[tT][aA][nN] return TAN;
[sS][iI][nN] return SIN;
[cC][oO][sS] return COS;
{integer} sscanf(yytext, "%lf",&yylval.real);return INT;//to test
{real} sscanf(yytext, "%lf",&yylval.real);return NB ;
[-+*/()^:{}_] return *yytext;
[a-zA-Z]+{integer} yylval.s=strdup(yytext);return ID;
%%