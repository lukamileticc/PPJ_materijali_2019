%option noyywrap
%option noinput
%option nounput
%{

#include <iostream>
#include <cstdlib>
#include <string>
#include "polinom.hpp" //bitno
#include "parser.tab.hpp"
using namespace std;

%}

%%

[a-zA-Z_][a-zA-Z_0-9]* {yylval.ime = new string(yytext);
 return ID;
}
[+-]?[0-9]+(\.[0-9]*)? { yylval.x = atof(yytext);
return BROJ;}

":=" return DOD;
"==" return EQ;
"!=" return NEQ;

[-+*\[\](),'|$<>\n] {return *yytext;}
[\t ] {}
. { cerr << "Leksicka greska: " << yytext << endl;
	exit(EXIT_FAILURE);}

%%
