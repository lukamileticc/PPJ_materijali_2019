%option noyywrap


%x comment

%{

	int broj_linija = 0;
%}


%%

"/*"    {  BEGIN(comment); }

<comment>[^*\n]* {}

<comment>"*"* {}
<comment>\n { ++broj_linija;} 

<comment>"*"+"/" {  BEGIN(INITIAL);  }


\n  {     ++broj_linija;
		  ECHO;          }

. {}
%%

int main() {

	yylex();
	printf("Broj linija je: %d\n",broj_linija);

	return 0;
}
