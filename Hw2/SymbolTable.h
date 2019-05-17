typedef struct SymbolTable{
	int 	index;
	char 	id[256];	// ID name
	int 	type;		// ID type
				// type =-1, MODULE
	int 	ival;		// type = 0, INTEGER
	double 	dval;		// type = 1, REAL
	int	bval;		// type = 2, BOOLEAN
	char 	*cval;		// type = 3, STRING
				// type = 4, ARRAY
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


void create(SymbolTable* lead, SymbolTable* end){
// Creates a symbol table

	lead = (SymbolTable*)malloc(sizeof(SymbolTable));
	lead->index = -1;
	char *tmp = "";
	strcpy( lead->id, tmp);
	lead->next = NULL;
	end = lead;
}


int lookup(SymbolTable* lead, char* input){
// Returns index of the entry for string s, or nil if s is not found.

	SymbolTable* table = lead;
	while(table != NULL){
		if(strcmp(table->id, input) == 0)
			return table->index;
		table = table->next;
	}
	return -1;
}


void insert(SymbolTable* lead, SymbolTable* end, char* input){
// Returns index of the entry for strings, ornilifsis not found.

	if(lookup(lead, input) == -1)
	{
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->index = end->index + 1;
		strcpy( table->id, input);
		end->next = table;
		end = table;
	}
}

void dump(SymbolTable* lead){
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
