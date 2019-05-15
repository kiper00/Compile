%{
#include <stdio.h>
#include <stdlib.h>

#define token(t) {LIST; printf("<'%s'>\n",t);}
#define tokenKeyword(t) {LIST; printf("<%s>\n",t); return t;}
#define tokenInteger(t) {LIST; printf("<int:%d>\n",t);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s);}

#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)

int linenum = 0;
char buf[MAX_LINE_LENG];

typedef struct SymbolTable{
	int index;
	char id[MAX_LINE_LENG];
	struct SymbolTable* next;
}SymbolTable;

SymbolTable* lead;	
SymbolTable* end;

%}

word 		[a-zA-Z_]
number 		[-+]?{[0-9]+}
operator 	[+]|[-]|[*]|[/]|[%]|[=]|[~]|[>]|[<]
id 			{word}({word}|{number})*
symbol 		[,]|[:]|[;]|[(]|[)]|[[]|[]]|[{]|[}]
string 		\"[^\"]*\"
comment 	\/\/[^\n]+\n

%x commentState

%%

"(*"		{		
			LIST;
			BEGIN(commentState);
		}

<commentState>"*)"	{
			LIST;
			BEGIN(INITIAL);
		}

<commentState>.	{LIST;}

<commentState>\n	{
			LIST;
			linenum++;
			printf("%d: %s", linenum,buf);
			buf[0] = '\0';
		}

{number}	{tokenInteger(yytext);}

{symbol}	{token(yytext); return yytext[0];}

{operator}	{token(yytext); return yytext[0];}

 /* two-character token */
":="		{ token(:=); return SET; }
"<>"        { token(<>); return RAL; }
"<="        { token(<=); return LE; }
">="        { token(>=); return GE; }
"&&"        { token(&&); return AND; }
"||"        { token(||); return OR; }

 /* keyword */
"array"		{tokenKeyword(ARRAY);}
"boolean"	{tokenKeyword(BOOLEAN);}
"begin"		{tokenKeyword(BEGIN);}
"break"		{tokenKeyword(BREAK);}
"char"		{tokenKeyword(CHAR);}
"case"		{tokenKeyword(CASE);}
"const"		{tokenKeyword(CONST);}
"continue"	{tokenKeyword(CONTINUE);}
"do"		{tokenKeyword(DO);}
"else"		{tokenKeyword(ELSE);}
"end"		{tokenKeyword(END);}
"exit"		{tokenKeyword(EXIT);}
"false"		{tokenKeyword(FALSE);}
"for"		{tokenKeyword(FOR);}
"fn"		{tokenKeyword(FN);}
"if"		{tokenKeyword(IF);}
"in"		{tokenKeyword(IN);}
"integer"	{tokenKeyword(INTEGER);}
"loop"		{tokenKeyword(LOOP);}
"module"	{tokenKeyword(MODULE);}
"print"		{tokenKeyword(PRINT);}
"println"	{tokenKeyword(PRINTLN);}
"procedure"	{tokenKeyword(PROCEDURE);}
"repeat"	{tokenKeyword(REPEAT);}
"return"	{tokenKeyword(RETURN);}
"real"		{tokenKeyword(REAL);}
"string"	{tokenKeyword(STRING);}
"record"	{tokenKeyword(RECORD);}
"then"		{tokenKeyword(THEN);}
"true"		{tokenKeyword(TRUE);}
"type"		{tokenKeyword(TYPE);}
"use"		{tokenKeyword(USE);}
"var"		{tokenKeyword(VAR);}
"util"		{tokenKeyword(UTIL);}
"while"		{tokenKeyword(WHILE);}

{id}		{
		tokenString(id,yytext);
		insert(yytext);
		}

{string}	{
		char* tmp = (char*)malloc(sizeof(char)*(yyleng-2));
		for(int i = 1; i < yyleng - 1;i++)
			tmp[i - 1] = yytext[i];
		tokenString(string,tmp);
		}

{comment}	{
		LIST;
		linenum++;
		printf("%d: %s", linenum, buf);
		buf[0] = '\0';
		}


\n 		{
		LIST;
		linenum++;
		printf("%d: %s", linenum, buf);
		buf[0] = '\0';
		}
	
[ \t]* 		{LIST;}

"."       	{
		token(yytext);
		printf("%d: %s\n", linenum+1, buf);
		dump();
		exit(-1);
		}

%%


void create(){
// Creates a symbol table

	lead = (SymbolTable*)malloc(sizeof(SymbolTable));
	lead->index = -1;
	char *tmp = "";
	strcpy( lead->id, tmp);
	lead->next = NULL;
	end = lead;
}


int lookup(char* input){
// Returns index of the entry for string s, or nil if s is not found.

	SymbolTable* table = lead;
	while(table != NULL){
		if(strcmp(table->id, input) == 0)
			return table->index;
		table = table->next;
	}
	return -1;
}


void insert(char* input){
// Returns index of the entry for strings, ornilifsis not found.

	if(lookup(input) == -1)
	{
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->index = end->index + 1;
		strcpy( table->id, input);
		end->next = table;
		end = table;
	}
}

void dump(){
// Dumps all entries of the symbol table. returns index of the entry.

	SymbolTable* table = lead;
	table = table->next;
	if(table != NULL){
		printf("\nSymbol Table:\n");
		while(table != NULL){
			printf("%s\n",table->id);
			table = table->next;
		}
	}
	else
		printf("\nNo Symbol Table.\n");
}