#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SymbolTable{
	int 	index;
	char 	id[256];	// ID name
	int 	type;		// ID type
				// type =-1, MODULE
	int 	ival;		// type = 0, INTEGER
	double 	dval;		// type = 1, REAL
	int	bval;		// type = 2, BOOLEAN
	char 	*cval;		// type = 3, STRING
	int	aval;		// type = 4, ARRAY aval = array's type
	struct 	FuncInfo* fval;	// type = 5, function

	int 	isglobal;	// global = 0, local = 1

	struct 	SymbolTable* next;
}SymbolTable;

typedef struct FuncInfo{
	int returnType;		// Return's type = SymbolTable's type
	int TotalVarCount;	// Variable's count
	int var[256];		// Record variable's type
}FuncInfo;

//void create(SymbolTable* lead, SymbolTable* end);
//int lookup(SymbolTable* lead, char* input);
//void insert(SymbolTable* lead, SymbolTable* end, char* input);
//void dump(SymbolTable* lead);

SymbolTable* lead;
SymbolTable* end;

/* Create Block */
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

void insertVar(SymbolTable* table){

	if(lead == NULL)
		create();
	table->index = end->index + 1;	
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

void dump(){
// Dumps all entries of the symbol table. returns index of the entry.
	if(lead != NULL){
	SymbolTable* table = lead;
	table = table->next;
	if(table != NULL){
		printf("\nSymbol Table:\n");
		while(table != NULL){
			if(table->isglobal == 0)
				printf("global\t");
			else
				printf("local\t");

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
			else
				printf("function\t");

			printf("%s\n",table->id);
			table = table->next;
		}
	}
	else
		printf("\nNo Symbol Table.\n");
}
	printf("TEST\n");
}
