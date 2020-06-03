izvrsni: parser.tab.o lex.yy.o date.o
	g++ -Wall parser.tab.o lex.yy.o date.o -o izvrsni

parser.tab.o: parser.tab.cpp
	g++ -Wall -c parser.tab.cpp

lex.yy.o: lex.yy.c
	g++ -Wall -c lex.yy.c

date.o: date.cpp
	g++ -Wall -c date.cpp

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp

PHONY: clean

clean:
	@rm izvrsni *.o *.tab.* *.output *.c
