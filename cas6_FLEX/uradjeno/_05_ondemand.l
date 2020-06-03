%option noyywrap

%{
	#define F_CONST 1
	#define I_CONST 2

%}


DIGIT [0-9]

%%

[+\-]?{DIGIT}+ {
					return I_CONST;
				}

[+\-]?{DIGIT}+\.{DIGIT}*([eE][+\-]?{DIGIT}+)? {

					return F_CONST;
				}

.    {}
\n   {}

%%

int main(int argc,char** argv) {

	int token;
	yyin = fopen(argv[1],"r");
	while(token = yylex()){

		switch(token){
			case I_CONST: printf("Pronadjena celobrojna konstanta: %s\n",yytext); 
					break;
			case F_CONST: printf("Pronadjena realna konstanta: %s\n",yytext);
					break;
		}
	}

	return 0;
}
