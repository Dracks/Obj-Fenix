/*
 *  main.c
 *  Compiladors
 *
 *  Created by dracks on 12/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */
#define file_main 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "main.h"
#include "tools.h"
#include "debug.h"
#include "symtab.h"
#include "SemanticAnalisis.h"
#include "classes/clist.h"
#include "../build/syntactic_parser.h"
#include "../build/flex.yy.h"
#include "generator/OFXRootGenerator.h"

using namespace OFXByteCode;

using namespace SemanticAnalisis;


extern FILE *yyin;
extern void yyparse();

int num_column=0;
int num_line=1;
int num_errors=0;
FILE *outFile;

SyntacticElement* main_object;

char* parsing_file;

FILE* out_syntactic_debug;
FILE* out_semantic_debug;
FILE* out_bytecode_debug;
FILE* out_asm_debug;

int espai_actual;
//int seguent_espai;
clist pila_espais;

clist list_files_compile;

clist list_objects_builded;


void yyerror(char *explanation){
	fprintf(stderr,"In line %d.%d\tError: %s, \n",num_line, num_column,explanation);
}


/*
sym_value_type* newElem(){
	sym_value_type* n=(sym_value_type*) malloc(sizeof(sym_value_type));
	n->params=NULL;
	n->semantic_type=NULL;
	return n;
}
*/

/*int nextEspai(){
	return seguent_espai++;
}*/

int name_space_push(int espai){
	//if (espai<0)
	//	espai=nextEspai();
	//printf("%d.%d Pushing space: %d and changing to %d \n",num_line, num_column, espai_actual, espai);
	int* save=(int*) malloc(sizeof(int));
	*save=espai_actual;
	pila_espais.add(save);
	espai_actual=espai;
	return espai;
}
void name_space_pop(){
	cnode* nod=pila_espais.pop();
	int* load=(int*)nod->getContents();
	espai_actual=*load;
	free(load);
	delete nod;
}
/*
void showError(char* word){
	char* line=(char*) malloc(sizeof(char)*1024);
	sprintf(line, "Line: %d Character:%d \t->LEXICAL ERROR in Word: %s !\n", num_line, num_column, word);
}
 */

void cleanContext(){
	
	//num_column=1;
	//num_line=1;
	num_errors=0;
	espai_actual=0;
	//seguent_espai=0;
	/* int i; */
	//init(&pila_espais);
	name_space_push(0);

	addElement("Object", IDENTIFIER);
	yylval.data->setSyntactic(1);
	yylval.data->setUID(getNextClassID());
	yylval.data->setSpaceName(yylval.data->getUID()+2);
	yylval.data->setNative(true);
	
	addElement("True", CONSTANT_VALUE);
	yylval.data->setSyntactic(6);
	yylval.data->setSemantic(insertToken("Boolean", IDENTIFIER, 0));

	addElement("False", CONSTANT_VALUE);
	yylval.data->setSyntactic(6);
	yylval.data->setSemantic(insertToken("Boolean", IDENTIFIER, 0));//*/



	
	addElement("for",FOR_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("while",WHILE_TOKEN);
	yylval.data->setSyntactic(4);
	//addElement("and",AND_TOKEN);
	//yylval.data->setSyntactic(4);
	addElement("in",IN_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("program",PROGRAM_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("def", DEF_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("private", PRIVATE_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("public", PUBLIC_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("protected", PROTECTED_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("class", CLASS_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("end", END_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("import", IMPORT_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("interface", INTERFACE_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("native", NATIVE_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("package", PACKAGE_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("return", RETURN_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("begin", BEGIN_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("if",IF_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("else",ELSE_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("elif",ELIF_TOKEN);
	yylval.data->setSyntactic(4);
	addElement("inherit",INHERIT_TOKEN);
	yylval.data->setSyntactic(4);
}


int main(int argc, char *argv[])
{	
	out_syntactic_debug=fopen("syntactic_debug.out","w");
	//out_syntactic_debug=stderr;
	/* int file=1; */
	if (argc<3){
		printf("useful %s INPUT [INPUT2 ... ] OUTPUT\n", argv[0]);
	} else{
		int i=0;
		/* We load all files from args to compile */
		for (i=1;i<argc-1;i++){
			list_files_compile.add(argv[i]);
		}
		
		//list_files_compile.add((void*) "BaseLibs/Base.ofx");
		list_files_compile.addFirst((void*) "BaseLibs/Base.ofx");
		
		/* Initialice all vars */
		
		main_object=NULL;
		
		//yyscan_t yyscanner;
		//struct yyguts_t * yyg;
		
		cleanContext();
		cnode* file=list_files_compile.getFirst();
		
		/* Parse all files to the treeCode */
		do {
			//yylex_init(&yyscanner);
			//yyg = (struct yyguts_t*)yyscanner;
			
			num_line=1;num_column=1;
			parsing_file=(char*)file->getContents();
			yyin=fopen(parsing_file,"r");
			if (yyin==NULL){
				fprintf(stderr, "File not found %s\n", parsing_file);
				return -1;
			}
			printf("-- Processing file: %s\n", parsing_file); 
			/* yylex(); */
			//yyout=outFile;
			 yyout= stdout; 
			//yyrestart(yyin);
			yyparse();
			fclose(yyin);	
		} while ((file=file->getNext())!=NULL);
		/* We have all sourcecode Loaded. native interfaces included and at this point, 
		 we need to execute the semantic parser and build the bytecode */
		fclose(out_syntactic_debug);
		if (num_errors==0){
			out_semantic_debug=fopen("semantic_debug.out","w");
			semanticValidation(&list_objects_builded);
			fclose(out_semantic_debug);
		}
		if (num_errors==0){
			string fileName=argv[argc-1];
			size_t dot=fileName.find_last_of(".");
			if (fileName.substr(dot+1).compare("ofb")!=0){
				fileName+=".ofb";
			}
			outFile=fopen(fileName.c_str(), "w");
			out_bytecode_debug=fopen("bytecode_debug.out","w");
			out_asm_debug=fopen("bytecode.asm", "w");
			if ( main_object!=NULL)
				buildByteCode(&list_objects_builded, main_object->getUID(),outFile);
			else {
				buildByteCode(&list_objects_builded, 0,outFile);
			}
			fclose(outFile);
			fclose(out_bytecode_debug);
			fclose(out_asm_debug);
		}
	}
	return 0;
	
}
