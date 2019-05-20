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
%token SET NEQ LE GE AND OR ID
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
%type <tval> var_decl var_ID con_Var const_glo const_loc array expression fun_invo comma_exp var_com
%type <fval> fun_var

/* precedence */
%left OR
%left AND
%left '~'
%left '<' LE EQ GE '>' NEQ
%left '+' '-'
%left '*' '/'
// %left -(unary)
%nonassoc UMINUS

%%
program:        MODULE var_ID program_decl BEG statement END var_ID {Trace("End Parse");dump();};

program_decl:	
		|fun
		|var_delc_glo
		|var_delc_glo fun;

var_delc_glo:	CONST const_glo  {Trace("const 2 delc+glo");}
		|VAR var_glo {Trace("var 2 delc+glo");}
		|array	{Trace("arr 2 delc+glo"); $1->isglobal = 0;}
		|var_delc_glo var_delc_glo {Trace("Combine Var glo");};

var_delc_loc: 	CONST const_loc  {Trace("const 2 delc+loc");}
		|VAR var_loc {Trace("var 2 delc+loc");}
		|array {Trace("arr 2 delc+loc"); $1->isglobal = 1;}
		|var_delc_loc var_delc_loc {Trace("Combine Var loc");};;

statement:	statement statement {Trace("statement Combine");}
		|simple {Trace("statement simple");}
		|loop {Trace("statement loop");}
		|condition {Trace("statement condition");}
		|proc_invo {Trace("statement proc_invo");}
		| {Trace("Null Statement");};

simple:		var_ID SET expression';'{
			Trace("ID SET exp");

			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->isvar == 1) yyerror("Const can't assign");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0)
				$1->ival = $3->ival;
			else if($1->type == 1)
				$1->dval = $3->dval;
			else if($1->type == 2)
				$1->bval = $3->bval;
			else if($1->type == 3)
				strcpy($1->cval, $3->cval);
		}
		|var_ID'['INT_CON']'SET expression';'{
			Trace("ID[i] SET EXP");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->type != 4) yyerror("Not Array Type");
			if($1->arr1 > $3 || $3 > $1->arr2) yyerror("Array Out Of Range");
			if($1->aval != $6->type) yyerror("Type Diff");
			$1 = ReturnArrItem($1->arr,$3);
			if($1->type == 0)
				$1->ival = $6->ival;
			else if($1->type == 1)
				$1->dval = $6->dval;
			else if($1->type == 2)
				$1->bval = $6->bval;
			else if($1->type == 3)
				strcpy($1->cval, $6->cval);
		}
		|READ var_ID';'	{Trace("READ ID"); if(lookup($2->id)==-1) yyerror("ID No define"); }
		|PRINT expression';' {Trace("PRINT");}
		|PRINTLN expression';' {Trace("PRINTLN");}
		|RETURN';'{
			Trace("RETURN");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			t->type = 6;
			insertReturn(t);
		}
		|RETURN expression';'{
			Trace("RETURN exp");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			printf("%d\n",$2->type);
			t->type = $2->type;
			insertReturn(t);
		};


expression:	var_ID	{
			Trace("ID 2 exp");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			$$ =  (SymbolTable*)malloc(sizeof(SymbolTable));
			copyVar($$,$1);
			$$->next == NULL;
			if($1->type == 5){
				if($1->delcNum != 0) yyerror("Delc variable numuber not correct");
				$$->type = $1->fval->returnType;
				if($$->type == 6) yyerror("Use void type calc");
			}
		}
		|con_Var	{ Trace("con 2 exp"); $$ = $1;}
		|fun_invo	{ 
			Trace("fun 2 exp"); 
			$$ =  (SymbolTable*)malloc(sizeof(SymbolTable));
			copyVar($$,$1);
			$$->next == NULL;
			$$->type = $1->fval->returnType;
		}
		|var_ID'['INT_CON']'{
			Trace("arr 2 exp");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->type != 4) yyerror("Not Array Type");
			if($1->arr1 > $3 || $3 > $1->arr2) yyerror("Array Out Of Range");
			$$ = ReturnArrItem($1->arr,$3);
		}
		|'-'expression %prec UMINUS	{
			Trace("-exp");
			if($2->type>=2) yyerror("Unknown");
			else if($2->type==1) $2->dval = -$2->dval;
			else $2->ival = -$2->ival;
			$$ = $2;
		}
		|expression'+'expression{
			Trace("exp + exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival + $3->ival;
			$$->dval = $1->dval + $3->dval;
		}
		|expression'-'expression{
			Trace("exp - exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival - $3->ival;
			$$->dval = $1->dval - $3->dval;
		}
		|expression'*'expression{
			Trace("exp * exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival * $3->ival;
			$$->dval = $1->dval * $3->dval;
		}
		|expression'/'expression{
			Trace("exp / exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			$$ = tmpVar("tmp",$1->type);
			if($3->type == 0 && $3->ival != 0)
				$$->ival = $1->ival / $3->ival;
			else if($3->type == 1 && $3->dval != 0)
				$$->dval = $1->dval / $3->dval;
			else	yyerror("Divide 0");
		}
		|expression'='expression{
			Trace("exp = exp");
			if($1->isvar == 1) yyerror("Const can't assign");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0 && $1->ival == $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval == $3->dval)
				$$ = tmpConBool(1);
			else if($1->type == 2 && $1->bval == $3->bval)
				$$ = tmpConBool(1);
			else if($1->type == 3 && strcmp($1->cval, $3->cval) == 0)
				$$ = tmpConBool(1);
			else
				$$ = tmpConBool(0);
		}
		|expression'>'expression{
			Trace("EXP > EXP");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0 && $1->ival > $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval > $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression'<'expression{
			Trace("EXP < EXP");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0 && $1->ival < $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval < $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|'~'expression{
			Trace("Not EXP");
			if($2->type !=2) yyerror("Type Error");
			if($2->bval == 0)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression LE expression{
			Trace("EXP <= EXP");
			if($1->type >= 2 || $3->type >= 2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0 && $1->ival <= $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval <= $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression GE expression{
			Trace("EXP > EXP");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Diff");
			if($1->type == 0 && $1->ival >= $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval >= $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression AND expression{
			Trace("AND EXP");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 && $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression OR expression{
			Trace("OR EXP");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 || $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression NEQ expression{
			Trace("!= EXP");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 && $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		};

comma_exp:	expression{
			Trace("1 comma");
			$$ = tmpVar("tmp",-1);
			copyVar($$,$1);
			$$->next = NULL;
		}
		|expression','expression{
			Trace("2 comma");
			$$ = tmpVar("tmp",-1);
			copyVar($$,$1);
			SymbolTable* t = tmpVar("tmp",-1);
			copyVar(t,$3);
			t->next = NULL;
			$$->next = t;
		}
		|comma_exp','expression{
			Trace("more comma");
			SymbolTable* t = tmpVar("tmp",-1);
			copyVar(t,$3);
			t->next = NULL;
			ConnectSymbol($1,t);
			$$ = $1;
		};

proc_invo:	var_ID';'{
			Trace("proc_invo null");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->delcNum != 0) yyerror("Delc variable numuber not correct");
		}
		|var_ID'('comma_exp')'';'{
			Trace("proc_invo var");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->delcNum != SymbolTableLength($3)) yyerror("Delc variable numuber not correct");
			if(CompareType($1->fval->lead,$3)==-1) yyerror("Delc variable type not correct");
		};

fun_invo:	var_ID'('comma_exp')'{
			Trace("fun_invo var");
			if(lookup($1->id)==-1) yyerror("ID No define");
			else $$ = ReturnID($1->id);
			if($$->delcNum != SymbolTableLength($3)) yyerror("Delc variable numuber not correct");
			if(CompareType($$->fval->lead,$3)==-1) yyerror("Delc variable type not correct");
		};
	
fun:		fun fun
		|PROCEDURE var_ID fun_var BEG statement END var_ID ';' {Trace("PROCEDURE");
			if(strcmp($2->id,$7->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc($3);
			if(CompareFuncReturnType($3) == 0) yyerror("Return type error");
			if(lookup($2->id) == -1) insertFun($3,$2->id);
			else yyerror("Func ID repeat");
		}
		|PROCEDURE var_ID fun_var var_delc_loc BEG statement END var_ID ';' {Trace("PROCEDURE");
			if(strcmp($2->id,$8->id) != 0) yyerror("PROCEDURE ID error");
			insertLocalToFunc($3);
			if(CompareFuncReturnType($3) == 0) yyerror("Return type error");
			if(lookup($2->id) == -1) insertFun($3,$2->id);
			else yyerror("Func ID repeat");
		};

fun_var:	{	Trace("Function no return & no var"); 
			$$ = createFun();
			$$->returnType = 6;}
		|':' var_type  {
			Trace("Function no var"); 
			$$ = createFun();
			$$->returnType = $2;
		}
		|'(' var_decl {
			Trace("Function add var"); $$ = createFun(); 
			if(lookup($2->id) == -1) insertFunVar($2);
			else yyerror("ID repeat");
		}
		|fun_var ',' var_decl {
			Trace("more var");
			if(lookup($3->id) == -1) insertFunVar($3);
			else yyerror("ID repeat");
			$$ = $1;
		}
		|fun_var ')' ':' var_type {
			Trace("End fun Var");
			$1->returnType = $4;
			$$ = $1;
		}
		|fun_var ')'{
			Trace("End fun Var & void");
			$1->returnType = 6;
			$$ = $1;
		};

loop:		WHILE '(' expression ')' DO statement END';'{
			Trace("loop");
			if($3->type != 2) yyerror("loop's type error");
		};

condition:	IF '(' expression ')' THEN statement END';'{
			Trace("condition");
			if($3->type != 2) yyerror("condition's type error");
		}
		|IF '(' expression ')' THEN statement ELSE statement END';'{
			Trace("condition");
			if($3->type != 2) yyerror("condition's type error");
		};

array:		var_com ':' ARRAY '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		};

const_glo:	const_glo const_glo
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		}
		|var_ID '=' con_Var ';'{
			Trace("insertConst glo");
			if(lookup($1->id) == -1) insertConst($3,$1->id,0);
			else yyerror("ID repeat");
		};

const_loc:	const_loc const_loc
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,1);
		}
		|var_ID '=' con_Var ';'{
			Trace("insertConst loc");
			if(lookup($1->id) == -1) insertConst($3,$1->id,1);
			else yyerror("ID repeat");

		};

var_glo:	var_glo var_glo
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		}
		|var_com ':' var_type ';'{
			Trace("insertVar glo");
			RedefineType($3,0);
		};

var_loc:	var_loc var_loc
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,1);
		}
		|var_com ':' var_type ';'{
			Trace("insertVar loc");
			RedefineType($3,1);

		};

var_com:	var_ID{
			Trace("var com");
			if(lookup($1->id) == -1) insertVar($1,0);
			else yyerror("ID repeat");
		}
		|var_com ',' var_ID{
			Trace("var com");
			if(lookup($3->id) == -1) insertVar($3,0);
			else yyerror("ID repeat");		
		}
		|var_ID ',' var_ID{
			Trace("var com");
			if(lookup($1->id) == -1) insertVar($1,0);
			else yyerror("ID repeat");
			if(lookup($3->id) == -1) insertVar($3,0);
			else yyerror("ID repeat");
		};

var_decl:	var_ID ':' var_type {	
			Trace("Announce Var");
			$$ = tmpVar($1->id,$3);
		};


var_ID:		ID{ 
			Trace("Make ID"); 
			$$ = tmpVar($1,-1); 
		};

var_type:	INTEGER 	{Trace("int"); 	 $$ = 0;}
		|REAL 		{Trace("real");  $$ = 1;}
		|BOOLEAN 	{Trace("bool");	 $$ = 2;}
		|STRING 	{Trace("string");$$ = 3;}
		|ARRAY		{Trace("array"); $$ = 4;};


con_Var:	INT_CON		{ $$ = tmpConInt($1);}
		|REAL_CON	{ $$ = tmpConReal($1);}
		|BOOL_CON	{ $$ = tmpConBool($1);}	
		|STR_CON	{ $$ = tmpConStr($1);};

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
