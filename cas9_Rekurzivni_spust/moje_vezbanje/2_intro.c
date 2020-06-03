#include <stdio.h>
#include <stdlib.h>

#define a 1
#define b 2
#define EOI 3
#define ISPIS 1

void A();
void Ap();
void greska();

int preduslov;

void greska(char* errmsg){
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}
int yylex(){
	
	char c = getchar();
	
	if(c == 'a') return a;
	else if(c == 'b') return b;
	else if(c == EOF || c == '\n')
		return EOI;
	else
		greska("Leksicka greska");
	
	return -1;
}
void A(){
	
	if(preduslov == b){
#ifdef ISPIS
	printf("A --> b Ap\n");
#endif
	preduslov = yylex();
	Ap();
	return;
	}
	else
		greska("Ocekuje se b");
}
void Ap(){
	
	if(preduslov == a){
#ifdef ISPIS
	printf("Ap --> a Ap\n");
#endif	
	preduslov = yylex();
	Ap();
	return;
	}
	else if(preduslov == EOI){
#ifdef ISPIS
	printf("Ap --> eps\n");
#endif	
	return;
	}
	else 
		greska("Ocekuje se ili a ili EOI");
}
int main(){
	
	preduslov = yylex();
	A();
	
	if(preduslov != EOI)
		greska("Visak na ulazu");
	
	return 0;
}
