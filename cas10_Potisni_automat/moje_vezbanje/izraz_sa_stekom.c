#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define EOI 0
#define PLUS 1
#define PUTA 2
#define LZ 3
#define DZ 4
#define BROJ 5

//ovo stavljamo na stek
#define E 6
#define T 7
#define EP 8
#define TP 9
#define F 10

#define _DEBUG 1

#define MAX 256
void greska(char* errmsg){
	fprintf(stderr,"%s\n",errmsg);
	exit(EXIT_FAILURE);
}

int preduvid;

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
		while(isdigit(c = getchar()));
		ungetc(c,stdin);
		return BROJ;
	}
	
	greska("Leksicka greska");
	return -1;
}

//implementiramo stek
int stek[MAX];
int sp;

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
	
	if(empty()){
		greska("stek je prazan!");
		return -1;
	}
	else{
		return stek[--sp];
	}
}
void push(int x){
	
	if(full()){
		greska("stek je pun");
	}
	else
		stek[sp++] = x;
}
void print_stek(){
	int i = sp - 1;
	for(; i >= 0;i--)
		printf("%d ",stek[sp]);
	printf("\n");
}
int top(){
	
	if(empty()){
		greska("stek je prazan");
		return -1;
	}
	else
		return stek[sp - 1];
}
int match(int x){
	return preduvid == x;
}
void advance(){
	preduvid = yylex();
}
int main() {
	
	advance();
	push(E);
	
	while(!empty()){
		switch(top()){
			case E:	
				if(match(BROJ) || match(LZ)){
#ifdef _DEBUG
					printf("E --> T EP\n");
#endif			
					pop();//skidamo E;
					push(EP);
					push(T);
				}
				else
					greska("greska 1");
				break;
			case EP:
				if(match(PLUS)){
#ifdef _DEBUG
					printf("EP --> + T EP\n");
#endif
					pop();
					push(EP);
					push(T);
					push(PLUS);
				}
				else if(match(LZ) || match(EOI)){
#ifdef _DEBUG
				printf("EP --> eps\n");
#endif
				pop();
				
				}
				else
					greska("greska 2");
				break;
			case T:
				if(match(LZ) || match(BROJ)){
#ifdef _DEBUG
				printf("T --> F TP\n");
#endif					
				pop();
				push(TP);
				push(F);
				}
				else
					greska("greska 3");
				break;
				
			case TP:
				if(match(PUTA)){
#ifdef _DEBUG
				printf("TP --> * F TP\n");
#endif
				pop();
				push(TP);
				push(F);
				push(PUTA);
				}
				else if(match(PLUS) || match(DZ) || match(EOI)){
#ifdef _DEBUG
				printf("TP --> eps\n");
#endif
				pop();
				}
				else {
					greska("greska 4");
				}
				break;
				
			case F:
				if(match(LZ)){
#ifdef _DEBUG
				printf("F -->( E )\n");
#endif
				pop();
				push(DZ);
				push(E);
				push(LZ);
				}
				else if(match(BROJ)){
#ifdef _DEBUG
				printf("F --> BROJ\n");
#endif
				pop();
				push(BROJ);
				}
				else
					greska("greska 5");
				break;
				
			default:
				if(match(top())){
					pop();
					advance();
				}
				else
					greska("Sintaksna greska--zavrsni simbol");
		} ///ZA SWITCH
	} // ZA WHILE
	
	printf("ARITMETICKI IZRAZ JE PREPOZNAT\n");
	
	return 0;
}
