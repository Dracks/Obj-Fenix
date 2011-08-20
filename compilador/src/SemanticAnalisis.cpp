/*
 *  SemanticAnalisis.cpp
 *  compilador
 *
 *  Created by Jaume Singla Valls on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "SemanticAnalisis.h"
#include "debug.h"
#include "tools.h"
#include "classes/syntacticElement.h"
#include "treeCode/Base.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


extern int num_line;
extern char* parsing_file;

namespace SemanticAnalisis {
	using namespace std;
	
	
	
	void semanticValidation(clist* objects){
		//printf("asd\n");
		cnode* aux=objects->getFirst();
		char* debugText=(char*) malloc(sizeof(char)*1024);
		while (aux!=NULL){
			SyntacticElement* object=(SyntacticElement*)aux->getContents();
			if (object!=NULL && !object->getSemanticValidated()){
				sprintf(debugText, "Object %s is not validated", object->getName().c_str());
				semantic_debug(0, debugText);
				validateObject(object);
			}
			aux=aux->getNext();
		}
		free(debugText);
	}
	
	void validateObject(SyntacticElement* object){
		//printf("asd2\n");
		char* debugText=(char*) malloc(sizeof(char)*1024);
		sprintf(debugText, "Validating object: %s with native flag: %d", object->getName().c_str(), object->getNative());
		semantic_debug(-1,debugText);
		SyntacticElement* parent=object->getSemantic();
		if (parent!=NULL && !parent->getSemanticValidated()){
			sprintf(debugText, "Object %s is not validated and is my father", parent->getName().c_str());
			semantic_debug(0,debugText);
			validateObject(parent);
		}
		object->setSemanticValidated(true);
		if (parent!=NULL){
			object->setNextMethodUID(parent->getNextMethodUID());
			object->setNextPropietyUID(parent->getNextPropietyUID());
		} else{
			// This is stupid, at this moment everyclass has a parent class, It is Object class.
			object->setNextMethodUID(1);
			object->setNextMethodUID(1);
		}
		//	if (!object->getNative()){ //I think it is incorrect. 
		
		cnode* propietyNode=object->getPropietyListFrom(3)->getFirst();
		while (propietyNode!=NULL){
			SyntacticElement* propiety=(SyntacticElement*) propietyNode->getContents();
			SyntacticElement* sem=propiety->getSemantic();
			propiety->setUID(object->getNextPropietyUID());
			printf("Propiety: %s withClass: %s\n", propiety->getName().c_str(), sem->getName().c_str());
			if (sem->getSyntactic()!=1) {
				char* errorText=(char*) malloc(sizeof(char)*1024);
				num_line=propiety->getLine();
				parsing_file=object->getFile();
				sprintf(errorText, "The lexem '%s'(%p) isn't a valid class ID: %d", sem->getName().c_str(), sem, sem->getSyntactic());
				showError(errorText);
				free(errorText);
				//delete semanticParams;
				//errors=1;
				//break;
				//continue(2);
			}
			propietyNode=propietyNode->getNext();
		}
		cnode* MethodsGroup=object->getMethodList()->getFirst();
		while (MethodsGroup!=NULL){
			SyntacticElement* methodName=((SyntacticElement*) MethodsGroup->getContents());
			cnode* nodeImplementations=methodName->getMethodVisibles(3)->getFirst();
			sprintf(debugText, "List of methods with Name: %s", methodName->getName().c_str());
			//printf("List of methods with Name: %s\n", methodName->getName().c_str());
			semantic_debug(-1, debugText);
			//A list of metods with same name. 
			while (nodeImplementations!=NULL){
				MethodDefinition* implementation=(MethodDefinition*) nodeImplementations->getContents();
				//Validate Params. And types
				//printf("-->%s<\n", implementation->getName().c_str());
				clist* semanticParams=new clist();
				cnode* nodeParam=implementation->getParams()->getFirst();
				char errors=0;
				while (nodeParam!=NULL){
					SyntacticElement* arg=(SyntacticElement*) nodeParam->getContents();
					SyntacticElement* sem=arg->getSemantic();
					if (sem->getSyntactic()==1){
						semanticParams->add(sem);
					} else {
						char* errorText=(char*) malloc(sizeof(char)*1024);
						num_line=implementation->getLine();
						parsing_file=object->getFile();
						sprintf(errorText, "The lexem '%s'(%p) isn't a valid class ID: %d", sem->getName().c_str(), sem,sem->getSyntactic());
						showError(errorText);
						free(errorText);
						//delete semanticParams;
						errors=1;
						//break;
						//continue(2);
					}
					nodeParam=nodeParam->getNext();
				}
				if (!errors){
					//implementation->setSemanticArgs(semanticParams);
					MethodDefinition* dinamicLink=NULL;
					if (!object->getNative() && parent!=NULL)
						dinamicLink=parent->getMethodByNameArgsAndVisibility(methodName->getName().c_str(), semanticParams, 2);
					// change it to a 
					if (dinamicLink!=NULL){
						implementation->setUID(dinamicLink->getUID());
					} else {
						implementation->setUID(object->getNextMethodUID());
					}
				}
				
				/*if (!errors){
					SyntacticElement* ret=implementation->getReturn();
					if (ret!=NULL){ // Fix-it don't create bytecode for instructions after the return. 
						if (ret->getSyntactic()!=1){ //If it isn't a class type, or is undefined, ERROR!
							num_line=implementation->getLine();
							parsing_file=object->getFile();
							char* errorText=(char*) malloc(sizeof(char)*1024);
							sprintf(errorText, "The lexem '%s'(%p) isn't a valid class ID: %d", ret->getName().c_str(), ret,ret->getSyntactic());
							showError(errorText);
							free(errorText);							
						} else {
							if (implementation->getnReturnStatments()==0 && !object->getNative() && stricmp(methodName->getName(), object->getName())!=0){
								string s="You need a return statment for the method ";
								s+=implementation->getName();
								showError((char*)s.c_str());
							}
							//Verify that you return at least 1 time. 
						}
					}
				}*/
				
				if (!errors){
					cnode* privNode=implementation->getPrivate()->getFirst();
					while (privNode!=NULL){
						SyntacticElement* var=(SyntacticElement*) privNode->getContents();
						if (var->getSemantic()==NULL || var->getSemantic()->getSyntactic()!=1){
							string s="The variable ";
							s+=var->getName();
							s+=" don't has a valid class";
							num_line=implementation->getLine();
							showError((char*) s.c_str());
						}
						privNode=privNode->getNext();
					}
				}
				
				//Validate code
				if (!errors){
					if (implementation->getCode()!=NULL){
						//printf("Aqui m'aposto que no entra\n");
						cnode* lineCode=implementation->getCode()->getFirst();
						bool hasReturn=false;
						bool validateReturn=false;
						while (lineCode!=NULL){
							validateReturn=true;
							Base* line=(Base*)lineCode->getContents();
							line->semantic();
							hasReturn = hasReturn | line->isReturn();
							lineCode=lineCode->getNext();
						}
						//printf("B: %d\n", hasReturn);
						if (validateReturn && !hasReturn && implementation->getReturn()!=NULL && !implementation->isConstructor()){
							string s="You need a return statment for the method ";
							s+=implementation->getName();
							showError((char*)s.c_str());
						}
					}
				}
				nodeImplementations=nodeImplementations->getNext();
			}
			MethodsGroup=MethodsGroup->getNext();
		}
		//}
		free(debugText);
	}
	
}
