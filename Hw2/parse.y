%{
#define Trace(t)        printf(t)
%}

/* token */
%token SET RAL LE GE AND OR
/* tokenKeyword */
%token ARRAY BOOLEAN BEGIN BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FALSE FOR FN IF IN INTEGER
%token LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TRUE TYPE USE VAR UTIL WHILE

/* precedence */
%left OR
%left AND
%left '~'
%left '<' LE EQ GE '>' RAL
%left '+' '-'
%left '*' '/'
// %left -(unary)
%nonassoc UMINUS

%%
program:        identifier semi
                {
                Trace("Reducing to program\n");
                }
                ;

%%
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}

main()
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}