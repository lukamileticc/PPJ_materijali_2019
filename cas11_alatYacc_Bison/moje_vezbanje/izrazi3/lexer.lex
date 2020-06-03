%option noyywrap
%option noinput
%option nounput


%{

#include <iostream>
#include <cstdlib>

using namespace std;
#include "parser.tab.hpp"
%}

%%

[0-9]+ { yylval.vrednost = atof(yytext);
		return BROJ;}
[+/*-] { return yytext[0];}
[ \n\t] {}
. { cerr <<"Lekiscka greska: leksema ne postoji: " << yytext << endl;
	exit(EXIT_FAILURE);}
%%
