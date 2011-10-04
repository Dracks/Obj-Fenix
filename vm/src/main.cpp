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


#include "BuiltIn/Boolean.h"
#include "BuiltIn/Integer.h"
#include "BuiltIn/String.h"

#include "BuiltIn/Shell.h"


using namespace SDK;
using namespace ofxBI;
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


pair<ASM_line*, int> loadByteCode(string file, Library* data){
	t_HeaderSave header;
	FILE*	bytecodeFile;
	ASM_line* bytecode;
	int count1, count2;
	bytecodeFile=fopen(file.c_str(), "r");
	
	if (!bytecodeFile){
		cout << "ERROR file not found" << endl;
		exit(-1);
	}

	Adapter* adaptador=new Adapter();
	
	fread(&header, sizeof(headerSave), 1, bytecodeFile); // A partir d'aqui tenim la capçalera carregada
	printf("Debugging: (%d)\n", header.ByteCodeVersion);
	printf("Constants:	%d despl: %ld\n",header.n_Constants, header.p_Constants);
	printf("Class:		%d despl: %ld\n",header.n_Class, header.p_Class);
	printf("ByteCode:	%d despl: %ld\n",header.n_ByteCode, header.p_ByteCode);
	
	
	// We read the Classes from bytecode
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
		//name=(char*) malloc(aux*sizeof(char));
		name=new char[aux];
		fread(name,		sizeof(char),	aux,	bytecodeFile);

		if (native){
			cache=new NativeCacheClass(cid,name);
		} else {
			cache=new OfxCacheClass(cid, name, fatherUID);
		}
		//cout << "Parsejant la clase: " << name << endl;
		//free(name);
		delete name;
		
		fread(&aux2, sizeof(int), 1, bytecodeFile);
		//cout << "Propietats: " << aux2 << endl;
		count2=0;
		while (count2<aux2){
			int uid;
			fread(&uid,		sizeof(int),	1, bytecodeFile);
			fread(&aux,	sizeof(int),	1, bytecodeFile);
			//name=(char*) malloc(sizeof(char)*(aux+1));
			name=new char[aux];
			fread(name, sizeof(char), aux, bytecodeFile);
			//cout << "\tPropietat: " << name << endl;
			cache->addProperty(uid, name);
			
			delete name;
			//free(name);

			count2++;
		}

		fread(&aux2, sizeof(int), 1, bytecodeFile);
		count2=0;
		//cout << "Metodes: " << aux2 << endl;
		while (count2<aux2){
			int uid;
			fread(&uid,		sizeof(int),	1, bytecodeFile);
			fread(&line,	sizeof(int),	1, bytecodeFile);
			fread(&constructor,	sizeof(char),	1, bytecodeFile);
			fread(&isStatic,	sizeof(char),	1, bytecodeFile);
			fread(&aux,	sizeof(int),	1, bytecodeFile);
			//name=(char*) malloc(sizeof(char)*(aux+1));
			name=new char[aux];
			fread(name, sizeof(char), aux, bytecodeFile);
			
			//cout << "\tMetode: $" << name << "$" << endl;
			
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
			//free(name);
			delete name;

			count2++;
		}//*/
		if (strcmp(cache->getName().c_str(),"Object")!=0)
			adaptador->assignClass(cache);
		count1++;
	}
	
	OnStartUp::registerAll(adaptador);
	adaptador->apply();
	
	// Reading the constants. 
	count1=0;
	fseek(bytecodeFile, header.p_Constants, SEEK_SET);
	while(count1<header.n_Constants){
		int cid;
		char type;
		int itype;
		bool booleanValue;
		char characterValue;
		int integerValue;
		float floatValue;
		int stringSize;
		char* stringValue;
		
		
		fread(&type, 	sizeof(char), 	1, 	bytecodeFile);
		fread(&cid, 	sizeof(int),	1,	bytecodeFile);
		itype=type;
		//cout << "Constant " << cid << " de tipus: " << itype << " ->";
		switch (itype) {
			case 1: // Boolean
				fread(&characterValue, sizeof(char), 1, bytecodeFile);
				booleanValue=characterValue;
				data->addConstant(cid, 
								  checkAndCast<BooleanClass>(data->getClass("Boolean"))->getNewInstance(booleanValue));
				//cout << booleanValue << endl;
				break;
			case 2: // Character -- Undefined
				fread(&characterValue, sizeof(char), 1, bytecodeFile);
				cerr << "Warning: Char not defined" << endl;
				//cout << characterValue << endl;
				break;
			case 3: // Integer
				fread(&integerValue, sizeof(int), 1, bytecodeFile);
				data->addConstant(cid, 
								  checkAndCast<IntegerClass>(data->getClass("Integer"))->getNewInstance(integerValue));
				//cout << integerValue << endl;
				break;
			case 4: // Float
				cerr << "Warning: Float not defined" << endl;
				fread(&floatValue, sizeof(float), 1, bytecodeFile);
				//cout << floatValue << endl;
				break;
			case 5: // String
				fread(&stringSize, sizeof(int), 1, bytecodeFile);
				stringValue=new char[stringSize];
				fread(stringValue, sizeof(char), stringSize, bytecodeFile);
				//stringValue[stringSize]='\0';
				data->addConstant(cid, 
								  checkAndCast<StringClass>(data->getClass("String"))->getNewInstance(stringValue));
				//cout << stringValue << endl;
				delete stringValue;
				break;
			default:
				break;
		}
		count1++;
	}
	
	bytecode=new ASM_line[header.n_ByteCode+6];
	
	fseek(bytecodeFile, header.p_ByteCode, SEEK_SET);
	fread(bytecode, sizeof(ASM_line), header.n_ByteCode, bytecodeFile);
	
	fclose(bytecodeFile);
	
	SuperClass* programObject=data->getClass(header.uid_programClass);
	
	//cout << "Debug:" << programObject->getName() << programObject->getMethod("main") << endl;
	//cout << "Debug:" << programObject->getOfxName() << programObject->getCache()->getMethodUid("main") << endl;
	
	bytecode[header.n_ByteCode].instruction=LOAD_CLASS;
	bytecode[header.n_ByteCode].param=header.uid_programClass;
	bytecode[header.n_ByteCode+1].instruction=LOAD_METHOD;
	bytecode[header.n_ByteCode+1].param=programObject->getMethodUid(programObject->getOfxName());
	bytecode[header.n_ByteCode+2].instruction=CALL;
	bytecode[header.n_ByteCode+2].param=0;
	bytecode[header.n_ByteCode+3].instruction=LOAD_METHOD;
	bytecode[header.n_ByteCode+3].param=programObject->getCache()->getMethodUid("main");
	bytecode[header.n_ByteCode+4].instruction=CALL;
	bytecode[header.n_ByteCode+4].param=0;
	bytecode[header.n_ByteCode+5].instruction=RET;
	bytecode[header.n_ByteCode+5].param-1;
	
	return pair<ASM_line*, int>(bytecode, header.n_ByteCode);
}

int main(int argc,char* args[]){
	clock_t start, finish;
	
	RegisterClass<ShellClass> registrador;

	printf("Objective-Fenix VM\nAuthor:\n\tJaume Singla Valls\nCollaborator:\n\tFernando Arroba\n");
	//printf("%d\n", argc);
	if (argc !=2){
		printf("Usage: %s file.ofb\n", args[0]);
		exit(-1);
	}
	//Library* data=new Library();
	pair<ASM_line*, int> program=loadByteCode(args[1], Library::getLibrary());
	
	Thread cpu(program.first, Library::getLibrary());
	
	start=clock();
	cpu.run(program.second);

	finish=clock();
	//printf("Debug:\nStack Quantity: %d\n", p.top);
	printf("Time: %f\n", ((float)(finish - start)/(float)CLOCKS_PER_SEC ));
	//*/
	
	
	return 0;
}