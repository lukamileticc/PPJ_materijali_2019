%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
#include "parser.tab.hpp"

%}


%%

print return PRINT;
int return INT;
list return LIST;
"<<" return MM;
">>" return VV;
"==" return EQV;


[-|&~+*/;()=\[\],] return *yytext;


[_][a-zA-z][a-z0-9]* { yylval.ime = new string(yytext); return ID;}

l[a-zA-Z0-9_]+ { yylval.ime = new string(yytext); return ID_L;}

(0|[1-9][0-9]*) {yylval.vrednost = atoi(yytext);
				return BROJ;}

0x(0|[1-9A-F][0-9A-F]*) {
	sscanf(yytext,"%x",&yylval.vrednost);
	return BROJ;
}

0(0|[1-7][0-7]*) {
	sscanf(yytext,"%o",&yylval.vrednost);
	return BROJ;
}

[ \t\n] {}
. { 
	cerr<< "Lekicka greska: " << yytext<< endl;
	exit(EXIT_FAILURE);
}

%%
