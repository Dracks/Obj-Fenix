/*
 *  main.cpp
 *  vm
 *
 *  Created by dracks on 01/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


/**
 * @mainpage Objective Fenix - Virtual Machine
 * @author Jaume Singla Valls
 * @date 2010
 */

#include "stdlib.h"
#include "stdio.h"

#include "ASM_instructions.h"
#include "SDK/Stackable.h"
/*#include "BuiltIn/Shell.h"
#include "BuiltIn/String.h"
#include "BuiltIn/Integer.h"
#include "SDK/SuperClass.h"
#include "SDK/Super.h"
*/
#include "tools/Adapter.h"
#include "tools/Cache.h"

#include <time.h>
#include "tools.h"



using namespace SDK;
using namespace ofxbytecode;
using namespace ofxtools;
//static Stackable* cache[10];

/*Stackable* search_constant(int num){
	//printf("Search constant : %d \n", num);
	/*Stackable* aux=0;
	if (cache[num]==0){
		switch (num) {
			case 1:
				aux= new String("Hola Mon!\n");
				break;
			case 2:
				aux= new Integer(0);
				break;
			case 3:
				aux= new Integer(1);
				break;
			case 4:
				aux= new Integer(1000000);
				break;
				//return new Integer(100);
			default:
				break;
		}
		cache[num]=aux;
	}
	//printf("Search constant : %s \n", cache[num]->getName());
	return cache[num];
//	ASSERT(true);
}

Stackable* search_class(int num){
	switch (num) {
		case 1:
			//return new Shell();
			break;
		default:
			break;
	}
}

ASM_line* getFirstSample(){
	ASM_line* test=(ASM_line*) malloc(sizeof(ASM_line)*30);
	int i=0;
	/*test[i].instruction=LOAD_CLASS;
	test[i].param=1//"Integer";
	i++
	test[i].instruction=LOAD_METHOD;
	test[i].param=0//"Integer";
	i++;
	test[i].instruction=LOAD_CONSTANT;
	test[i].param=5//"5"
	i++;	
	/*test[i].instruction=CALL;
	test[i].param="1";
	i++;*
	int ini_bucle;
	// variable i;
	test[i].instruction=PUSH_TOP;
	test[i].param=1;
	i++;
	// i:=0
	test[i].instruction=LOAD_CONSTANT;
	test[i].param=2;
	i++;
	test[i].instruction=STORE_PRIVATE;
	test[i].param=1;
	i++;
	ini_bucle=i;
	// i:=i+1
	test[i].instruction=LOAD_PRIVATE;
	test[i].param=1;
	i++;
	test[i].instruction=LOAD_METHOD;
	test[i].param=1;
	i++;
	test[i].instruction=LOAD_CONSTANT;
	test[i].param=3;
	i++;
	test[i].instruction=CALL;
	test[i].param=1;//"1";
	i++;
	test[i].instruction=STORE_PRIVATE;
	test[i].param=1;
	i++;
	// i-100=0?
	test[i].instruction=LOAD_PRIVATE;
	test[i].param=1;
	i++;
	test[i].instruction=LOAD_METHOD;
	test[i].param=2;
	i++;
	test[i].instruction=LOAD_CONSTANT;
	test[i].param=4;
	i++;
	test[i].instruction=CALL;
	test[i].param=1;//"1";
	i++;
	test[i].instruction=GOTO_TRUE;
	test[i].param=ini_bucle;//"1";
	i++;
	test[i].instruction=LOAD_CLASS;
	test[i].param=1;//"Shell";
	i++;
	test[i].instruction=LOAD_METHOD;
	test[i].param=1;//"print";
	i++;
	test[i].instruction=LOAD_CONSTANT;
	test[i].param=1;//"5"
	i++;
	test[i].instruction=CALL;
	test[i].param=1;//"1";
	i++;
	test[i].instruction=POP_TOP;
	test[i].param=1;//"1";
	i++;
	test[i].instruction=RET;
	test[i].param=-2;//"";
	return test;
}
/*
void run(Pila* pila, ASM_line* code, int params, int n_line){
	//printf("Test1\n");
	int ini_params=pila->top-params;
	while ( true ){
		ASM_line* line=&(code[n_line]);
		//printf("\t%d:Runing instruction %d %d\n",n_line, line->instruction, line->param);
		n_line++;
		switch (line->instruction) {
			case LOAD_CONSTANT:
				pila->top++;
				pila->pila[pila->top]=search_constant(line->param);
				
				//printf("Load constant: %s\n", pila->pila[pila->top]->getName());
				break;
			case LOAD_PRIVATE:
				pila->top++;
				pila->pila[pila->top]=pila->pila[ini_params+line->param];
								//printf("Load private: %d(%s) -> %d(%s)\n", ini_params+line->param,pila->pila[ini_params+line->param]->getName(), pila->top, pila->pila[pila->top]->getName());
				break;
			case LOAD_CLASS:
				pila->top++;
				pila->pila[pila->top]=search_class(line->param);
				break;
			case LOAD_ATTR:
				pila->pila[pila->top]=pila->pila[pila->top]->getAtr(line->param);
				break;
			case CALL:
				//pila->pila[pila->top]=
				pila->pila[pila->top-line->param]->call(pila, code, line->param);
				/*pila->pila[pila->top-line->param]
				if (pila->pila[pila->top-line->param]->getNative()){
					
				}*
				
				break;
			case LOAD_METHOD:
				//printf("%s\n",pila->pila[pila->top]->getName());
				pila->pila[pila->top]=pila->pila[pila->top]->getMethod(line->param);
				break;
			case STORE_ATTR:
				/** Delicado, necesitamos conocer en que objeto estamos... **
				break;
			case STORE_PRIVATE:
				//printf("Store private: %d -> %d\n", pila->top, ini_params+line->param);
				pila->pila[ini_params+line->param]=pila->pila[pila->top];
				pila->top--;
				break;
			case RET:
				// rewrite the position of the method call to me
				if (line->param>-1)
					pila->pila[ini_params-1]=pila->pila[ini_params+line->param];
				else if (line->param==-1){
					pila->pila[ini_params-1]=pila->pila[pila->top];
				}
				/* Release private objects *
				pila->top=ini_params;
				return;
				break;
			case GOTO_TRUE:
				//printf("Goto_false: %d\n", ((Integer* )pila->pila[pila->top])->getValue());
				if (((Integer* )pila->pila[pila->top])->getValue()!=0){
					n_line=line->param;
				}
				pila->top--;
				break;
			case PUSH_TOP:
				pila->top++;
				break;
			/*case <#constant#>:
				<#statements#>
				break;*
			default:
				break;
		}
	}
}
//*/

typedef struct headerSave{
	int		 ByteCodeVersion;
	int		 uid_programClass;
	long int p_Constants; // Position where found the sections.
	int		 n_Constants;
	long int p_Class;
	int		 n_Class;
	long int p_ByteCode;
	int		 n_ByteCode;
} t_HeaderSave;


ASM_line* loadByteCode(string file, Library* data){
	t_HeaderSave header;
	FILE*	bytecodeFile;
	ASM_line* bytecode;
	int count1, count2;
	bytecodeFile=fopen(file.c_str(), "r");

	Adapter* adaptador=new Adapter();
	
	fread(&header, sizeof(headerSave), 1, bytecodeFile); // A partir d'aqui tenim la capçalera carregada
	printf("Debugging: (%d)\n", header.ByteCodeVersion);
	printf("Constants:	%d despl: %ld\n",header.n_Constants, header.p_Constants);
	printf("Class:		%d despl: %ld\n",header.n_Class, header.p_Class);
	printf("ByteCode:	%d despl: %ld\n",header.n_ByteCode, header.p_ByteCode);
	
	count1=0;
	fseek(bytecodeFile, header.p_Class, SEEK_SET);
	
	while (count1<header.n_Class){
		int cid;
		int fatherUID;
		char native;
		char constructor,isStatic;
		int line;
		int aux,aux2;
		int limit2;
		char* name;
		CacheClass* cache;
		fread(&cid,		sizeof(int),	1, bytecodeFile);
		fread(&fatherUID,	sizeof(int),	1, bytecodeFile);
		fread(&native,	sizeof(char),	1, bytecodeFile);
		fread(&aux,		sizeof(int),	1, bytecodeFile);
		name=(char*) malloc(aux*sizeof(char));
		fread(name,		sizeof(char)*(aux-1),	1,	bytecodeFile);

		if (native){
			cache=new NativeCacheClass(cid,name);
		} else {
			cache=new OfxCacheClass(cid, name, fatherUID);
		}

		free(name);
		
		fread(&aux2, sizeof(int), 1, bytecodeFile);
		count2=0;
		while (count2<aux2){
			int uid;
			fread(&uid,		sizeof(int),	1, bytecodeFile);
			fread(&aux,	sizeof(int),	1, bytecodeFile);
			name=(char*) malloc(sizeof(char)*(aux+1));
			fread(name, sizeof(char), aux, bytecodeFile);
			
			cache->addProperty(uid, name);

			count2++;
		}

		fread(&aux2, sizeof(int), 1, bytecodeFile);
		count2=0;
		while (count2<aux2){
			int uid;
			fread(&uid,		sizeof(int),	1, bytecodeFile);
			fread(&line,	sizeof(int),	1, bytecodeFile);
			fread(&constructor,	sizeof(char),	1, bytecodeFile);
			fread(&isStatic,	sizeof(char),	1, bytecodeFile);
			fread(&aux,	sizeof(int),	1, bytecodeFile);
			name=(char*) malloc(sizeof(char)*(aux+1));
			fread(name, sizeof(char), aux, bytecodeFile);
			if (native){
				((NativeCacheClass*)cache)->addMethod(uid, name);
			} else {
				OfxCacheMethod* method=new OfxCacheMethod(uid,name,line);
				((OfxCacheClass*) cache)->addMethod(method);
				if (constructor)
					method->setConstructor(true);
				if (isStatic)
					method->setIsStatic(true);
			}

			count2++;
		}
		
		count1++;
	}
	
	
	fclose(bytecodeFile);
	return bytecode;
}

int main(int argc,char* args[]){
	clock_t start, finish;
	
	//cache[1]= new String("Hola Mon!\n");
	/*cache[2]= new Integer(0);
	cache[3]= new Integer(1);
	cache[4]= new Integer(1000000);*/
	printf("Objective-Fenix VM\nAuthor:\n\tJaume Singla Valls\nCollaborator:\n\tFernando Arroba\n");
	//printf("%d\n", argc);
	if (argc !=2){
		printf("Usage: %s file.ofb\n", args[0]);
		exit(-1);
	}
	//Library* data=new Library();
	ASM_line* bytecode=loadByteCode(args[1], Library::getLibrary());
	/*Thread cpu(bytecode, data);
	//Pila p;
	//p.pila=(Stackable**) malloc(sizeof(Stackable*)*1024);
	start=clock();
	//run(&p, sample1, 0, 0);
	cpu.run(0);
	finish=clock();
	//printf("Debug:\nStack Quantity: %d\n", p.top);
	printf("Time: %f\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ));*/
	
	return 0;
}