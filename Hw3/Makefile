parser: scanner.o parse.o
	gcc y.tab.c lex.yy.c -ll -ly

scanner.o: main.l
	flex -o lex.yy.c main.l

parse.o: parse.y
	bison -y -d parse.y

clean:
	rm -f *.o lex.yy.c
