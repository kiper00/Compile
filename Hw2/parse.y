%{
#include <stdio.h>
#include <stdlib.h>
#define Trace(t)     if(debug){printf(t); printf("\n");}
int debug = 1;
%}

/* yylval */
%union {
	int ival;
	double dval;
	int bval;
	char *cval;
	int type;
}

/* token */
%token SET RAL LE GE AND OR ID
/* tokenKeyword */
%token ARRAY BOOLEAN BEG BREAK CHAR CASE CONST CONTINUE DO ELSE END EXIT FALSE FOR FN IF IN INTEGER OF READ
%token LOOP MODULE PRINT PRINTLN PROCEDURE REPEAT RETURN REAL STRING RECORD THEN TRUE TYPE USE VAR UTIL WHILE
%token <ival> INT_CON 
%token <cval> STR_CON 
%token <dval> REAL_CON 
%token <bval> BOOL_CON
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
program:        MODULE ID BEG statement END ID {Trace("End Parse");dump(lead);}
		|MODULE ID program_decl BEG statement END ID {Trace("End Parse");printf("END\n");dump(lead);};

program_decl:	fun
		|var_delc_glo
		|var_delc_glo fun;

var_delc_glo:	CONST const_glo  
		|VAR var_glo
		|array
		|var_delc_glo var_delc_glo;

var_delc_loc: 	CONST const_loc  
		|VAR var_loc
		|array
		|var_delc_loc var_delc_loc;


statement:	statement statement
		|simple
		|loop
		|condition
		|proc_invo;

simple:		ID SET expression';'
		|ID'['INT_CON']'SET expression';'
		|READ ID';'	
		|PRINT expression';' {Trace("PRINT ID");}
		|PRINTLN expression';' {Trace("PRINTLN");}
		|RETURN';'
		|RETURN expression';';


expression:	ID
		|con_Var
		|fun_invo
		|ID'['INT_CON']'
		|'-'expression %prec UMINUS
		|expression'+'expression
		|expression'-'expression
		|expression'*'expression
		|expression'/'expression
		|expression'%'expression
		|expression'='expression
		|expression'>'expression
		|expression'<'expression
		|expression'~'expression
		|expression LE expression
		|expression GE expression
		|expression AND expression
		|expression OR expression
		|expression RAL expression;

comma_exp:	expression','expression
		|comma_exp','expression;

proc_invo:	ID'('')'';'
		|ID'('comma_exp')'';';

fun_invo:	ID'('')'
		|ID'('comma_exp')';
	
fun:		PROCEDURE ID fun_var BEG statement END ID ';' {Trace("PROCEDURE");}
		|PROCEDURE ID fun_var var_delc_loc BEG statement END ID ';' {Trace("PROCEDURE");};

fun_var:	'(' ')' {Trace("NULL var");}
		|'(' var_decl {Trace("1 var");}
		|fun_var ',' var_decl {Trace("more var");}
		|fun_var ')' ':' var_type {Trace("End fun Var");};

loop:		WHILE '(' expression ')' DO END';'
		|WHILE '(' expression ')' DO statement END';';

condition:	IF '(' expression ')' THEN END
		|IF '(' expression ')' THEN statement END
		|IF '(' expression ')' THEN ELSE END
		|IF '(' expression ')' THEN statement ELSE END
		|IF '(' expression ')' THEN ELSE statement END
		|IF '(' expression ')' THEN statement ELSE statement END;

const_glo:	const_glo const_glo
		|ID '=' con_Var ';';

const_loc:	const_loc const_loc
		|ID '=' con_Var ';';

array:		ID ':' ARRAY '[' INT_CON ',' INT_CON ']' OF var_type';';

var_glo:	var_glo var_glo
		|var_decl ';';

var_loc:	var_loc var_loc
		|var_decl ';';

var_decl:	ID ':' var_type {Trace("Announce")};

var_type:	INTEGER {Trace("int")}
		|REAL {Trace("real")}
		|STRING {Trace("string")}
		|BOOLEAN {Trace("bool")};

con_Var:	INT_CON
		|REAL_CON
		|STR_CON
		|BOOL_CON;
%%

int yyerror(char *s){   
	fprintf(stderr, "%s\n", s);   
	return 0;
}

int main(char *argv, int argc)
{

    /* open the source program file */
    //if (argc != 2) {
    //    printf ("Usage: sc filename\n");
    //    exit(1);
    //}
    //yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    //if (yyparse() == 1)                 /* parsing */
    //    yyerror("Parsing error !");     /* syntax error */

	yyparse();
}
