#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokeni.h"

// #define ISPIS 100
extern int yylex();
int yyval;

int preduvid;
void greska(char* errmsg);

int E();
int EP(int nasledjen);
int T();
int TP(int nasledjen);
int F();

int main() {
	
	preduvid = yylex();
	
	int rezultat = E();
	
	if(preduvid == EOI){
		printf("\n\nRecenica odgovara jeziku zadatim gramatikom\n");
		
		printf("\n Vrednost izraza je: %d\n",rezultat);
	}
	else
		greska("Previse tokena na ulazu");
	
	return 0;
}
void greska(char *errmsg){
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}
int E(){
	if(preduvid == LZ || preduvid == BROJ){
#ifdef ISPIS
	printf("E --> T EP\n");
#endif
	int rezultat = T();
	return EP(rezultat);
	}
	else
		greska("Ocekivana je ( ili broj");
}
int T(){
	if(preduvid == LZ || preduvid == BROJ){
#ifdef ISPIS
	printf("T --> F TP\n");
#endif
	
	int rezultat = F();
	return TP(rezultat);
	}
	else
		greska("Ocekivana je ( ili broj");
}

int EP(int nasledjen){
	
	if(preduvid == PLUS){
#ifdef ISPIS
	printf("EP --> + T EP\n");
#endif		
	preduvid = yylex();
	int rezultat = nasledjen + T();
	printf("+ ");
	return EP(rezultat);
		
	}
	else if(preduvid == MINUS){
#ifdef ISPIS
	printf("EP --> - T EP\n");
#endif	
	preduvid = yylex();
	int rezultat = nasledjen - T();
	printf("- ");
	return EP(rezultat);
		
	}
	else if(preduvid == DZ || preduvid == EOI){
#ifdef ISPIS
	printf("EP --> eps\n");
#endif		
	return nasledjen;
	}
	else
		greska("Ocekuje se plus minus ili ) ili EOI");
}
int TP(int nasledjen){
	
	if(preduvid == PUTA){
		
#ifdef ISPIS
	printf("TP --> * F TP\n");
#endif				
		preduvid = yylex();
		
		int rezultat = nasledjen * F();
		printf("* ");
		return TP(rezultat);
		
	}
	else if(preduvid == PLUS || preduvid == MINUS || preduvid == DZ || preduvid == EOI){
#ifdef ISPIS
	printf("TP --> eps\n");
#endif				
		return nasledjen;
	}
	else
		greska("Ocekivani su neki drugi simboli");
}
int F(){
	
	if(preduvid == LZ){
#ifdef ISPIS
	printf("F --> ( E )\n");
#endif		
		preduvid = yylex();
		int rezultat = E();
		if(preduvid == DZ)
			preduvid = yylex();
		else
			greska("OCekuje se )");
		
		return rezultat;
	}
	else if(preduvid == BROJ){
#ifdef ISPIS
	printf("F --> BROJ\n");
#endif	
		int rezultat = yyval;
		printf("%d ",rezultat);
		preduvid = yylex();
		return rezultat;
	}
	else{
		
		greska("Ocekuje se ( ili broj");
	}
}
