%option noyywrap
%option noinput
%option nounput

%{

#include <iostream>
#include <cstdlib>
using namespace std;
#include <string>
#include "date.hpp"
#include "parser.tab.hpp"

%}

%%

EUR return EUR;
USA return USA;
ISO return ISO;
print return print;
date return DATE;
"=" return DOD;

days {yylval.ime = new string(yytext);
					return tip;}
months {yylval.ime = new string(yytext);
					return tip;}
years {yylval.ime = new string(yytext);
					return tip;}

[a-zA-Z][a-zA-Z0-9]* {yylval.ime = new string(yytext);
return ID;}

[0-9]+ {yylval.vrednost = atoi(yytext);
		  return BROJ;} 


[-;,/.'<>!+()] return *yytext;
"==" return JEDNAKO;




[\n\t ] {}
. { cerr << "Leksicka greska: " << yytext << endl;
	exit(EXIT_FAILURE);}
%%o
