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
  AND,
  OR
}condition;

/* Label opreator */ 
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
  file = fopen("output.jasm","w");
  strcpy(name,filename);
  fprintf("class %s\n{\n",filename);
}
void genProgramEnd(){
  fprintf("}\n");
  fclose(file);
}

void genBlockEnd(){
  fprintf("\t}\n");
}

void genGlobalVar(char* id){
  fprintf("\tfield static int %s\n",id);
}
void genGlobalVarWithVal(char* id, int val){
  fprintf("\tfield static int %s = %d\n",id,val);
}

void genLocalVarWithVal(char* id, int val){
  fprintf("\t\tistore %s\n",id);
}
void genConstStr(char* str){
  fprintf("\t\tldc \"%s\"\n",str);
}
void genConstInt(int val){
  fprintf("\t\tsipush %d",val);
}

void genGetGlobalVar(char* id){
  fprintf("\t\tgetstatic int %s.%s\n",name,id);
}
void genGetLocalVar(int idx){
  fprintf("\t\tiload %d\n",idx);
}
void genSetGlobalVar(char* id){
  fprintf("\t\tputstatic int %s.%s\n",name,id);
}
void genSetLocalVar(int idx){
  fprintf("\t\tistore %s\n",idx);
}

void genOperator(char op){
  switch (op)
  {
    case '*': fprintf("\t\timul\n"); break;
    case '/': fprintf("\t\tidiv\n"); break;
    case '+': fprintf("\t\tiadd\n"); break;
    case '-': fprintf("\t\tisub\n"); break;
    case '~': fprintf("\t\tldc 1\n\t\tixor\n"); break;
    default:  break;
  }

}
void genCondOp(int op)){
  fprintf("\t\tisub\n");
  int lb1 = getLabel();
  int lb2 = getLabel();
  switch (op) {
    case IFLT: fprintf("\t\tiflt"); break;
    case IFGT: fprintf("\t\tifgt"); break;
    case IFLE: fprintf("\t\tifle"); break;
    case IFGE: fprintf("\t\tifge"); break;
    case IFEQ: fprintf("\t\tifeq"); break;
    case IFNE: fprintf("\t\tifne"); break;
    case AND:  fprintf("\t\tiand"); break;
    case OR:   fprintf("\t\tior");  break;
    default: break;
  }
  fprintf(" L%d\n",lb1);
  fprintf("\t\ticonst_0\n");
  fprintf("\t\tgoto L%d\n",lb2);
  fprintf("\t\ticonst_1\n");
}

void genMainStart(){
  fprintf("\tmethod public static void main(java.lang.String[])\n");
  fprintf("\tmax_stack 15\n");
  fprintf("\tmax_locals 15\n\t{\n");
}
void genFuncStart(SymbolTable* info){
  fprintf("\tmethod public static ");
  fprintf(((info.type == 6)? "void" : "int"));
  fprintf(" %s(",info.id);
  for (int i = 0; i < info.delcNum; i++) {
    if (i != 0) fprintf(", ");
    fprintf("int");
  }
  fprintf(")\n");
  fprintf("\tmax_stack 15\n");
  fprintf("\tmax_locals 15\n\t{\n");
}
void genVoidFuncEnd(){
  fprintf("\t\treturn\n\t}\n");
}

void genPrintStart(){
  fprintf("\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
}
void genPrintStr(){
  fprintf("\t\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
}
void genPrintInt(){
  fprintf("\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
}
void genPrintlnStr(){
  fprintf("\t\tinvokevirtual void java.io.PrintStream.println(java.lang.String)\n");
}
void genPrintlnInt(){
  fprintf("\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
}

void genIReturn(){
  fprintf("\t\tireturn\n");
}
void genReturn(){
  fprintf("\t\treturn\n");
}

void genCallFunc(SymbolTable* info){
  fprintf("\t\tinvokestatic ");
  fprintf(((info.type == 6)? "void" : "int"));
  fprintf(" %s.%s(",filename,info.id);
  for (int i = 0; i < info.delcNum; ++i) {
    if (i != 0) fprintf(", ");
    fprintf("int");
  }
  fprintf(")\n");
}

void genIfStart(){
  pushNLabel(2);
  fprintf("\t\tifeq L%d\n",takeLabel(0));
}
void genElse(){
  fprintf("\t\tgoto L%d\n",takeLabel(1));
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
  fprintf("\t\tifeq L%d\n",takeLabel(3 + getFlag()));
}
void genWhileEnd()
{
  fprintf("\t\tgoto L%d\n",takeLabel(getFlag()));
  popLabel();
}