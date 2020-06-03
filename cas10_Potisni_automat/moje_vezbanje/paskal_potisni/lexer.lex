%option noyywrap
%option noinput
%option nounput

%{

#include "tokeni.h"
extern void greska(char* errmsg);
%}

%%

while return WHILE_TOKEN;
do return DO_TOKEN;
if return IF_TOKEN;
end return END_TOKEN;
begin return BEGIN_TOKEN;
then return THEN_TOKEN;

[a-z]+[A-Za-z0-9_]* return ID;
[0-9]+(\.[0-9]+)? return BROJ;
"(" return LZ;
")" return DZ;
";" return TZ;
":=" return DTJ;
[<>=]=? return ROP;
[\t\n ] {}

. { greska("Leksicak greska!");}

%%
