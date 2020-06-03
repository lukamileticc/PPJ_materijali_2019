%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "parser.tab.hpp"
%}


%%
print return print;
vector return VECTOR;
"=" return DOD;

[a-z][0-9]* {yylval.ime = new string(yytext); return ID;}

[-,;+*()\[\]] return *yytext;

-?[0-9][0-9]*(\.[0-9][0-9]*)? {yylval.vrednost = atof(yytext); 
	return BROJ;}



[\t\n ] {}
. { cerr << "Leksicka greska: " << yytext  << endl;
	exit(EXIT_FAILURE);}
%%
