izvrsni: parser.tab.o lex.yy.o formula.o
	g++ -Wall -std=c++11 parser.tab.o lex.yy.o formula.o -o izvrsni

formula.o: formula.cpp formula.hpp
	g++ -Wall -std=c++11 -c formula.cpp

parser.tab.o: parser.tab.cpp
	g++ -Wall -std=c++11 -c parser.tab.cpp

lex.yy.o: lex.yy.c
	g++ -Wall -std=c++11 -c lex.yy.c

lex.yy.c: lexer.l parser.tab.hpp
	flex lexer.l

parser.tab.cpp parser.tab.hpp: parser.ypp
	bison -d -v parser.ypp



PHONY: clean

clean:
	@rm izvrsni *.c *.output *.tab.* *.o
