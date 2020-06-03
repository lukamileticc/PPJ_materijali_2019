izvrsni: parser.tab.o lex.yy.o
	g++ -Wall -o izvrsni parser.tab.o lex.yy.o

parser.tab.o: parser.tab.cpp
	g++ -Wall -c parser.tab.cpp

lex.yy.o: lex.yy.c
	g++ -Wall -c lex.yy.c

lex.yy.c: lexer.l
	flex lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp


PHONY: clean

clean:
	@rm izvrsni *.output *.c *.o *.tab.*
