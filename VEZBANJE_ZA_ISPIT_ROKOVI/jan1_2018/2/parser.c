//GRAMATIKA SA SKUPOM IZBORA

/*

S -> PROGRAM -|
PROGRAM -> NAREDBA NIZP {ID,PRINT}
NIZP -> ; NAREDBA NIZP {;}
        | eps {EOI}
NAREDBA -> ID DOD IZRAZ {ID}
		 | PRINT ( IZRAZ ) {PRINT}
IZRAZ -> TERM IZRAZP {<}
IZRAZP -> + TERM IZRAZP {+}
		| - TERM IZRAZP {-}
		| * BROJ IZRAZP {*}
		| eps {;}
TERM -> < NABRAJANJE > {<}
NABRAJANJE -> BROJ , NAB {BROJ}
NAB -> , BROJ NAB {,}
	   | eps {>}




*/

#include <stdio.h>
#include <stdlib.h>

int preduvid;
//lex nisam implementirao jer me mrzi :)
extern int yylex();
void yyerror(char* s){
	fprintf(stderr,"%s\n",s);
	exit(EXIT_FAILURE);
}
#define BROJ 1
#define MANJE 2
#define VECE 3
#define TZ 4
#define PLUS 5
#define MINUS 6
#define PUTA 7
#define EOI 0
#define LZ 8
#define DZ 9
#define ID 10
#define PRINT 11
#define DOD 12
#define ZAREZ 13

void program();
void nizp();
void naredba();
void izraz();
void term();
void izrazp();
void nabrajanje();
void nab();

void program() {
	if(preduvid == ID || preduvid == PRINT){
		naredba();
		nizp();
	}
	else 
		yyerror("Greska");
}
void nizp(){
	if(preduvid == TZ){
		preduvid = yylex();
		naredba();
		nizp();
	}	
	else if(preduvid == EOI)
		return;
	else 
		yyerror("Greska");

}
void naredba() {
	if(preduvid == ID){
		preduvid = yylex();
		if(preduvid == DOD){
			preduvid = yylex();
			izraz();
		}
		else
			yyerror("greska");
	}
	else if(preduvid == PRINT){
		preduvid = yylex();
			if(preduvid == LZ){
				preduvid = yylex();
				izraz();
	
				if(preduvid == DZ)
					preduvid = yylex();
				else
					yyerror("greska");
			}
	}	
	else
		yyerror("greska");
}

void izraz(){
	if(preduvid == MANJE){
		term();
		izrazp();
	}
	else
		yyerror("greska");
}	
void izrazp(){

	if(preduvid == PLUS){
		preduvid = yylex();
		term();
		izrazp();
	}
	else if(preduvid == MINUS){
		preduvid = yylex();
		term();
		izrazp();
	}
	
	else if(preduvid == PUTA){
		preduvid = yylex();
		if(preduvid ==BROJ){
			preduvid = yylex();
			izrazp();
		}
	}
	else if(preduvid == TZ)
		return;
	else 
		yyerror("Greksa()");
}
void term(){

	if(preduvid == MANJE){
		preduvid = yylex();
		nabrajanje();
		if(preduvid == VECE)
			preduvid = yylex();

		else
			yyerror("Greksa");
	}
	else
		yyerror("greska");
}

void nabranjanje() {
	if(preduvid == BROJ){
		preduvid = yylex();
		nab();
	}
	else
		yyerror("greska");
}
void nab(){
	if(preduvid == ZAREZ){
		preduvid = yylex();
		if(preduvid == BROJ){
			preduvid = yylex();
			nab();	
		}
	}
	else if(preduvid == VECE)
		return;
	else
		yyerror("Greska");
}	
int main() {

	preduvid = yylex();
	program();
	if(preduvid == EOI)
		printf("Da\n");
	else
		printf("Ne\n");

return 0;
}
