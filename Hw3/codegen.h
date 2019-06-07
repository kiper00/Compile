#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"

/* Label Data */
typedef struct Label{
  int count;
  int loop_flag;
  struct Label* next; 
}Label;

/* Init data */
FILE *file;
char* name;
int labelCount = 0;
struct Label* leadL; 
struct Label* endL;

/* enum condition */
typedef enum condition{
  IFLT,
  IFGT,
  IFLE,
  IFGE,
  IFEQ,
  IFNE,
  IAND,
  IOR
}condition;

/* Label opreator */
void LabelInit(){
 	Label* l = (Label*)malloc(sizeof(Label));
	leadL = l;
	endL = l;
}
void LabelPush(Label* l){
	  endL->next = l;
	  endL = l;
}
void LabelPop(){
	  Label* l = leadL;
	  while(l->next != endL)
	    	l = l->next;
	  endL = l;
	  endL->next = NULL;
}

Label* CreateLabel(int n){
	  Label* l = (Label*)malloc(sizeof(Label));
	  l->count = n;
	  l->loop_flag = -1;
	  l->next = NULL;
	  return l;
}
void pushNLabel(int n){
  	for(int i = 0; i < n; i++)
    		LabelPush(CreateLabel(labelCount));
  	labelCount += n;
}
void NLabel(int n){
  endL->count += n;
  labelCount += n;
}
void popLabel(){
  LabelPop();
}
int takeLabel(int n){
  return endL->count + n;
}
int getLabel(){
  labelCount++;
  return labelCount;
}
int getFlag(){
  return endL->loop_flag;
}

/* javaa */
void genProgramStart(char* filename){
    LabelInit();
    name = (char*)malloc(sizeof(char));
    strcpy(name,filename);
    char* IO = (char*)malloc(sizeof(char));
	  strcpy(IO,filename);
	  strcat(IO,".jasm");
  	file = fopen(IO,"w");  	
  	fprintf(file,"class %s\n{\n",filename);
}
void genProgramEnd(){
  	fprintf(file,"}\n");
  	fclose(file);
}

void genBlockEnd(){
    fprintf(file,"\t}\n");
}

void genGlobalVar(){
    if(lead == NULL)  return;
    SymbolTable* t = lead->next;
    while(t != NULL){
        if(t->type == 0)
            fprintf(file,"\tfield static int %s\n",id);
        else if(t->type == 2)
            fprintf(file,"\tfield static boolean %s\n",id);
        t = t->next;
    }
}
// void genGlobalInt(char* id){
//     fprintf(file,"\tfield static int %s\n",id);
// }
// void genGlobalBool(char* id){
//     fprintf(file,"\tfield static boolean %s\n",id);
// }
void genGlobalVarWithVal(char* id, int val){
    fprintf(file,"\tfield static int %s = %d\n",id,val);
}

void genLocalVarWithVal(char* id, int val){
    fprintf(file,"\t\tistore %s\n",id);
}
void genConstStr(char* str){
    fprintf(file,"\t\tldc \"%s\"\n",str);
}
void genConstInt(int val){
    fprintf(file,"\t\tsipush %d",val);
}

void genGetGlobalVar(char* id){
    fprintf(file,"\t\tgetstatic int %s.%s\n",name,id);
}
void genGetLocalVar(int idx){
    fprintf(file,"\t\tiload %d\n",idx);
}
void genSetGlobalVar(char* id){
    fprintf(file,"\t\tputstatic int %s.%s\n",name,id);
}
void genSetLocalVar(int idx){
    fprintf(file,"\t\tistore %d\n",idx);
}

void genOperator(char op){
    switch (op)
    {
      case '*': fprintf(file,"\t\timul\n"); break;
      case '/': fprintf(file,"\t\tidiv\n"); break;
      case '+': fprintf(file,"\t\tiadd\n"); break;
      case '-': fprintf(file,"\t\tisub\n"); break;
      case '~': fprintf(file,"\t\tldc 1\n\t\tixor\n"); break;
      default:  break;
    }
}
void genCondOp(int op){
    fprintf(file,"\t\tisub\n");
    int lb1 = getLabel();
    int lb2 = getLabel();
    switch (op) {
      case IFLT: fprintf(file,"\t\tiflt"); break;
      case IFGT: fprintf(file,"\t\tifgt"); break;
      case IFLE: fprintf(file,"\t\tifle"); break;
      case IFGE: fprintf(file,"\t\tifge"); break;
      case IFEQ: fprintf(file,"\t\tifeq"); break;
      case IFNE: fprintf(file,"\t\tifne"); break;
      case IAND:  fprintf(file,"\t\tiand"); break;
      case IOR:   fprintf(file,"\t\tior");  break;
      default: break;
    }
    fprintf(file," L%d\n",lb1);
    fprintf(file,"\t\ticonst_0\n");
    fprintf(file,"\t\tgoto L%d\n",lb2);
    fprintf(file,"\t\ticonst_1\n");
}

void genMainStart(){
  fprintf(file,"\tmethod public static void main(java.lang.String[])\n");
  fprintf(file,"\tmax_stack 15\n");
  fprintf(file,"\tmax_locals 15\n\t{\n");
}
void genFuncStart(SymbolTable* info){
  fprintf(file,"\tmethod public static ");
  fprintf(file,((info->type == 6)? "void" : "int"));
  fprintf(file," %s(",info->id);
  for (int i = 0; i < info->delcNum; i++) {
    if (i != 0) fprintf(file,", ");
    fprintf(file,"int");
  }
  fprintf(file,")\n");
  fprintf(file,"\tmax_stack 15\n");
  fprintf(file,"\tmax_locals 15\n\t{\n");
}
void genVoidFuncEnd(){
  fprintf(file,"\t\treturn\n\t}\n");
}

void genPrintStart(){
  fprintf(file,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
}
void genPrintStr(){
  fprintf(file,"\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
}
void genPrintInt(){
  fprintf(file,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
}
void genPrintlnStr(){
  fprintf(file,"\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
}
void genPrintlnInt(){
  fprintf(file,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
}

void genIReturn(){
  fprintf(file,"\t\tireturn\n");
}
void genReturn(){
  fprintf(file,"\t\treturn\n");
}

void genCallFunc(SymbolTable* info){
  fprintf(file,"\t\tinvokestatic ");
  fprintf(file,((info->type == 6)? "void" : "int"));
  fprintf(file," %s.%s(",name,info->id);
  for (int i = 0; i < info->delcNum; ++i) {
    if (i != 0) fprintf(file,", ");
    fprintf(file,"int");
  }
  fprintf(file,")\n");
}

void genIfStart(){
  pushNLabel(2);
  fprintf(file,"\t\tifeq L%d\n",takeLabel(0));
}
void genElse(){
  fprintf(file,"\t\tgoto L%d\n",takeLabel(1));
}
void genIfEnd(){
  popLabel();
}
void genIfElseEnd(){
  popLabel();
}

void genWhileStart(){
  pushNLabel(1);
}
void genWhileCond()
{
  NLabel(1);
  fprintf(file,"\t\tifeq L%d\n",takeLabel(3 + getFlag()));
}
void genWhileEnd()
{
  fprintf(file,"\t\tgoto L%d\n",takeLabel(getFlag()));
  popLabel();
}
