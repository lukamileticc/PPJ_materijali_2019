izvrsni: lex.yy.o 3_a.o
	gcc -o izvrsni -Wall lex.yy.o 3_a.o

lex.yy.o: lex.yy.c
	gcc -Wall -c lex.yy.c

3_a.o: 3_a.c
	gcc -Wall -c 3_a.c

lex.yy.c: 3a_lex_analys.l
	flex 3a_lex_analys.l
