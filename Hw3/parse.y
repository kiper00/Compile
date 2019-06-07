%{
#include "codegen.h"
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
program:        MODULE var_ID {genProgramStart($2->id);} program_decl BEG statement END var_ID {
			if(strcmp($2->id,$8->id) != 0) yyerror("Module ID No Error");
			Trace("End Parse");dump();
			genProgramEnd();
		};

program_decl:	
		|fun {Trace("Program has function delcare");}
		|var_delc_glo{Trace("Program has global variable delcare");}
		|var_delc_glo fun{Trace("Program has global variable & function delcare");};

var_delc_glo:	CONST const_glo  {Trace("Const global delcare");}
		|VAR var_glo {Trace("Var global delcare");}
		|array	{Trace("Array global delcare"); $1->isglobal = 0;}
		|var_delc_glo var_delc_glo {Trace("Combine global delcare");};

var_delc_loc: 	CONST const_loc  {Trace("Const local delcare");}
		|VAR var_loc {Trace("Var local delcare");}
		|array {Trace("Array local delcare"); $1->isglobal = 1;}
		|var_delc_loc var_delc_loc {Trace("Combine local delcare");};;

statement:	statement statement {Trace("statement Combine");}
		|simple {Trace("statement simple");}
		|loop {Trace("statement loop");}
		|condition {Trace("statement condition");}
		|proc_invo {Trace("statement procedure invocation");}
		| {Trace("Null statement");};

simple:		var_ID SET expression';'{
			Trace("ID := exp");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->isvar == 1) yyerror("Const can't assign");
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0) $1->ival = $3->ival;
			else if($1->type == 1) $1->dval = $3->dval;
			else if($1->type == 2) $1->bval = $3->bval;
			else if($1->type == 3) strcpy($1->cval, $3->cval);
		}
		|var_ID'['expression']'SET expression';'{
			Trace("ID[exp] := EXP");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->type != 4) yyerror("Not Array Type");
			else if($3->type != 0) yyerror("index not int");
			if($1->arr1 > $3->ival || $3->ival > $1->arr2) yyerror("Array Out Of Range");
			if($1->aval != $6->type) yyerror("Type Difference");
			$1 = ReturnArrItem($1->arr,$3->ival);
			if($1->type == 0) $1->ival = $6->ival;
			else if($1->type == 1) $1->dval = $6->dval;
			else if($1->type == 2) $1->bval = $6->bval;
			else if($1->type == 3) strcpy($1->cval, $6->cval);
		}
		|READ var_ID';'	{Trace("Read ID"); if(lookup($2->id) == 0) yyerror("ID No define"); }
		|PRINT expression';' {Trace("PRINT");}
		|PRINTLN expression';' {Trace("PRINTLN");}
		|RETURN';'{
			Trace("Return");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			t->type = 6;
			insertReturn(t);
		}
		|RETURN expression';'{
			Trace("Return exp");
			SymbolTable* t = (SymbolTable*)malloc(sizeof(SymbolTable));;
			t = tmpVar("tmp",-1);
			t->isvar = 5;
			t->type = $2->type;
			insertReturn(t);
		};


expression:	var_ID	{
			Trace("ID to exp");
			if(lookup($1->id) == 0) yyerror("ID No define");
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
		|con_Var	{ Trace("con to exp"); $$ = $1;}
		|fun_invo	{ 
			Trace("function invocation to exp"); 
			$$ =  (SymbolTable*)malloc(sizeof(SymbolTable));
			copyVar($$,$1);
			$$->next = NULL;
			$$->type = $1->fval->returnType;
		}
		|var_ID'['expression']'{
			Trace("Array to exp");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->type != 4) yyerror("Not Array Type");
			else if($3->type != 0) yyerror("index not int");
			if($1->arr1 > $3->ival || $3->ival > $1->arr2) yyerror("Array Out Of Range");
			$$ = ReturnArrItem($1->arr,$3->ival);
		}
		|'-'expression %prec UMINUS	{
			Trace("-exp");
			if($2->type>=2) yyerror("Type Error");
			else if($2->type==1) $2->dval = -$2->dval;
			else $2->ival = -$2->ival;
			$$ = $2;
		}
		|expression'+'expression{
			Trace("exp + exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival + $3->ival;
			$$->dval = $1->dval + $3->dval;
		}
		|expression'-'expression{
			Trace("exp - exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival - $3->ival;
			$$->dval = $1->dval - $3->dval;
		}
		|expression'*'expression{
			Trace("exp * exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			$$ = tmpVar("tmp",$1->type);
			$$->ival = $1->ival * $3->ival;
			$$->dval = $1->dval * $3->dval;
		}
		|expression'/'expression{
			Trace("exp / exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
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
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0 && $1->ival == $3->ival) $$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval == $3->dval) $$ = tmpConBool(1);
			else if($1->type == 2 && $1->bval == $3->bval) $$ = tmpConBool(1);
			else if($1->type == 3 && strcmp($1->cval, $3->cval) == 0) $$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression'>'expression{
			Trace("exp > exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0 && $1->ival > $3->ival) $$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval > $3->dval) $$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression'<'expression{
			Trace("exp < exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0 && $1->ival < $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval < $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|'~'expression{
			Trace("~exp");
			if($2->type !=2) yyerror("Type Error");
			if($2->bval == 0)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression LE expression{
			Trace("exp <= exp");
			if($1->type >= 2 || $3->type >= 2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0 && $1->ival <= $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval <= $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression GE expression{
			Trace("exp >= exp");
			if($1->type >=2 || $3->type >=2) yyerror("Type Error");
			if($1->type != $3->type) yyerror("Type Difference");
			if($1->type == 0 && $1->ival >= $3->ival)
				$$ = tmpConBool(1);
			else if($1->type == 1 && $1->dval >= $3->dval)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression AND expression{
			Trace("exp && exp");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 && $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression OR expression{
			Trace("exp || exp");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 || $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		}
		|expression NEQ expression{
			Trace("exp <> exp");
			if($1->type != 2 || $3->type != 2) yyerror("Type Error");
			if($1->bval == 1 && $3->bval == 1)
				$$ = tmpConBool(1);
			else $$ = tmpConBool(0);
		};

comma_exp:	expression{
			Trace("(exp ,) OR (exp)");
			$$ = tmpVar("tmp",-1);
			copyVar($$,$1);
			$$->next = NULL;
		}
		|comma_exp','expression{
			Trace("exp , exp");
			SymbolTable* t = tmpVar("tmp",-1);
			copyVar(t,$3);
			t->next = NULL;
			ConnectSymbol($1,t);
			$$ = $1;
		};

proc_invo:	var_ID';'{
			Trace("procedure invocation");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->delcNum != 0) yyerror("Delc variable numuber not correct");
		}
		|var_ID'('comma_exp')'';'{
			Trace("procedure invocation (comman exp)");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $1 = ReturnID($1->id);
			if($1->delcNum != SymbolTableLength($3)) yyerror("Delc variable numuber not correct");
			if(CompareType($1->fval->lead,$3) == 0) yyerror("Delc variable type not correct");
		};

fun_invo:	var_ID'('comma_exp')'{
			Trace("funciton invocation (comman exp)");
			if(lookup($1->id) == 0) yyerror("ID No define");
			else $$ = ReturnID($1->id);
			if($$->delcNum != SymbolTableLength($3)) yyerror("Delc variable numuber not correct");
			if(CompareType($$->fval->lead,$3) == 0) yyerror("Delc variable type not correct");
		};
	
fun:		fun fun { Trace("Function combine")}
		|PROCEDURE var_ID fun_var BEG statement END var_ID ';' {Trace("Proceduce Delcare");
			if(strcmp($2->id,$7->id) != 0) yyerror("Proceduce ID error");
			insertLocalToFunc($3);
			if(CompareFuncReturnType($3) == 0) yyerror("Return type error");
			if(lookup($2->id) == 0) insertFun($3,$2->id);
			else yyerror("Func ID repeat");
		}
		|PROCEDURE var_ID fun_var var_delc_loc BEG statement END var_ID ';' {Trace("Proceduce Delcare");
			if(strcmp($2->id,$8->id) != 0) yyerror("Proceduce ID error");
			insertLocalToFunc($3);
			if(CompareFuncReturnType($3) == 0) yyerror("Return type error");
			if(lookup($2->id) == 0) insertFun($3,$2->id);
			else yyerror("Function ID repeat");
		};

fun_var:	{	Trace("Function no return & no var"); 
			$$ = createFun();
			$$->returnType = 6;}
		|':' var_type  {
			Trace("Function has return & no delc var"); 
			$$ = createFun();
			$$->returnType = $2;
		}
		|'(' var_decl {
			Trace("Function delc var"); 
			$$ = createFun(); 
			if(lookupLocal($2->id) == 0) insertFunVar($2);
			else yyerror("ID repeat1");
		}
		|fun_var ',' var_decl {
			Trace("Function delc var, delc var");
			if(lookupLocal($3->id) == 0) insertFunVar($3);
			else yyerror("ID repeat2");
			$$ = $1;
		}
		|fun_var ')' ':' var_type {
			Trace("End Function delc var & has return");
			$1->returnType = $4;
			$$ = $1;
		}
		|fun_var ')'{
			Trace("End Function delc var & no return");
			$1->returnType = 6;
			$$ = $1;
		};

loop:		WHILE '(' expression ')' DO statement END';'{
			Trace("Loop");
			if($3->type != 2) yyerror("loop's type error");
		};

condition:	IF '(' expression ')' THEN statement END';'{
			Trace("Condition IF");
			if($3->type != 2) yyerror("condition's type error");
		}
		|IF '(' expression ')' THEN statement ELSE statement END';'{
			Trace("condition IF ELSE");
			if($3->type != 2) yyerror("condition's type error");
		};

array:		var_com ':' ARRAY '[' INT_CON ',' INT_CON ']' OF var_type';'{
			Trace("Array Delc");
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		};

const_glo:	const_glo const_glo {Trace("Const global combine")}
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			Trace("Array Global Delcare");
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		}
		|var_ID '=' con_Var ';'{
			Trace("Const global delcare");
			if(lookup($1->id) == 0) insertConst($3,$1->id,0);
			else yyerror("ID repeat3");
		};

const_loc:	const_loc const_loc {Trace("Const const combine")}
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			Trace("Array Local Delcare");
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,1);
		}
		|var_ID '=' con_Var ';'{
			Trace("Const local delcare");
			if(lookup($1->id) == 0) insertConst($3,$1->id,1);
			else yyerror("ID repeat4");

		};

var_glo:	var_glo var_glo {Trace("Variable global combine")}
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			Trace("Array Global Delcare");
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,0);
		}
		|var_com ':' var_type ';'{
			Trace("Variable global delcare");
			RedefineType($3,0);
		};

var_loc:	var_loc var_loc {Trace("Variable local combine")}
		|var_com ':' var_type '[' INT_CON ',' INT_CON ']' OF var_type';'{
			Trace("Array Local Delcare");
			if($7 <= $5) yyerror("Array Range Error");
			RedefineArray($10,$5,$7,1);
		}
		|var_com ':' var_type ';'{
			Trace("Variable local delcare");
			RedefineType($3,1);

		};

var_com:	var_ID{
			Trace("var commman begin");
			if(lookup($1->id) == 0) insertVar($1,0);
			else yyerror("ID repeat5");
		}
		|var_com ',' var_ID{
			Trace("var commman , var");
			if(lookup($3->id) == 0) insertVar($3,0);
			else yyerror("ID repeat6");		
		};

var_decl:	var_ID ':' var_type {	
			Trace("Variable delc");
			$$ = tmpVar($1->id,$3);
		};


var_ID:		ID{ 
			Trace("ID"); 
			$$ = tmpVar($1,-1); 
		};

var_type:	INTEGER 	{Trace("int"); 	 $$ = 0;}
		|REAL 		{Trace("real");  $$ = 1;}
		|BOOLEAN 	{Trace("bool");	 $$ = 2;}
		|STRING 	{Trace("string");$$ = 3;}
		|ARRAY		{Trace("array"); $$ = 4;};


con_Var:	INT_CON		{Trace("int const"); $$ = tmpConInt($1);}
		|REAL_CON	{Trace("real const"); $$ = tmpConReal($1);}
		|BOOL_CON	{Trace("bool const"); $$ = tmpConBool($1);}	
		|STR_CON	{Trace("string const"); $$ = tmpConStr($1);};

%%

int yyerror(char *s){   
	fprintf(stderr, "%s\n", s); 
	exit(-1);  
	return 0;
}

int main(char *argv, int argc)
{

	yyparse();
}
