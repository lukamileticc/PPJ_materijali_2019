%option noyywrap

%{
#include <iostream>
#include "skup.hpp"
#include <cstdlib>
#include "parser.tab.hpp"

using namespace std;

%}


%%
UniversalSet return UNIVERSE;
check return CHECK;
card return CARD;
print return PRINT;
[A-Z][A-Za-z0-9]* { yylval.ime = new string(yytext);  return ID;}

".." return TT;
"\\" return R;
"\\/" return U;
"/\\" return P;
[={,};:<~] return *yytext;

-?[0-9]+ { yylval.vrednost = atoi(yytext);
			return BROJ;}
[ \n\t] {}
. { cerr << "Nepoznata leksema" << yytext << endl; exit(EXIT_FAILURE);}
%%
