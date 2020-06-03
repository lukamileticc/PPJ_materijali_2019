%option noyywrap

%{



%}


%%
      
"{".*?"}" { } //oblik komentara

"(*"([^*]|"*"+[^)])*"*"+")" {}  // drugi oblik komentara u paskalu

. {ECHO;}
%%
//   (*             *)
int main() {
	
	yylex();

	return 0;
}
