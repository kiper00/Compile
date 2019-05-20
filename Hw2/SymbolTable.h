#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int debug = 0;
typedef struct SymbolTable{
	int 	index;
	char 	id[256];	// ID name
	int 	type;		// ID type
	int 	isglobal;	// global = 0, local = 1
	int 	isvar;		// variable = 0, const = 1, array = 2, function = 3, function's delc = 4, return type tmp save = 5
	struct 	SymbolTable* next;

				// type =-1, tmp save data
	int 	ival;		// type = 0, INTEGER
	double 	dval;		// type = 1, REAL
	int	bval;		// type = 2, BOOLEAN
	char 	cval[256];	// type = 3, STRING

	int	aval;		// type = 4, ARRAY aval = array's type
	int	arr1;		// Array num 1
	int	arr2;		// Array num 2
	struct	SymbolTable* arr; // Array Link

	struct 	FuncInfo* fval;	// type = 5, function link
	int 	delcNum;	// Decl in ()

}SymbolTable;

typedef struct FuncInfo{
	int returnType;		// Return's type = SymbolTable's type, 6 = void
	struct SymbolTable* lead;	// Record variable's name
}FuncInfo;

SymbolTable* lead;
SymbolTable* end;

/* Create Block */

	FuncInfo* createFun(){
	// Create a funcInfo
		FuncInfo* fun = (FuncInfo*)malloc(sizeof(FuncInfo));
		fun->lead = NULL;
		return fun;
	}

	void createArr(SymbolTable* in,int a1, int a2, int type){
	// Create an array
		in->arr = (SymbolTable*)malloc(sizeof(SymbolTable));
		in->arr->type = type;
		in->arr->index = a1;
		a1++;
		SymbolTable* t = in->arr;
		while(a1<=a2){
			SymbolTable* f = (SymbolTable*)malloc(sizeof(SymbolTable));
			f->type = type;
			f->index = a1;
			t->next = f;
			t = t->next;
			a1++;
		}
	}
	void create(){
	// Create a symbol table

		lead = (SymbolTable*)malloc(sizeof(SymbolTable));
		lead->index = -1;
		char *tmp = "";
		strcpy( lead->id, tmp);
		lead->next = NULL;
		end = lead;
	}

	SymbolTable* tmpVar(char* id, int type){
	// Tmp Var (didn't insert table)
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		strcpy( table->id, id);
		table->type = type;
		table->isvar = 0;
		return table;
	}

	SymbolTable* tmpConInt(int ival){
	// Tmp const (didn't insert table)
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 0;
		table->ival = ival;
		return table;
	}

	SymbolTable* tmpConReal(double dval){
	// Tmp const real (didn't insert table)
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 1;
		table->dval = dval;
		return table;
	}

	SymbolTable* tmpConBool(int bval){
	// Tmp const bool (didn't insert table)
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 2;
		table->bval = bval;
		return table;
	}

	SymbolTable* tmpConStr(char* cval){
	// Tmp const str (didn't insert table)
		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 3;
		strcpy( table->cval, cval);
		return table;
	}

/*Find Table*/

	SymbolTable* ReturnArrItem(SymbolTable* arr, int index){
	// Return Array item symbol table
		SymbolTable* t = arr;
		while(t->index != index)
			t = t->next;
		return t;
	}

	SymbolTable* ReturnID(char* input){
	// Return ID symbol table
		SymbolTable* table = lead;
		while(table != NULL){
			if(strcmp(table->id, input) == 0)
				return table;
			table = table->next;
		}
	}

	int CompareFuncReturnType(FuncInfo* fun){
	// Compare return type == function type ? true = 1 : false = 0
		int type = fun->returnType;
		if(fun->lead->next == NULL && fun->lead->isvar == 5){
			if(fun->lead->type == type){
				fun->lead = NULL;
				return 1;
			}
			return 0;
		}
		SymbolTable* t = fun->lead;
		while(t != NULL){
			if(t->next == NULL)
				break;
			if(t->next->isvar == 5){
				if(t->next->type != type) return 0;
				else t->next = t->next->next;
			}
			else t = t->next;
		}
		return 1;
	}

	int FuncDelcNum(SymbolTable* in){
	// Calc how function delcare var
		SymbolTable* t = in;
		int count = 0;
		while(t != NULL){
			if(t->isvar == 4) count++;
			t = t->next;
		}
		return count;
	}
	int SymbolTableLength(SymbolTable* t){
	// Calc symbol table length, use for comma_exp
	// To compare is equal to function delcare var'lebgth or not
		int count = 0;
		while(t != NULL){
			count++;
			t = t->next;
		}
		return count;
	}
	void ConnectSymbol(SymbolTable* in, SymbolTable* con){
	// Connect symbol to another
		SymbolTable* t = in;
		while(t->next != NULL)
			t = t->next;
		t->next = con;
	}
	int CompareType(SymbolTable* ri, SymbolTable* li){
	// Compare 2 different symbol table's type
	// Use for function check
		SymbolTable* r = ri;
		SymbolTable* l = li;

		while(r != NULL && r->isvar == 4 ){
			if(r->type != l->type)	return 0;
			r = r->next;	l = l->next;
		}
		return 1;
	}
	
	int lookup(char* input){
	// Returns index of the entry for string s, or nil if s is not found.
	// Find == 1 ,not == 0;
		if(lead == NULL)
			return 0;
		SymbolTable* table = lead;
		
		while(table != NULL){
			if(strcmp(table->id, input) == 0)
				return 1;
			table = table->next;
		}
		return 0;
	}

/* Insert Block */

	void RedefineType(int type, int isglobal){
	// use for id,id,id:type
		SymbolTable* t = lead;
		t = t->next;
		while(t!=NULL){
			if(t->type == -1){
				t->type = type;
				t->isglobal = isglobal;
			}
			t = t->next;
		}
	}
	void RedefineArray(int aval,int a1, int a2, int isglobal){
	// Use fo id,id:array
		SymbolTable* t = lead;
		t = t->next;
		while(t!=NULL){
			if(t->type == -1){
				t->type = 4;
				t->aval = aval;
				t->arr1 = a1;
				t->arr2 = a2;
				t->isvar = 2;
				t->arr =  (SymbolTable*)malloc(sizeof(SymbolTable));
				t->isglobal = isglobal;
				createArr(t,t->arr1,t->arr2,t->aval);
			}
			t = t->next;
		}
	}

	void copyVar(SymbolTable* w, SymbolTable* r){
	// Copy symbol table
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
	// Insert local (declare before add function) to function symbol table
		SymbolTable* table = lead;
		int needAdd = 0;
		while(table != NULL){
			if(table->isglobal == 1){
				needAdd = 1;
				break;
			}
			table = table->next;
		}
		if(needAdd == 1){
			table = lead;
			fun->lead = (SymbolTable*)malloc(sizeof(SymbolTable));
			SymbolTable* f = fun->lead;
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
	}

	void insertFunVar(SymbolTable* table){
	// Function delcare variable
		if(lead == NULL)
			create();
		table->index = end->index + 1;	
		table->isglobal = 1;
		table->isvar = 4;
		end->next = table;
		end = table;
	}

	void insertVar(SymbolTable* table, int isglobal){
	// Insert var into symbol table
		if(lead == NULL)
			create();
		table->index = end->index + 1;	
		table->isglobal = isglobal;
		table->isvar = 0;
		end->next = table;
		end = table;
	}

	void insertReturn(SymbolTable* table){
		if(lead == NULL)
			create();
		table->index = end->index + 1;	
		table->isglobal = 1;
		table->isvar = 5;
		end->next = table;
		end = table;
	}
	void insertConst(SymbolTable* table, char* id, int isglobal){
	// Insert const into symbol table
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
	// Insert int const into symbol table
		if(lead == NULL)
			create();

		SymbolTable* table = (SymbolTable*)malloc(sizeof(SymbolTable));
		table->type = 5;
		table->fval = fun;
		table->index = end->index + 1;	
		strcpy( table->id, id);
		table->isglobal = 0;
		table->isvar = 3;
		table->delcNum = FuncDelcNum(fun->lead);
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
	// dump function variable
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
						printf("integer\t%d\t",table->ival);
					else if(table->type == 1)
						printf("real\t%f\t",table->dval);
					else if(table->type == 2 && table->bval == 1)
						printf("boolean\ttrue\t");
					else if(table->type == 2 && table->bval == 0)
						printf("boolean\tfalse\t");
					else
						printf("string\t%s\t",table->cval);
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
				else if(table->isvar == 4){
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
						printf("integer\t%d\t",table->ival);
					else if(table->type == 1)
						printf("real\t%f\t",table->dval);
					else if(table->type == 2 && table->bval == 1)
						printf("boolean\ttrue\t");
					else if(table->type == 2 && table->bval == 0)
						printf("boolean\tfalse\t");
					else
						printf("string\t%s\t",table->cval);
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
				else if (table->isvar == 3){
					printf("func\t");
					if(table->fval->returnType == 0)
						printf("integer\n");
					else if(table->fval->returnType == 1)
						printf("real\n");
					else if(table->fval->returnType == 2)
						printf("boolean\n");
					else if(table->fval->returnType == 3)
						printf("string\n");
					else if(table->fval->returnType == 6)
						printf("void\n");
					dumpFunc(table->fval);
				}
				table = table->next;
			}
		}
		else
			printf("\nNo Symbol Table.\n");
	}
