%option noyywrap
%option noinput
%option nounput

%{
#include "tokeni.h"
#include <stdlib.h>
%}

%%

while return WHILE_TOKEN;
if return IF_TOKEN;
begin return BEGIN_TOKEN;
end return END_TOKEN;
do return DO_TOKEN;
then return THEN_TOKEN;

"(" return LZ;
")" return DZ;
":=" return DTJ;
[<>] return ROP;
[0-9]+ return BROJ;
; return TZ;
[a-z]+ return ID;

[\n\t ] {}

. {
	fprintf(stderr,"Leksicka greska,nepoznata leksema %s\n",yytext);
	exit(EXIT_FAILURE);}

%%
