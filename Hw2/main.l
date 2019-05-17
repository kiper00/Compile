%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#define token(t) {LIST; printf("<'%s'>\n",t);}
#define tokenKeyword(t) {LIST; printf("<%s>\n",t);}
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
number 		[0-9]+
integer         ([-+]?{number})
real            ([-+]?{number}\.{number}?([Ee](-+)?{number})?)
operator 	[+]|[-]|[*]|[/]|[%]|[=]|[~]|[>]|[<]
id 		{word}({word}|{number})*
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

{integer}	{tokenInteger(atoi(yytext)); yylval.ival = atoi(yytext); return INT_CON;}

{real}		{tokenString(real,yytext); yylval.dval = atof(yytext); return REAL_CON;}

{symbol}	{token(yytext); return yytext[0];}

{operator}	{token(yytext); return yytext[0];}

 /* two-character token */
":="		{token(':='); return SET; }
"<>"    	{token('<>'); return RAL; }
"<="        	{token('<='); return LE; }
">="        	{token('>='); return GE; }
"&&"        	{token('&&'); return AND; }
"||"        	{token('||'); return OR; }

 /* keyword */
"array"		{tokenKeyword("ARRAY"); return ARRAY;}
"boolean"	{tokenKeyword("BOOLEAN"); return BOOLEAN;}
"begin"		{tokenKeyword("BEGIN"); return BEG;}
"break"		{tokenKeyword("BREAK"); return BREAK;}
"char"		{tokenKeyword("CHAR"); return CHAR;}
"case"		{tokenKeyword("CASE"); return CASE;}
"const"		{tokenKeyword("CONST"); return CONST;}
"continue"	{tokenKeyword("CONTINUE"); return CONTINUE;}
"do"		{tokenKeyword("DO"); return DO;}
"else"		{tokenKeyword("ELSE"); return ELSE;}
"end"		{tokenKeyword("END"); return END;}
"exit"		{tokenKeyword("EXIT"); return EXIT;}
"false"		{tokenKeyword("FALSE"); yylval.bval = 0; return BOOL_CON;}
"for"		{tokenKeyword("FOR"); return FOR;}
"fn"		{tokenKeyword("FN"); return FN;}
"if"		{tokenKeyword("IF"); return IF;}
"in"		{tokenKeyword("IN"); return IN;}
"integer"	{tokenKeyword("INTEGER"); return INTEGER;}
"loop"		{tokenKeyword("LOOP"); return LOOP;}
"module"	{tokenKeyword("MODULE"); return MODULE;}
"print"		{tokenKeyword("PRINT"); return PRINT;}
"println"	{tokenKeyword("PRINTLN"); return PRINTLN;}
"procedure"	{tokenKeyword("PROCEDURE"); return PROCEDURE;}
"repeat"	{tokenKeyword("REPEAT"); return REPEAT;}
"return"	{tokenKeyword("RETURN"); return RETURN;}
"real"		{tokenKeyword("REAL"); return REAL;}
"string"	{tokenKeyword("STRING"); return STRING;}
"record"	{tokenKeyword("RECORD"); return RECORD;}
"then"		{tokenKeyword("THEN"); return THEN;}
"true"		{tokenKeyword("TRUE"); yylval.bval = 1; return BOOL_CON;}
"type"		{tokenKeyword("TYPE"); return TYPE;}
"use"		{tokenKeyword("USE"); return USE;}
"var"		{tokenKeyword("VAR"); return VAR;}
"util"		{tokenKeyword("UTIL"); return UTIL;}
"while"		{tokenKeyword("WHILE"); return WHILE;}
"of"		{LIST; return OF;}

{id}		{
		tokenString(id,yytext);
		yylval.cval = yytext;
		return ID;
		//insert(yytext);
		}

{string}	{
		char* tmp = (char*)malloc(sizeof(char)*(yyleng-2));
		for(int i = 1; i < yyleng - 1;i++)
			tmp[i - 1] = yytext[i];
		tokenString(string,tmp);
		yylval.cval = tmp;
		return STR_CON;
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
		//dump();
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
