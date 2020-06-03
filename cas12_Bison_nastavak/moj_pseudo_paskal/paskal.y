%{

#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1
void yyerror(char* m){
	fprintf(stderr,"%s\n",m);
	exit(EXIT_FAILURE);
}
extern int yylex();
int promenljive[26];
%}

%union {
	int vrednost;
	char ime;
	char niska[256];
}

%token pocetak_token kraj_token ispisi_token dod_token 
%token <vrednost> BROJ
%token <niska> NISKA
%token <ime> id_token
%type <vrednost> e


%left '+'
%left MOD
%left '*'

%%
//gramatika
program: blok '.' {}
		;
blok: pocetak_token nizNaredbi kraj_token {}
		;
nizNaredbi: nizNaredbi ';' naredba {}
		| naredba {}
		;
naredba: ispisi_token '(' NISKA ')' {printf("%s\n",$3);}
		| ispisi_token '(' e ')'	{printf("%d\n",$3);}
		| id_token dod_token e		{promenljive[$1 - 'a'] = $3;} 
		;
e: e '+' e   { $$ = $1 + $3;}
	| e '*' e { $$ = $1 * $3;}
	| e MOD e { $$ = $1 % $3;}
	| '(' e ')' {$$ = $2;}
    | BROJ //Podrazumevano $$ = $1
	| id_token { $$ = promenljive[$1 - 'a'];}
	;
	
%%

int main(){
	
	/*flag za debagovanje! */
	yydebug = 0;
	if(yyparse() == 0)
		printf("Paskal fragment odgovara gramatici!\n");

	return 0;
}
