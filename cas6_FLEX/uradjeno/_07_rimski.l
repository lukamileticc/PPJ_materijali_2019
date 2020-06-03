%option noyywrap

%{
	#include <string.h>
	int vrednost = 0;
%}

hiljade M+
stotine C+|CD|DC*|CM
desetice X+|XL|LX*|XC
jedinice I+|IV|VI*|IX

%%
{hiljade} {vrednost +=1000*yyleng;
			//printf("%d\n\n",vrednost); //yyleng vraca duzinu poklopenjene rece npr MMMM yyleng ce biti 
		  }
{stotine} { if(strcmp(yytext,"CM") == 0)
				vrednost += 900;
    	  	else if(strcmp(yytext,"CD")==0)
				vrednost += 400;
			else{
				if(yytext[0] == 'D'){
					vrednost+=500;
				if(yyleng<=4){ //DCCC
					vrednost += 100 *(yyleng -1);
				}
				else{
					fprintf(stderr,"Neispravan rimski broj %s\n",yytext);
					exit(EXIT_FAILURE);
				 } 
		 	 }
				else{
					if(yyleng <= 3){
						vrednost += yyleng*100;
					}
					else{
						fprintf(stderr,"NEipsravan rimski broj %s\n",yytext);
						exit(EXIT_FAILURE);
					}
				}
			}
}

{desetice}  {  if(strcmp("XL",yytext) == 0)
					vrednost += 40;
			   else if(strcmp("XC",yytext) == 0)
					vrednost += 90;
			   else{

					if(yytext[0] != 'L'){
						
						if(yyleng <=3 ) 
							vrednost +=  yyleng*10;
						else {
							fprintf(stderr,"NEipsavan rimski broj %s\n",yytext);
							exit(EXIT_FAILURE);
						}
					}
					else{
						vrednost += 50;
						if(yyleng <= 4){
							vrednost += (yyleng-1)*10;
						}
						else{
							fprintf(stderr,"Neispravan rimski broj %s\n",yytext);
							exit(EXIT_FAILURE);
						}
					}
				}
}

{jedinice}  { if(strcmp(yytext,"IV") == 0)
					vrednost+= 4;
			  else if(strcmp(yytext,"IX") == 0)
					vrednost+= 9;
			  else{
				 if(yytext[0] == 'V'){
					vrednost += 5;
					if(yyleng <=4)
						vrednost += yyleng-1;
					else{
						fprintf(stderr,"Neipsravan rimski broj: %s\n",yytext);
						exit(EXIT_FAILURE);
					}
				 }
				 else{
					if(yyleng <=3)
						vrednost += yyleng;
					else{
						fprintf(stderr,"Neipsravan rimski broj: %s\n",yytext);
						exit(EXIT_FAILURE);
					}
				 }
			  }
}

.|\n {  if(vrednost !=0){
			fprintf(stdout,"%d\n",vrednost);
			vrednost = 0;
		}
		ECHO;
}
%%
int main(){
	
	yylex();
	
	return 0;
}

