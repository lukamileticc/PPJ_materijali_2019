%option noyywrap
%option noinput
%option nounput

%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "y.tab.h"
%}


%%
[.+*();] return yytext[0];

[a-zA-Z] { yylval.ime = tolower(yytext[0]);
		return id_token;}

[0-9]+|0[xX][a-fA-F0-9]+ {  yylval.vrednost = atoi(yytext);
			return BROJ;}

ispisi {return ispisi_token;}
kraj {return kraj_token;}
pocetak {return pocetak_token;}
mod  {return MOD;}
":="  return dod_token;

 /* za nisku! */

["][A-Za-z\t !\-?.;,:0-9]+["] {
	strncpy(yylval.niska,yytext+1,strlen(yytext)-2);
	return NISKA;
}	


[\t\n ] {}
. { fprintf(stderr,"Nepoznata leksema: %s \n",yytext);
	exit(EXIT_FAILURE);}

%%
