#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ISPIS 100

#define PLUS 1
#define PUTA 2
#define LZ 3
#define DZ 4
#define BROJ 5
#define EOI 0

int preduvid;
int yyval;

int E();
int T();
int EP();
int TP();
int F();

void greska(char* errmsg){
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}
int yylex(){
		
	char c = getchar();
	switch(c){
		case '+': return PLUS;
		case '*': return PUTA;
		case '(': return LZ;
		case ')': return DZ;
		case '\n': 
		case EOF: return EOI;
	}
	
	if(isdigit(c)){
		yyval = c - '0';
		while(isdigit(c = getchar()))
		yyval = yyval*10 + c - '0';
		
		ungetc(c,stdin);
		return BROJ;
	}
		
	greska("Leskicka greska");
	return -1;
}
int E(){
	printf("\n\n%d\n\n",preduvid);
	if(preduvid == BROJ || preduvid == LZ){
#ifdef ISPIS 
	printf("E --> T EP\n");
#endif
	
	return T() + EP();
	}
	else
		greska("Ocekivan je broj ili (");
	
	return -1;
}
int T(){
	printf("\n\n%d\n\n",preduvid);
	if(preduvid == LZ || preduvid == BROJ){
#ifdef ISPIS 
	printf("T --> F TP\n");
#endif
	return F() * TP();
	}
	else
		greska("OCekivana ( ili broj");
	
	return -1;
}
int EP(){
	printf("\n\n%d\n\n",preduvid);
	if(preduvid == PLUS){
#ifdef ISPIS 
	printf("EP --> +T EP\n");
#endif	
	
	preduvid = yylex();
	return T() + EP();
	}
	else if(preduvid == DZ || preduvid == EOI){
#ifdef ISPIS 
	printf("EP --> eps\n");
#endif	
	
	return 0;
	}
	else
        greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI");
    return -1;
}
int TP(){
	printf("\n\n%d\n\n",preduvid);
	if(preduvid == PUTA){
#ifdef ISPIS 
	printf("TP --> *F TP\n");
#endif	
	
	preduvid = yylex();
	return F() * TP();
	}
	else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI){
#ifdef ISPIS 
	printf("TP --> eps\n");
#endif
		return 1;
	}
	else
        greska("Sintaksna greska: Neocekivani token");
    return -1;
	
}
int F(){
	printf("\n\n%d\n\n",preduvid);
	if(preduvid == LZ){
		int pom;
#ifdef ISPIS 
	printf("F -->( E )\n");
#endif	
		preduvid = yylex();
		pom = E();
		
		if(preduvid == DZ)
			preduvid = yylex();
		else
			greska("OCekivana je )");
		
		return pom;
	}
	else if(preduvid == BROJ){
#ifdef ISPIS 
	printf("F -->BROJ\n");
#endif		
		preduvid = yylex();
		return yyval;
	}
	else
        greska("Sintaksna greska: Ocekivano je ).");
	
    return -1;
	
}
int main() {
	
	int rezultat;
	preduvid = yylex();
	
	rezultat = E();
	
	if(preduvid != EOI)
		greska("Sintkasna greska");
	
	fprintf(stdout,"Vrednost izraza je: %d\n",rezultat);
	return 0;
}
