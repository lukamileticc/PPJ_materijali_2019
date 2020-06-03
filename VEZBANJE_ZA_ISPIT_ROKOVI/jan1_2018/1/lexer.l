%option noyywrap
%option noinput
%option nounput
%{
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#include "parser.tab.hpp"
%}

%%
eqv return 	EQV;
ugao return UGAO;
":=" return DOD;
print return PRINT;

[a-z] { yylval.ime = new string(yytext);
		return ID;}

(-)?[0-9][0-9]* {yylval.vrednost = atoi(yytext);
		return BROJ;}

[-+*;<>,().||] return *yytext;

[\t\n ] {}
. { cerr << "Leksicka greska!" << yytext << endl;
	exit(EXIT_FAILURE);}
%%

