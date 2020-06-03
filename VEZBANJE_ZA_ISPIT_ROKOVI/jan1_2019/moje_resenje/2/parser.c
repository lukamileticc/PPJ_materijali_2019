#include <stdio.h>
#include <stdlib.h>
#include "tokeni.hpp"
extern int yylex();
void yyerror(char* s);
int preduvid;


void program();
void naredba();
void nizp();
void e();
void ep();
void t();

void program(){
	if(preduvid == IME || preduvid == PRINT){
		naredba();
		nizp();
	}
	else if(preduvid == EOI){
		return;
	}
	else 
		yyerror("GRESKA 1");
		
}
void naredba(){
	if(preduvid == IME){
		preduvid = yylex();
		if(preduvid == DOD){
			preduvid = yylex()
			e();		
		}
		else
			yyerror("GRESKA 2");
	}
	else if(preduvid == PRINT){
		preduvid = yylex();
		if(preduvid == OZ){
			preduvid =yylex();
			if(preduvid == IME)	{
				preduvid = yylex();
				if(preduvid == OZ)
					preduvid = yylex();
			}
		}
	}
	else
		yyerror("GRESKA 3");
}

void nizp(){
	if(preduvid = TZ){
		preduvid = yylex();
		naredba();
		nizp();

	}
	else if(preduvid == TZ || preduvid == EOI)
		return;
	else
		yyerror("greska 4");
}
void e(){
	if(preduvid == BROJ || preduvid == IME){
		t();
		ep();

	}	
	else
		yyerror("GRESKA 5");
}

void t(){
	if(preduvid == BROJ || preduvid == IME)
		return;
	else
		yyerror("greska 6");
}

void ep(){
	if(preduvid == AND){
		t(); 
		ep();
	}
	else if(preduvid == OR)
		t(); 
		ep();
	else if(preduvid == NOT){
		t(); 
		}
	else if(preduvid == TZ)
		return;
	else 
		yyerror("greska() 7");
}
int main() {

	preduvid = yylex();

	program();
	if(preduvid == EOI)
		printf("OK\n");
	else
		printf("NOT OK\n");

	return 0;
}

void yyerror(char* s){
	fprintf(stderr,"%s\n",s);
	exit(EXIT_FAILURE);
}
