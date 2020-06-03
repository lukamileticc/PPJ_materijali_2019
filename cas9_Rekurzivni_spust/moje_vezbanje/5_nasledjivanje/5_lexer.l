%option noyywrap
%option noinput
%option nounput

%{
#include <stdlib.h>
#include "tokeni.h"
extern int yyval;
%}

%%

"(" {return LZ;}
")" {return DZ;}
"*" {return PUTA;}
"+" {return PLUS;}
"-" {return MINUS;}
\n {return EOI;}
[0-9]+ {yyval = atoi(yytext);
			return BROJ;}
. {
	fprintf(stderr,"Leksicka greska\n");
	exit(EXIT_FAILURE);
	}

%%
