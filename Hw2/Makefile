scanner: lex.yy.o SymbolTable.o
	gcc -o p lex.yy.o SymbolTable.o -ll

lex.yy.o: main.l
	lex main.l
	gcc -c -g lex.yy.c

main.o: SymbolTable.c SymbolTable.h
	gcc -c -g SymbolTable.c

clean:
	rm -f *.o lex.yy.c
