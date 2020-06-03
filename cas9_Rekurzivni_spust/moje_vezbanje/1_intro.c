#include <stdio.h>
#include <stdlib.h>

//ako zelimo da nam se ispisuju izvodjenja
#define ISPIS 1

#define a 1
#define b 2
#define c 3
#define EOI 0 //end of input

void S();
void A();
void B();
void C();


int preduslov;


void greska(const char *errmsg)
{
    fprintf(stderr, "%s\n", errmsg);
    exit(EXIT_FAILURE);
}
int yylex(){
	
	char ch = getchar();
	switch(ch){
		
		case 'a': return a;
		case 'b': return b;
		case 'c': return c;
		
		case '\n':
		case EOF: return EOI;
		
		default: greska("Leksicka greska");
	}
	
	return -1;
}

void S() {
	
	if(preduslov == a){
#ifdef ISPIS
	printf("S --> AB\n");
#endif
	A();
	B();
	}
	else if(preduslov == c){
#ifdef ISPIS
	printf("S --> C\n");
#endif
	C();
	}
	
	else
		greska("Sintkasna: Ocekivaju se tokeni 'a' ili 'b'");
}
void A(){
	
	if(preduslov == a){
#ifdef ISPIS
	printf("A --> a\n");
#endif
	preduslov = yylex();
	return;
	}
	else
		greska("Ocekuje se a");
	
}
void B(){
	
	if(preduslov == b){
#ifdef ISPIS
	printf("B --> b\n");
#endif
	preduslov = yylex();
	return;
	}
	else
		greska("Ocekuje se b");
}
void C(){
	
	if(preduslov == c){
#ifdef ISPIS
	printf("C --> cS\n");
#endif
	
	preduslov = yylex();
	S();
		
	}
	else 
		greska("Ocekuje se c");
}
int main() {
    
	preduslov = yylex();
	
	S();
	
	if(preduslov != EOI)
		greska("Sintkasna greska: Visak karaktera na ulazu");
    
    return 0;
}
