%{
#include <stdio.h>
#include <stdlib.h>

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
number 		[0-9]
keyword 	array|boolean|begin|break|char|case|const|continue|do|else|end|exit|false|for|fn|if|in|integer|loop|module|print|println|procedure|repeat|return|real|string|record|then|true|type|use|var|util|while
operator 	[+]|[-]|[*]|[/]|[%]|[:][=]|[>][=]|[<][=]|[=]|[~]|[|][|]|[&][&]|[<][>]|[>]|[<]
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

{number}	{tokenInteger(yytext);}

{symbol}	{token(yytext);}

{operator}	{token(yytext);}

{keyword}	{tokenKeyword(yytext);}

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

int main(){
	create(); // create symbol table
   	yylex(); /* start the analysis*/ 
	dump(); // if no '.' in this case
}

int yywrap() 
{ 
	return 1; 
}
