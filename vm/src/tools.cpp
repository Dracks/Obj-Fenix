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


//extern sym_scope_id scope_pointer;
//#undef current_scope
//extern sym_scope_id * current_scope;



void showError(string str){
	//num_errors++;
	fprintf(stderr, "%s\n", str.c_str());
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
	//char* line=(char*) malloc(sizeof(char)*1024);
	//num_errors++;
	//sprintf(line, "Line: %d Character:%d \t-> %s\t%s\t%s\n", num_line, num_column, word.c_str(), token, value);
	//fprintf(outFile,"%s", line);
	//printf("%s", line);
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
