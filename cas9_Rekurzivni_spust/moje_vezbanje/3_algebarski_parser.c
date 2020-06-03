#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



#define BROJ 1
#define PLUS 2
#define PUTA 3
#define LZ 4
#define DZ 5
#define EOI 0 //end of inuput

#define ISPIS 100
int preduvid; //globalna prom

void e();
void ep();
void t();
void tp();
void f();

void greska(char* s){
	fprintf(stderr,"%s\n",s);
	exit(EXIT_FAILURE);
}
//leskicki analizator
int yylex(){
	
	char ch = getchar();
	switch(ch){
		case '+': return PLUS;
		case '*': return PUTA;
		case '(': return LZ;
		case ')': return DZ;
		case '\n': return EOI;
	}

// ako smo procitali cifru
	if(isdigit(ch)){
		while(isdigit(ch = getchar()));
		
		//vracamo karakter koji nije cifra da se dalje obradjuje
		ungetc(ch,stdin);
		return BROJ;
	}

	greska("Leksicka greska: nepoznata leksema");
	return -1;
}

void e(){

	if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
	printf("e --> t ep \n");
#endif
	t();
	ep();
	}
	else
		greska("Sintaksna greska: Ocekivan je t	token BROJ ili (.");

}

void ep(){

	if(preduvid == PLUS){
#ifndef ISPIS
	printf("ep --> + t ep\n");
#endif
//todo
	preduvid = yylex();
	t();
	ep();
	}
	else if(preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
	printf("ep --> eps\n");
#endif 
	return;

	}
	
	else {
	greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI");
	}
}
void t(){
	
	if(preduvid == LZ || preduvid == BROJ){
#ifndef ISPIS
	printf("t --> f tp\n");
#endif
	f();
	tp();
	}
	else greska("Sintaksna greska: Ocekivano je ( ili broj.");
}

void tp(){
	if(preduvid == PUTA){
#ifndef ISPIS
	printf("tp --> * f tp\n");
#endif
	preduvid= yylex();
	f();
	tp();
	}
	else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
	printf("tp --> eps\n");
#endif
	return;
	}
	else greska("Sintaksna greska: Neocekivani token");
}

void f(){

	if(preduvid == LZ){
#ifndef ISPIS
	printf("f --> (e)\n");
#endif
	preduvid=yylex();
	e();
	if(preduvid == DZ)
		preduvid =yylex();
	else
		greska("Sintaksna greska: Ocekivano je ).");
	}
	 
	else if(preduvid == BROJ){
#ifndef ISPIS
	printf("f --> BROJ\n");
#endif
	preduvid = yylex();
	return;
	}

}
int main() {

	preduvid = yylex();
	
	e();

	if(preduvid != EOI)
		greska("Sintaksna greska: Visak karaktera na ulazu");
	
	return 0;
}	


