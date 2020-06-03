%option noyywrap
%option noinput
%option nounput


%{
#include <iostream>
#include <cstdlib>

#include "parser.tab.hpp"
using namespace std;

%}


%%
[0-9]+(\.[0-9]+)? {
	yylval.vrednost = atof(yytext);
	return broj_token;
}
print return print_token;

[a-zA-Z_][a-zA-z0-9]* {
	yylval.id = new string(yytext);
	return id_token;
}
[\n=+*()/-] return *yytext;
[ \t] {}

. { cerr << "Leksicka greska: Neprepoznat simbol " << yytext << endl;
	exit(EXIT_FAILURE);}
%%
