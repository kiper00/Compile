#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int debug = 1;
typedef struct SymbolTable{
	int 	index;
	char 	id[256];	// ID name
	int 	type;		// ID type
				// type =-1, tmp save data
	int 	ival;		// type = 0, INTEGER
	double 	dval;		// type = 1, REAL
	int	bval;		// type = 2, BOOLEAN
	char 	cval[256];	// type = 3, STRING
	int	aval;		// type = 4, ARRAY aval = array's type
	struct 	FuncInfo* fval;	// type = 5, function

	int	arr1;		// Array num 1
	int	arr2;		// Array num 2


	int 	isglobal;	// global = 0, local = 1
	int 	isvar;		// variable = 0, const = 1, array = 2, func = 3

	struct 	SymbolTable* next;
}SymbolTable;

typedef struct FuncInfo{
	int returnType;		// Return's type = SymbolTable's type
	struct SymbolTable* lead;	// Record variable's name
}FuncInfo;

SymbolTable* lead;
SymbolTable* end;

/* Create Block */

	FuncInfo* createFun(){
		FuncInfo* fun = (FuncInfo*)malloc(sizeof(FuncInfo));
		fun->lead = NULL;
		return fun;
	}

	void create(){
	// Creates a symbol table

		lead = (SymbolTable*)malloc(sizeof(SymbolTable));
		lead->index = -1;
		char *tmp = "";
		strcpy( lead->id, tmp);
		lead->next = NULL;
		end = lead;
	}

	SymbolTable* tmpVar(char* id, int type){
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		strcpy( table->id, id);
		table->type = type;
		table->isvar = 0;
		return table;
	}

	SymbolTable* tmpConInt(int ival){
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 0;
		table->ival = ival;
		return table;
	}

	SymbolTable* tmpConReal(double dval){
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 1;
		table->dval = dval;
		return table;
	}

	SymbolTable* tmpConBool(int bval){
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 2;
		table->bval = bval;
		return table;
	}

	SymbolTable* tmpConStr(char* cval){
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 3;
		strcpy( table->cval, cval);
		return table;
	}

/*Find Table*/


	int lookup(char* input){
	// Returns index of the entry for string s, or nil if s is not found.
		if(lead == NULL)
			return -1;
		SymbolTable* table = lead;
		while(table != NULL){
			if(strcmp(table->id, input) == 0)
				return table->index;
			table = table->next;
		}
		return -1;
	}

/* Insert Block */

void copyVar(SymbolTable* w, SymbolTable* r){
	strcpy(w->id,r->id);
	w->type = r->type;
	w->ival = r->ival;
	w->dval = r->dval;
	w->bval = r->bval;
	strcpy(w->cval,r->cval);
	w->aval = r->aval;
	w->arr1 = r->arr1;
	w->arr2 = r->arr2;
	w->isvar = r->isvar;
	w->next = r->next;
}

void insertLocalToFunc(FuncInfo* fun){
	SymbolTable* table = lead;
	fun->lead = (SymbolTable*)malloc(sizeof(SymbolTable));
	SymbolTable* f = fun->lead;
	if( fun->lead == NULL) printf("TEST\n");
	while(table != NULL){
		if(table->next == NULL){
			end = table;
			break;
		}
		else if(table->next->isglobal == 1){
			copyVar(f,table->next);
			end = table;
			end->next = NULL;
			break;
		}
		else
			table = table->next;
	}
}

void insertFunVar(SymbolTable* table){

	if(lead == NULL)
		create();
	table->index = end->index + 1;	
	table->isglobal = 1;
	table->isvar = 3;
	end->next = table;
	end = table;
}

void insertVar(SymbolTable* table, int isglobal){

	if(lead == NULL)
		create();
	table->index = end->index + 1;	
	table->isglobal = isglobal;
	table->isvar = 0;
	end->next = table;
	end = table;
}

void insertArr(SymbolTable* table){

	if(lead == NULL)
		create();
	table->index = end->index + 1;	
	end->next = table;
	end = table;
}

void insertConst(SymbolTable* table, char* id, int isglobal){

	if(lead == NULL)
		create();
	table->index = end->index + 1;	
	strcpy( table->id, id);
	table->isglobal = isglobal;
	table->isvar = 1;
	end->next = table;
	end = table;
}

void insertFun(FuncInfo* fun, char* id){
	if(lead == NULL)
		create();

	SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
	table->type = 5;
	table->fval = fun;
	table->index = end->index + 1;	
	strcpy( table->id, id);
	table->isglobal = 0;
	table->isvar = 3;
	end->next = table;
	end = table;
}

void insert(char* input){
// Returns index of the entry for strings, ornilifsis not found.
	if(lead == NULL)
		create();
	if(lookup(input) == -1)
	{
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->index = end->index + 1;
		strcpy( table->id, input);
		end->next = table;
		end = table;
	}
}

void dumpFunc(FuncInfo* fun){
	SymbolTable* table = fun->lead;
	if(table == NULL)
		printf("\tNo func var\n");
	else{
		while(table != NULL){
			printf("\t%s\t",table->id);
			if(table->isvar == 0){
				printf("var\t");
				if(table->type == 0)
					printf("integer\t");
				else if(table->type == 1)
					printf("real\t");
				else if(table->type == 2)
					printf("boolean\t");
				else if(table->type == 3)
					printf("string\t");			
				printf("\n");
			}
			else if (table->isvar == 1){
				printf("const\t");
				if(table->type == 0)
					printf("%d\t",table->ival);
				else if(table->type == 1)
					printf("%f\t",table->dval);
				else if(table->type == 2 && table->bval == 1)
					printf("true\t");
				else if(table->type == 2 && table->bval == 0)
					printf("false\t");
				else
					printf("%s\t",table->cval);
				printf("\n");	
			}
			else if (table->isvar == 2){
				printf("array\t");
				if(table->aval == 0)
					printf("integer\t");
				else if(table->aval == 1)
					printf("real\t");
				else if(table->aval == 2)
					printf("boolean\t");
				else if(table->aval == 3)
					printf("string\t");
				printf("range[%d,%d]\n",table->arr1,table->arr2);
			}
			else{
				printf("delc\t");
				if(table->type == 0)
					printf("integer\t");
				else if(table->type == 1)
					printf("real\t");
				else if(table->type == 2)
					printf("boolean\t");
				else if(table->type == 3)
					printf("string\t");			
				else if(table->type == 4)
					printf("array\t");
				printf("\n");
			}		
			table = table->next;
		}
	}
}

void dump(){
// Dumps all entries of the symbol table. returns index of the entry.
	if(lead != NULL){
	SymbolTable* table = lead;
	table = table->next;
	if(table != NULL){
		printf("\nSymbol Table:\n");
		while(table != NULL){
			if(table->isglobal == 0 && debug)
				printf("global\t");
			else if(table->isglobal == 1 && debug)
				printf("local\t");
			printf("%s\t",table->id);
			if(table->isvar == 0){
				printf("var\t");
				if(table->type == 0)
					printf("integer\t");
				else if(table->type == 1)
					printf("real\t");
				else if(table->type == 2)
					printf("boolean\t");
				else if(table->type == 3)
					printf("string\t");			
				printf("\n");
			}
			else if (table->isvar == 1){
				printf("const\t");
				if(table->type == 0)
					printf("%d\t",table->ival);
				else if(table->type == 1)
					printf("%f\t",table->dval);
				else if(table->type == 2 && table->bval == 1)
					printf("true\t");
				else if(table->type == 2 && table->bval == 0)
					printf("false\t");
				else
					printf("%s\t",table->cval);
				printf("\n");	
			}			
			else if (table->isvar == 2){
				printf("array\t");
				if(table->aval == 0)
					printf("integer\t");
				else if(table->aval == 1)
					printf("real\t");
				else if(table->aval == 2)
					printf("boolean\t");
				else if(table->aval == 3)
					printf("string\t");
				printf("range[%d,%d]\n",table->arr1,table->arr2);
			}
			else{
				printf("function\t\n");
				dumpFunc(table->fval);
			}
			table = table->next;
		}
	}
	else
		printf("\nNo Symbol Table.\n");
}
}
