//gramtika
/*
S --> program -|

program --> naredba \n nizp  {id,true,false,undef,not,(}
nizp --> \n naredba nizp  {\n}
		| eps    {EOI}

naredba --> izraz {ID,true,false,undef,not,(}
		 

izraz --> id izrazp      {id}
		 | true izrazp  {true}
		 | false izrazp  {false}
		 | undef izrazp   {undef}
		 | not izraz izrazp {not}
		 | ( izraz ) izrazp {(}

izrazp --> I izraz izrazp       {I}
 		  | ILI izraz izrazp    {ILI}
		  | EQV izraz izrazp    {EQV}
		  | IMPL izraz izrazp	{IMPL}
		  | dod izraz           {dod}
		  | eps	               {\n, EOI}
		


*/


#include <stdio.h>
#include <stdlib.h>


extern int yylex();
void yyerror(char* s);
#define MAX 100
int preduvid;

//lekser me mrzi da pisem :)
#define program 100
#define naredba 101
#define nizp 102
#define izraz 103
#define izrazp 104

//implementiramo stek! preko niza
int stek[MAX];
int n = 0;

bool empty(){
	if(n == 0)
		return true;
	else 
		return false;
}
bool full(){
	if(MAX == n)	
		return true;
	return false;
}
void push(int x){
	
	if(full())
		yyerror("Stack owerflow");

	stek[n++] = x;
}
int pop(){
	if(empty())
		yyerror("Stack underflow");
	
	return stek[--n];
}
int top(){

	if(empty())
		yyerror("Stack is empty");
	
	return stek[n-1];
}

void advance(){
	preduvid = yylex();
}

int main() {
	advance();
	push(program);
	while(!empty()){

		switch(top()){

			case program: if(preduvid == ID || PREDUVID == TRUE_TOKEN || preduvid == FALSE_TOKEN || preduvid == UNDEF_TOKEN || preduvid == NOT || preduvid == '('){
				pop();
				push(nizp);
				push(NOVI_RED);
				push(naredba);
			}
						else 
							yyerror("Greska");
			break;
			case nizp: if(preduvid == NOVI_RED){
								pop();
								push(nizp);
								push(naredba);
								push(NOVI_RED);
						}
						else if(preduvid == EOI){
							pop();
						}
						else yyerror("greska()");
			break;
	//itako dalje.....

			default:	
				if(preduvid == top()){		
					pop();
					advance();
				}
				else 
						yyerror("greksa");
		}
	}
	
	printf("Prepoznat aritmeticki izraz");
 return 0;
}
void yyerror(char* s){
	fprintf(stderr,"%s\n",s);
	exit(EXIT_FAILURE);
}
