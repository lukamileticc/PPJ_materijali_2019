PROGRAM = _07_rimski.l

a.out: lex.yy.c
	gcc -Wall lex.yy.c
lex.yy.c: $(PROGRAM)
	flex $(PROGRAM)

