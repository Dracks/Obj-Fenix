/*
 *  main.h
 *  Compiladors
 *
 *  Created by dracks on 12/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */



#define MAXTAGS 1000


#include "../src/symtab.h"


#ifndef file_main
extern int num_column;
extern int num_line;
extern int num_errors;
extern FILE *outFile;
#endif

/** Temes de Cast i aquestes comprovacions **
int comprovaCast(sym_value_type* type, sym_value_type* var);
int comprovaTipusExp(int line, int column, sym_value_type* var1, sym_value_type* var2);
int comprovaVar(sym_value_type* var1,char* tipus);*/



int nextEspai();
int name_space_push(int espai);
void name_space_pop();

//void showError(char* word);
void showText(char* word, char* token,char* value);
void cleanContext();

void yyerror(char *explanation);