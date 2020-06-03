#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"
// #define _DEBUG 100
#define MAX 256
extern int yylex();
extern FILE* yyin;
int preduvid;

void greska(char* errmsg){
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}
//implementiramo stek!
int stek[MAX];
int sp = 0;//pokazivac na vrh

int empty(){
	if(sp == 0)
		return 1;
	else
		return 0;
}
int full(){
	if(sp == MAX)
		return 1;
	else
		return 0;
}
int pop(){
	if(empty())
		greska("Stek je prazan, ne mozemo skidati sa njega");
	else
		return stek[--sp];
	
	return 1;
}
void push(int x){
	if(full())
		greska("Stek je pun,ne mozemo dodavat!");
	else
		stek[sp++] = x;
}
int top(){
	if(empty()){
		greska("stek underflow!");
		return -1;
	}
	else
		return stek[sp - 1];
}
void advance(){
	preduvid = yylex();
}
int main(int argc,char** argv) {
	
	yyin = fopen(argv[1],"r");
	if(yyin == NULL) greska("file open failed");
	
	advance();
	push(nizNaredbi);
	
	while(!empty()){
		
		switch(top()){
			
			case nizNaredbi: 
				if(preduvid == WHILE_TOKEN || preduvid == IF_TOKEN || preduvid == ID || preduvid == BEGIN_TOKEN || preduvid == EOI || preduvid == TZ || preduvid == END_TOKEN){
#ifdef _DEBUG
					printf("nizNarebi --> naredba nizp");
#endif
					pop();
					push(nizp);
					push(naredba);
				}
				else 
					greska("Sintaksna greska 1");
				break;
			case naredba:
				if(preduvid == ID){
#ifdef _DEBUG
					printf("naredba --> ID DTJ izraz");
#endif					
					pop();
					push(izraz);
					push(DTJ);
					push(ID);
				}
				else if(preduvid == WHILE_TOKEN){
#ifdef _DEBUG
					printf("naredba --> while ( izraz ROP izraz ) do naredba ");
#endif					
					pop();
					push(naredba);
					push(DO_TOKEN);
					push(DZ);
					push(izraz);
					push(ROP);
					push(izraz);
					push(LZ);
					push(WHILE_TOKEN);
				}
				else if(preduvid == IF_TOKEN){
#ifdef _DEBUG
					printf("naredba --> if (izraz ROP izraz) THEN naredba");
#endif					
					pop();
					push(naredba);
					push(THEN_TOKEN);
					push(DZ);
					push(izraz);
					push(ROP);
					push(izraz);
					push(LZ);
					push(IF_TOKEN);
				}
				else if(preduvid == BEGIN_TOKEN){
#ifdef _DEBUG
					printf("naredba --> BEGIN niznaredbi END");
#endif				
					pop();
					push(END_TOKEN);
					push(nizNaredbi);
					push(BEGIN_TOKEN);
				}
				else if(preduvid == EOI || preduvid == END_TOKEN || preduvid == TZ){
#ifdef _DEBUG
					printf("naredba --> eps");
#endif					
					pop();
				}
				else
					greska("Sintaksna greska 2");
				break;
			case nizp:
				if(preduvid == TZ){
#ifdef _DEBUG
					printf("nizp --> TZ nizNarebi");
#endif					
					pop();
					push(nizNaredbi);
					push(TZ);
				}
				else if(preduvid ==EOI || preduvid == END_TOKEN){
#ifdef _DEBUG
					printf("nizp --> eps");
#endif	
					pop();
				}
				else
					greska("Sintaksna greska 3");
				break;
			case izraz:
				if(preduvid == ID){
#ifdef _DEBUG
					printf("izraz --> ID");
#endif					
					pop();
					push(ID);
				}
				else if(preduvid == BROJ){
#ifdef _DEBUG
					printf("izraz --> BROJ");
#endif					
					pop();
					push(BROJ);
				}
				else
					greska("Sintaksna greska 4");
				break;
			default:
				if(top() == preduvid){
					pop();
					advance();
				}
				else
					greska("Sintaksna");
				break;
		} // end za switch
	}//end za while
	
	if(preduvid == EOI)
		printf("ISPRAVAN FRAGMENT KODA U PASKALU\n");
	else
		printf("Visak tokena\n");
	
	fclose(yyin);
	return 0;
}
