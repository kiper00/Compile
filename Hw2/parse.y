%{
#include "SymbolTable.h"
#define Trace(t)     if(debug){printf(t); printf("\n");}


%}

/* yylval */
%union {
	int ival;
	double dval;
	int bval;
	char *cval;
	struct SymbolTable* tval;
	struct 	FuncInfo* fval;
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

/* type */
%type <ival> var_type
%type <cval> ID
%type <tval> var_decl var_ID con_Var const_glo const_loc array
%type <fval> fun_var

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
program:        MODULE var_ID BEG statement END var_ID {Trace("End Parse");dump();}
		|MODULE var_ID program_decl BEG statement END var_ID {Trace("End Parse");dump();};

program_decl:	fun
		|var_delc_glo
		|var_delc_glo fun;

var_delc_glo:	CONST const_glo  {Trace("const 2 delc+glo");}
		|VAR var_glo {Trace("var 2 delc+glo");}
		|array	{Trace("arr 2 delc+glo"); $1->isglobal = 0;}
		|var_delc_glo var_delc_glo;

var_delc_loc: 	CONST const_loc  
		|VAR var_loc
		|array {$1->isglobal = 1;}
		|var_delc_loc var_delc_loc;


statement:	statement statement
		|simple
		|loop
		|condition
		|proc_invo;

simple:		var_ID SET expression';'
		|var_ID'['INT_CON']'SET expression';'
		|READ var_ID';'	
		|PRINT expression';' {Trace("PRINT ID");}
		|PRINTLN expression';' {Trace("PRINTLN");}
		|RETURN';'
		|RETURN expression';';


expression:	var_ID
		|con_Var
		|fun_invo
		|var_ID'['INT_CON']'
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

proc_invo:	var_ID'('')'';'
		|var_ID'('comma_exp')'';';

fun_invo:	var_ID'('')'
		|var_ID'('comma_exp')';
	
fun:		fun fun
		|PROCEDURE var_ID fun_var BEG statement END var_ID ';' {Trace("PROCEDURE");
			if(strcmp($2->id,$7->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc($3);
			if(lookup($2->id) == -1) insertFun($3,$2->id);
			else	yyerror("ID repeat");
			
		}
		|PROCEDURE var_ID fun_var var_delc_loc BEG statement END var_ID ';' {Trace("PROCEDURE");
			if(strcmp($2->id,$8->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc($3);
			if(lookup($2->id) == -1) insertFun($3,$2->id);
			else	yyerror("Func ID repeat");
			
		};

fun_var:	'(' ')' ':' var_type  {
			Trace("Function no var"); 
			$$ = createFun();
			$$->returnType = $4;
		}
		|'(' var_decl {
			Trace("Function add var"); $$ = createFun(); 
			if(lookup($2->id) == -1)
				insertFunVar($2);
			else
				yyerror("ID repeat");
		}
		|fun_var ',' var_decl {
			Trace("more var");
			if(lookup($3->id) == -1)
				insertFunVar($3);
			else
				yyerror("ID repeat");
			$$ = $1;
		}
		|fun_var ')' ':' var_type {
			Trace("End fun Var");
			$1->returnType = $4;
			$$ = $1;
		};

loop:		WHILE '(' expression ')' DO END';'
		|WHILE '(' expression ')' DO statement END';';

condition:	IF '(' expression ')' THEN END
		|IF '(' expression ')' THEN statement END
		|IF '(' expression ')' THEN ELSE END
		|IF '(' expression ')' THEN statement ELSE END
		|IF '(' expression ')' THEN ELSE statement END
		|IF '(' expression ')' THEN statement ELSE statement END;

array:		var_ID ':' ARRAY '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if(lookup($1->id)!= -1) yyerror("ID repeat");
			if($7 <= $5) yyerror("Array Range Erroe");
			$1->type = 4;
			$1->isvar = 2;
			$1->aval = $10;
			$1->arr1 = $5;
			$1->arr2 = $7;
			$$ = $1;
			insertArr($1);
		};

const_glo:	const_glo const_glo
		|var_ID '=' con_Var ';'{
			Trace("insertConst glo");
			if(lookup($1->id) == -1)
				insertConst($3,$1->id,0);
			else
				yyerror("ID repeat");
		};

const_loc:	const_loc const_loc
		|var_ID '=' con_Var ';'{
			Trace("insertConst loc");
			if(lookup($1->id) == -1)
				insertConst($3,$1->id,1);
			else
				yyerror("ID repeat");
		};

var_glo:	var_glo var_glo
		|var_decl ';'{
			Trace("insertVar glo");
			if(lookup($1->id) == -1)
				insertVar($1,0);
			else
				yyerror("ID repeat");
		};

var_loc:	var_loc var_loc
		|var_decl ';'{
			Trace("insertVar loc");
			if(lookup($1->id) == -1)
				insertVar($1,1);
			else
				yyerror("ID repeat");

		};

var_decl:	var_ID ':' var_type {	
			Trace("Announce Var");
			$$ = tmpVar($1->id,$3);
		};


var_ID:		ID{ $$ = tmpVar($1,-1);};

var_type:	INTEGER 	{Trace("int"); 	 $$ = 0;}
		|REAL 		{Trace("real");  $$ = 1;}
		|STRING 	{Trace("string");$$ = 2;}
		|BOOLEAN 	{Trace("bool");	 $$ = 3;};

con_Var:	INT_CON		{ $$ = tmpConInt($1);}
		|REAL_CON	{ $$ = tmpConReal($1);}
		|STR_CON	{ $$ = tmpConStr($1);}
		|BOOL_CON	{ $$ = tmpConBool($1);};	
%%

int yyerror(char *s){   
	fprintf(stderr, "%s\n", s); 
	exit(-1);  
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
