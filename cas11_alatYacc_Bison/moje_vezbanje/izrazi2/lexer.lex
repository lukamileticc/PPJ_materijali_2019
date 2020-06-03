%option noyywrap
%option noinput
%option nounput

%{
#include <iostream>
#include "parser.tab.hpp"
#include <cstdlib>
using namespace std;

%}

%%

[0-9]+ { yylval.vrednost = atoi(yytext) ;
			      return BROJ;}
[+*()] return yytext[0];
[ \n\t] {}
. {
	cerr << "Leksicka greska! " << endl;
	exit(EXIT_FAILURE); }
%%
