%{
	#include "gambox.hpp"
%}

%option yylineno noyywrap

%%
#.*                     {}                      // line comment
[ \t\r\n]+              {}                      // drop spaces
":"                     TOKEN(Op,COLON)         // :
";"                     TOKEN(Op,SEMICOLON)     // ;
[_a-zA-Z][_a-zA-Z0-9]*  TOKEN(Sym,SYM)          // symbol
.                       {yyerror("");}          // undetected char
