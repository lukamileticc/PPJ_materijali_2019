izvrsni: parser.tab.o lex.yy.o
	g++ -Wall lex.yy.o parser.tab.o -o izvrsni

lex.yy.o: lex.yy.c
	g++ -Wall -c lex.yy.c

parser.tab.o: parser.tab.cpp
	g++ -Wall -c parser.tab.cpp

lex.yy.c: lexer.l  
	flex lexer.l

parser.tab.cpp : parser.ypp
	bison -d -v parser.ypp


PHONY: clean

clean:
	@rm izvrsni *.tab.* *.o *.output *.c
