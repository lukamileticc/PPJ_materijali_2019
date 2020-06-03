%option noyywrap


%{
	#include <stdlib.h>
	#define KLJUCNA_REC 1
    #define ID 2
	#define I_CONST 3	
    #define F_CONST 4
	#define AOP 5
	#define ROP 6
	#define INTERPUNKCIJA 7
	#define DODELA 8
	#define Z 9
	#define NN 10

%}

DIGIT [0-9]
ID [a-z][a-z0-9]*
%%
{DIGIT}+ {
		 return I_CONST;
}

{DIGIT}+\.{DIGIT}* {
		 return F_CONST;
}

if|then|var|begin|end|integer|function {
	     return KLJUCNA_REC;
}
{ID} {
		 return ID;
}

[+*/-] {
		 return AOP;
}

:= {
		return DODELA;
}

[,.:;] {
		 return INTERPUNKCIJA;
}

\(|\) {
		return Z;
}
[<>=]|"<="|">=" {
		return ROP;
}
[ \t\n] {
	//ignorisemo beline
}

. {
		return NN; //nepoznati karakteri
}

%%

int main(int argc,char** argv){

	int token;

	if(argc > 1) {
		yyin = fopen(argv[1],"r");
		if(yyin == NULL)
			yyin = stdin;
	}
	else
		yyin=stdin;
	
	
	//leksicka analizaa
	while(token = yylex()){

		switch(token){
			
			case I_CONST: printf("Ceo broj: %d\n",atoi(yytext)); break;
			case F_CONST: printf("Realan broj: %lf\n",atof(yytext)); break;
			case ID: printf("Identifikator: %s\n",yytext); break;
			case KLJUCNA_REC: printf("KLjucna rec: %s\n",yytext); break;
			case AOP: printf("Aritemticki operator: %s\n",yytext); break;
			case ROP:printf("Relacioni operator: %s\n",yytext); break;
			case INTERPUNKCIJA: printf("Znak intepunkcije: %s\n",yytext); break;
			case DODELA: printf("Operator dodele: %s\n",yytext); break;
			case Z: printf("Zagrada: %s\n",yytext); break;
			case NN: fprintf(stderr,"Nepoznata leksema: %s\n",yytext); 
			exit(EXIT_FAILURE); break;
		}
	}

	fclose(yyin);
	return 0;
}

