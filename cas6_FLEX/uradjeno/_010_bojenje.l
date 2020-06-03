%option noyywrap
%option noinput
%option nounput

%{
 	#include <stdlib.h>
	void stampaj_karakter(char c);
	void stampaj_nisku(char* niska);
%}

DIGIT [0-9]
ID [a-zA-Z][a-zA-Z0-9_]*
WHITE [ \t\n]

%%

{DIGIT}+ {
	fprintf(yyout,"<span style=\"color:blue;\">%s</span>",yytext);
}

{DIGIT}+\.{DIGIT}* {
	fprintf(yyout,"<span style=\"color:blue;\">%s</span>",yytext);
}

if|else|switch|case|while|for|break|continue|int|double|float|char|short|long|unsigned|void|struct|union|static|extern|typedef|return|register {
	
	fprintf(yyout,"<B>%s</B>",yytext);
}

^{WHITE}*#(.|\\\n)*\n {
	//pretprocesorske direktive
	fprintf(yyout,"<span style= \"color:green; \">");
	stampaj_nisku(yytext);
	fprintf(yyout,"</span");
}

{ID} {
	fprintf(yyout,"<span style = \" color: black;\">%s</span>",yytext);
}

"/*"([^*]|"*"*[^/*])*"*"*"/" {
	//komentari u sivo;
	fprintf(yyout,"<span style=\"color:grey;\">");
	stampaj_nisku(yytext);
	fprintf(yyout,"</span>");
}

\"([^\\\"]|\\.)*\" {
	//stringove u crveno
	fprintf(yyout,"<span style=\"color:red;\">");
	stampaj_nisku(yytext);
	fprintf(yyout,"</span>");
}
'([^\\']|\\.)' {
	//karkatere u ljubicasto
	fprintf(yyout,"<span style=\"color:violet;\">");
	stampaj_nisku(yytext);
	fprintf(yyout,"</span>");
}

.|\n {
	ECHO;
}

%%

void stampaj_karakter(char c){
	if(c == '<')
		fprintf(yyout,"&lt;");
	else if(c=='>')
		fprintf(yyout,"&gt");
	else if(c=='&')
		fprintf(yyout,"&amp");
	else
		fprintf(yyout,"%c",c);
}	
void stampaj_nisku(char* niska){
	int i;
	for(int i = 0; niska[i] != '\0';i++){
		stampaj_karakter(niska[i]);
	}
}
int main(int argc,char* argv[]) {

	if(argc > 1){
		if((yyin = fopen(argv[1],"r")) ==NULL){
			fprintf(stderr,"Neuspesno otvaranje datoteke %s\n",yytext);
			exit(EXIT_FAILURE);
		}
	}
	else
		yyin = stdin;
	if(argc >2) {
		if((yyout = fopen(argv[2],"w")) == NULL){
			fprintf(stderr,"file open failed");
			exit(EXIT_FAILURE);
		}
	}
	else
		yyout = stdout;


	//STAMPAMO ZAGLAVLJE DOKUMENTA
	fprintf(yyout,"<html>\n");
	if(argc >1)
		fprintf(yyout,"<head><title>%s</title></head>\n",argv[1]);
	
	fprintf(yyout,"<body>\n<pre>\n");

	//bojimo tekst
	yylex();
	
	//zavrsvamo html dokument
	fprintf(yyout,"</pre>\n</body>\n</html>");

	fclose(yyin);
	fclose(yyout);
	return 0;
}
