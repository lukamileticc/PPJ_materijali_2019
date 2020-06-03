#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"

int preduvid;
extern int yylex();
extern FILE* yyin;
void greska(char* errmsg) {
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}
#define _DEBUG

void nizNaredbi();
void naredba();
void nizp();
void uslov();
void izraz();

int main(int argc,char** argv) {
	
	if(argc > 1){
		yyin = fopen(argv[1],"r");
		if(yyin == NULL)
			greska("FIle open failed");
	}
	
	preduvid = yylex();
	nizNaredbi();
	
	if(preduvid != EOI)
		greska("Visak tokena na ulazu");
	
	fclose(yyin);
	return 0;
}
void nizNaredbi(){
	
	if(preduvid == WHILE_TOKEN || preduvid == IF_TOKEN || preduvid == ID || preduvid == TZ || preduvid == EOI || preduvid == BEGIN_TOKEN || preduvid == END_TOKEN){
		
#ifdef _DEBUG
		printf("nizNaredbi --> naredba nizp\n");
#endif
		naredba();
		nizp();
	}
	else
		greska("Sintaksna 1");
	
}
void naredba() {
	
	if(preduvid == WHILE_TOKEN){
#ifdef _DEBUG
		printf("naredba--> WHILE uslov DO naredba\n");
#endif

		preduvid = yylex();
		uslov();
		if(preduvid != DO_TOKEN)
			greska("Sintaksna greska 2");
		
		preduvid = yylex();
		naredba();
	}
	else if(preduvid == THEN_TOKEN){
#ifdef _DEBUG
		printf("naredba--> IF uslov THEN naredba\n");
#endif		
		preduvid = yylex();
		uslov();
		if(preduvid != THEN_TOKEN)
			greska("Sintaksna greksa 3");
		
		preduvid = yylex();
		naredba();
	}
	else if(preduvid == ID){
#ifdef _DEBUG
		printf("naredba--> ID DTJ izraz\n");
#endif
		preduvid = yylex();
		if(preduvid != DTJ)
			greska("Sintaksna greska! Ocekivano :=!");	
		preduvid = yylex();	
		izraz();
	}
	else if (preduvid ==BEGIN_TOKEN){
#ifdef _DEBUG
		printf("naredba--> BEGIN niznaredbi END\n");
#endif
		preduvid = yylex();
		nizNaredbi();
		if(preduvid != END_TOKEN)
			greska("Sintaksna greska! Ocekivano END!");
		preduvid =yylex();
	}	
	else if(preduvid == TZ || preduvid == EOI || preduvid == END_TOKEN){
#ifdef _DEBUG
		printf("naredba --> eps\n");
#endif
		return;
	}
	else if (preduvid == IF_TOKEN){
#ifdef _DEBUG
		printf("naredba--> IF uslov THEN naredba\n");
#endif
		preduvid = yylex();
		uslov();
		if(preduvid != THEN_TOKEN)
			greska("Sintaksna greska! Ocekivano THEN!");	
		preduvid = yylex();
		naredba();
	}else{char pom[100];
		sprintf(pom,"Sintaksna greska! Neocekivan token %d!", preduvid);
		greska(pom);
		}
}
void nizp(){
	if(preduvid == TZ){
#ifdef _DEBUG
		printf("nizp --> TZ naredba nizp\n");
#endif	
		preduvid = yylex();
		naredba();
		nizp();	
	}
	else if(preduvid == EOI || preduvid == END_TOKEN){
#ifdef _DEBUG
		printf("nizp--> eps\n");
#endif
		return;
	}else 
		greska("Sintaksna greska! Ocekivano je: TZ ili EOI,ili END!");
}
void uslov(){
	if(preduvid == LZ){
#ifdef _DEBUG
		printf("uslov--> LZ izraz ROP izraz DZ\n");
#endif
		preduvid = yylex();
		izraz();
		if(preduvid != ROP)
			greska("Sintaksna greska! Ocekivano ROP!");
		preduvid = yylex();
		izraz();
		if(preduvid != DZ)
			greska("Sintaksna greska! Ocekivano DZ!");
		preduvid = yylex();
	}
	else 
		greska("Sintaksna greska! Ocekivana je LZ!");
}
void izraz(){
	if(preduvid == ID ){
#ifdef _DEBUG
		printf("izraz--> ID\n");
#endif
		preduvid =yylex();
	}
	else if(preduvid ==BROJ){
#ifdef _DEBUG
		printf("izraz--> BROJ\n");
#endif
		preduvid =yylex();

	}
	else
		greska("Sintaksna greska! Ocekivano je ID ili BROJ!");	
}
