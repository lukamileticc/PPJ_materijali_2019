%option noyywrap

%{
	int broj_otvorenih = 0;
%}

%%

"{" { printf("%s",yytext);
		broj_otvorenih++;}
"}" { 
		ECHO;//isto sto i printf("%s",yytext);
		
		if(broj_otvorenih == 0){
			fprintf(stderr,"Zagrade nisu korektno uparene\n");
			return -1;
        }
		else broj_otvorenih--;
		
	
	}

\n {ECHO;}
.  {ECHO;}

%%


int main() {

	if(yylex() == -1)
		exit(EXIT_FAILURE);
	

	if(broj_otvorenih == 0)
		printf("Zagrade su korektne\n");
	else
		printf("Zagrade su nekorektne\n");


	return 0;
}

