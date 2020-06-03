%option noyywrap
%option noinput
%option nounput
%{
//vrednost 0 je za EOF ne sme se koristiti
#define F_CONST 1
#define I_CONST 2

%}

DIGIT [0-9]

%%
[+\-]?{DIGIT}+ {
	return I_CONST;
}

[+\-]?{DIGIT}+\.{DIGIT}*([Ee][+\-]?{DIGIT}+)? {
	return F_CONST;
}

. {}
\n {} //da nam se ne bi ispisivalo nista zato je prazno

%%


int main(int argc,char** argv) {

	int token;
	if(argc > 1){
		yyin = fopen(argv[1],"r");
		if(yyin ==NULL){
			yyin = stdin;
		}
	}
	if(argc >2 && (yyout = fopen(argv[2],"w")) != NULL);
	else
		yyout = stdout;

	while(token = yylex()){
		
		switch(token){
			
			case I_CONST: fprintf(yyout,"Pronasli smo celobrojnu konstantu: %s \n",yytext); break;
			case F_CONST: fprintf(yyout,"Pronasli smo realnu konstantu: %s \n",yytext); break;

		}
	}

	fclose(yyin);
	fclose(yyout);
	return 0;
}
