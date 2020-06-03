%option noyywrap
%option noinput
%option nounput

%{
#include <vector>
#include "formula.hpp"
using namespace std;
#include <iostream>
#include <cstdlib>
#include "parser.tab.hpp"

#include <string>



%}

%%
head return HEAD;
tail return TAIL;
True return TRUE_TOKEN;
False return FALSE_TOKEN;
Undef return UNDEF_TOKEN;
					
":=" return DOD;
"<=>" return EQV;
"=>" return IMPL;
[!] return NOT;
"/\\" return I;
"\\/" return ILI;

[0-9]* {yylval.vrednost = atoi(yytext);return BROJ;}
[A-Z][a-z0-9]* {yylval.ime_liste = new string(yytext);
		return L_ID;}
[a-z][0-9]* { yylval.ime = new string(yytext);
		return ID;}

[()\n,\[\]] return *yytext;

[ \t] {}
. { cerr << "Sintaksna greska!" << endl;
	 exit(EXIT_FAILURE);}
%%
