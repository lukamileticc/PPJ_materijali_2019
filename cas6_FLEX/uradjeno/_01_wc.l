%option noyywrap

%{

	//globalne promenljive
	int broj_linija = 0;
	int broj_karaktera = 0;

%}

%%

\n {broj_linija++;}
.  {broj_karaktera++;}

%%

int main() {

	yylex();
	
	printf("Ukupan broj karaktera: %d\nBroj redova: %d\n",broj_karaktera,broj_linija);

	return 0;
}
