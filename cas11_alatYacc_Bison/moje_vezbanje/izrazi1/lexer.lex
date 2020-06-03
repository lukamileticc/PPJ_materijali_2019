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

[0-9]+(\.[0-9]+)? {return BROJ;}
[+*()] { return yytext[0]; }
[\n \t] {}
. { 
	cerr << "Leksicka greska: Neprpoznat karakter " << *yytext << endl;
	exit(EXIT_FAILURE);
}

%%
