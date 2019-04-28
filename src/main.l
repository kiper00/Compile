%{
#include <stdio.h>
#include <stdlib.h>
//#include "SymbolTable.h"

#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)

int linenum = 0;
char buf[MAX_LINE_LENG];

%}

keyword array|boolean|begin|break|char|case|const|continue|do|else|end|exit|false|for|fn|if|in|integer|loop|module|print|println|procedure|repeat|return|real|string|record|then|true|type|use|var|util|while
operator [+]|[-]|[*]|[/]|[%]|[:][=]|[>][=]|[<][=]|[=]|[~]|[|][|]|[&][&]|[<][>]|[>]|[<]
identfier [A-Za-z]([A-Za-z][0-9])*
symbol [,]|[:]|[.]|[;]|[(]|[)]|[[]|[]]|[{]|[}]

%%

{symbol}	{
			LIST;
			printf("<'%s'>\n",yytext);
		}

{operator}	{
			LIST;
			printf("<'%s'>\n",yytext);
		}

{keyword}	{
			LIST;
			printf("<%s>\n",yytext);
		}

{identfier}	{
			LIST;
			printf("<id: %s>\n",yytext);
		}

\n {
		LIST;
		linenum++;
		printf("%d: %s", linenum, buf);
		buf[0] = '\0';
	}
	
[ \t]* {LIST;}

. 	{
		LIST;
		printf("%d:%s\n", linenum, buf);
		printf("bad character:’%s’\n",yytext);
		exit(-1);
	}


%%

void main(){
	printf("词法分析器输出类型说明:\n");
	printf("1：保留字\n");
	printf("2：运算符\n");
	printf("3：分界符\n");
	printf("4：常  数\n");
	printf("5：标识符\n");
	printf("\n");
	yyin=fopen("example.txt","r"); 
    yylex(); /* start the analysis*/ 
	fclose(yyin);
}

int yywrap() 
{ 
	return 1; 
}