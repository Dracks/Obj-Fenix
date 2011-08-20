/*
 *  tools.cpp
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "tools.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#include "../build/syntactic_parser.h"

extern char* parsing_file;
extern int	num_line;
extern int espai_actual;

//extern sym_scope_id scope_pointer;
//#undef current_scope
//extern sym_scope_id * current_scope;


int addElement(string lexema, int type){
	sym_value_type element;
	int valor_retorn;
	char * upper=strtoup(lexema);
	//char* lex=(char*) malloc((strlen(lexema)+1)*sizeof(char));
	//sprintf(lex, "%s",lexema);
	int error;
	if((error=sym_lookup(upper, &element, espai_actual)) != SYMTAB_NOT_FOUND)
	{
		//printf("> %s Existeix en %d \n",lexema, espai_actual);
		//free(lexema);
		valor_retorn = element.element->getParser();
		yylval.data = element.element;
	}
	else if (espai_actual>1 && (error=sym_lookup(upper, &element, 0)) != SYMTAB_NOT_FOUND)
	/* Look if the variable espai_actual is in Global context, and if not, look in Global context, else write element in symtab */
	{
		//printf("> %s Existeix en 0 \n",lexema);
		//free(lexema);
		valor_retorn = element.element->getParser();
		yylval.data = element.element;
	} else 
	{
		element.element= new SyntacticElement(lexema, type, num_line, parsing_file);
		if (espai_actual==0){
			error=sym_global_add(upper, &element, espai_actual);
		}else
			error=sym_add(upper, &element, espai_actual);
		//printf("* %s No existeix en %d, creem %p i insertem %d\n",lexema, espai_actual, element.element, error);
		//printf("test %p\n", searchElem(lexema, espai_actual));
		yylval.data = element.element;
		valor_retorn=type;
	}
	//printf("resultat es %s/%s/%s amb %d amb %d\n", lexema, upper, yylval.data->getName(), element.element->getParser(), error); //*/
	return valor_retorn;
	//return IDENTIFIER;
}


SyntacticElement* insertThisToken(SyntacticElement* clase){
	sym_value_type elem;
	elem.element=new SyntacticElement("this", IDENTIFIER, num_line, parsing_file);
	elem.element->setSemantic(clase);
	elem.element->setUID(0);
	elem.element->setSyntactic(5);
	sym_add("THIS",&elem, espai_actual);
	return elem.element;
}

SyntacticElement* insertToken(string lexema, int type, int espai){
	sym_value_type element;
	int valor_retorn;
	char * upper=strtoup(lexema);
	int error;
	if (espai==-1)
		espai=espai_actual;
	//printf("insertToken: %s - %d - %d\n", lexema, type, espai);
	if((error=sym_lookup(upper, &element, espai)) != SYMTAB_NOT_FOUND)
	{
		//printf("<insertToken: %s - %d - %d\n", lexema, type, espai);
		return element.element;
	}
	else 
	{
		element.element= new SyntacticElement(lexema, type, num_line, parsing_file);
		//printf("*insertToken: %s - %d - %d\n", lexema, type, espai);
		sym_add(upper, &element, espai);
		//yylval.data = element.element;
		//valor_retorn=type;
	}
	//printf("resultat es %s/%s/%s amb %d amb %d\n", lexema, upper, yylval.data->getName(), element.element->getParser(), error); //*/
	return element.element;
	//return IDENTIFIER;
}

SyntacticElement* searchElem(string lexema){
	sym_value_type element;
	int valor_retorn;
	char * upper=strtoup(lexema);
	int error;
	if((error=sym_lookup(upper, &element, espai_actual)) != SYMTAB_NOT_FOUND)
	{
		//free(lexema);
		//valor_retorn = element.element->getParser();
		//yylval.data = element.element;
		return element.element;
	}
	else if (espai_actual>1 && (error=sym_lookup(upper, &element, 0)) != SYMTAB_NOT_FOUND)
	/* Look if the variable espai_actual is in Global context, and if not, look in Global context, else write element in symtab */
	{
		//free(lexema);
		//valor_retorn = element.element->getParser();
		//yylval.data = element.element;
		return element.element;
	} 
	//printf("resultat es %s/%s/%s amb %d amb %d\n", lexema, upper, yylval.data->getName(), element.element->getParser(), error); //*/
	return NULL;
}

SyntacticElement* searchElem(string lexema, int espai){
	sym_value_type element;
	int valor_retorn;
	char * upper=strtoup(lexema);
	int error;
	//printf("searchElem: %s, %d\n", lexema, espai);
	if((error=sym_lookup(upper, &element, espai)) != SYMTAB_NOT_FOUND)
	{
		//printf("Algo va malament\n");
		//free(lexema);
		//valor_retorn = element.element->getParser();
		//yylval.data = element.element;
		return element.element;
	}
	else {
		//printf("resultat es %s/%s/%s amb %d amb %d\n", lexema, upper, yylval.data->getName(), element.element->getParser(), error); //*/
		//printf("Pos, no se que li passa!\n");
		return NULL;
	}
}

void showError(string str){
	num_errors++;
	fprintf(stderr, "Error on %s line %d: %s\n", parsing_file, num_line, str.c_str());
}

void showWarning(string str, int line){
	fprintf(stderr, "Warning %d: %s", line, str.c_str());
}

float toNumber(char* cadena){
	int i, n, nova_mida;
	char * float_cad;
	int mida=strlen(cadena);
	
	/*printf("ABANS DE CONVERTIR: %s\n", cadena);*/
	
	nova_mida = 0;
	for (i = 0; i < mida; i++)
	{
		if (cadena[i] != '_')
		{
			nova_mida++;
		}
	}
	
	float_cad = (char *) malloc(sizeof(char) * nova_mida);
	
	n = 0;
	for (i = 0; i < mida; i++)
	{
		if (cadena[i] != '_')
		{
			float_cad[n] = cadena[i];
			n++;
		}
	}
	float_cad[n] = '\0';
	
	/*printf("DESPRES DE CONVERTIR: %s\n", float_cad);*/
	
	return atof(float_cad);
}

void showText(string word, char* token,char* value){
	char* line=(char*) malloc(sizeof(char)*1024);
	num_errors++;
	sprintf(line, "Line: %d Character:%d \t-> %s\t%s\t%s\n", num_line, num_column, word.c_str(), token, value);
	fprintf(outFile,"%s", line);
	printf("%s", line);
}

char* strtoup(string str){
	int length=str.length();
	char* ret=(char*) malloc((length+1)*sizeof(char));
	int i=0;
	for (i=0; i<length; i++){
		ret[i]=toupper(str[i]);
	}
	ret[length]='\0';
	return ret;
}

int stricmp(string str1, string str2){
	//printf("stricmp: %s - %s \n", str1, str2);
	char* STR1=strtoup(str1);
	char* STR2=strtoup(str2);
	//printf("stricmp: %s - %s \n", STR1, STR2);
	int ret=strcmp(STR1, STR2);
	free(STR1);
	free(STR2);
	//printf("And Return %d\n", ret);
	return ret;
}

char* parseStringInput(string str){
	//int size=strlen(str)-1;
	int size=str.length()-1;
	char* neuf=(char*) malloc(size*sizeof(char));
	int i,j=0;
	i=1;
	while (i<size){
		if (str[i]!='\\'){
			neuf[j]=str[i];
		} else {
			i++;
			switch(str[i]){
				case '\\':
					neuf[j]='\\';
					break;
				case 'n':
					neuf[j]='\n';
					break;
				default:
					neuf[j]=str[i];
			}
		}
		i++;j++;
	}
	neuf[i]='\0';
	return neuf;
}

char* strCopy(const char* text){
	int length=strlen(text);
	char * newtext=(char *)malloc(sizeof(char)*length+1);
	newtext[length]=0; 
	strncpy(newtext,text,length);
	//printf("debug: %s (%p) >> %s (%p)\n", text, text, newtext, newtext);
	return newtext;
}
