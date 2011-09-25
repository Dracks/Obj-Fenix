/*
 *  Identifier.cpp
 *  compilador
 *
 *  Created by dracks on 19/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "syntacticElement.h"

#include "../tools.h"
#include <string.h>
#include <iostream>
#include "../../build/syntactic_parser.h"

int nextClassID=1; 
// this is the old, is for spacenames.
//0 => Global, typeClass; 1=>Undefined elements To Clone; 2=> First nameSpace for a class

int getNextClassID(){
	int tmp=nextClassID;
	nextClassID++;
	return tmp;
}

SyntacticElement::SyntacticElement(string _name, int _type, int line, char* file_){
	//name=strCopy(_name, strlen(_name));
	//name=strCopy(_name);
	name=_name;
	parserType=_type;
	UID=0;
	methodList=NULL;
	lineDefinition=line;
	file=file_;
	propietyList=new clist();
	nextMethodUID=0;
	nextPropietyUID=0;
	this->methodList=new clist();
	headerClass=NULL;
	packageContents=NULL;
	isStatic=false;
}
SyntacticElement::SyntacticElement(void* cont, int line, char* file_){
	name="Package";
	parserType=IDENTIFIER;
	UID=0;
	methodList=new clist;
	lineDefinition=line;
	file=file_;
	propietyList=new clist();
	nextMethodUID=0;
	nextPropietyUID=0;
	this->methodList=new clist();
	headerClass=NULL;
	packageContents=cont;
	syntactic_type=7;
	isStatic=false;
}

void* SyntacticElement::getPackage(){
	return packageContents;
}
void SyntacticElement::setSyntactic(int _val){
	syntactic_type=_val;
}

void SyntacticElement::setSemantic(struct SyntacticElement* _val){
	semantic_type=_val;
}

void SyntacticElement::setAmbito(int _val){
	ambito=_val;
}

void SyntacticElement::setUID(int _val){
	UID=_val;
}

void SyntacticElement::setSpaceName(int v){ spaceName=v;};
int SyntacticElement::getSpaceName(){return spaceName;};

void SyntacticElement::addPropiety(struct SyntacticElement* _val){
	this->propietyList->add(_val);
}

string SyntacticElement::getName(){
	return name;
}

char SyntacticElement::getSyntactic(){
	return syntactic_type;
}

int SyntacticElement::getParser(){
	return parserType;
}
SyntacticElement* SyntacticElement::searchSubElement(const char* name){
	cnode* node=this->propietyList->getFirst();
	SyntacticElement* aux;
	while (node!=NULL){
		aux=(SyntacticElement*) node->getContents();
		if (stricmp(name, aux->getName())==0){
			return aux;
		}
		node=node->getNext();
	}
	
	node=this->methodList->getFirst();
	while (node!=NULL){
		aux=(SyntacticElement*) node->getContents();
		if (stricmp(name, aux->getName())==0){
			return aux;
		}
		node=node->getNext();
	}
	if (this->semantic_type!=NULL)
		return this->semantic_type->searchSubElement(name);
	else
		return NULL;
}

clist* SyntacticElement::getPropietyListFrom(char _ambito){
	clist* devuelve=new clist();
	cnode* aux=propietyList->getFirst();
	while (aux!=NULL){
		SyntacticElement* tst=(SyntacticElement*) aux->getContents();
		if (tst->ambito<=_ambito){
			devuelve->add(tst);
		}
		aux=aux->getNext();
	}
	return devuelve;
}

int SyntacticElement::getUID(){
	return UID;
}

MethodDefinition* SyntacticElement::addMethodImplementation(clist* params, clist* vars, clist* code, SyntacticElement* returnType, int ambito, int num_line)
{
	MethodDefinition* tmp=new MethodDefinition(this->name, params, vars, code, returnType, ambito, num_line);
	methodList->add(tmp);
	return tmp;
}

void SyntacticElement::addMethod(SyntacticElement* val){
	methodList->add(val);
}

clist* SyntacticElement::getMethodList(){
	//At this moment, is basic options
	return this->methodList;
}

int SyntacticElement::getLine(){
	return lineDefinition;
}

char* SyntacticElement::getFile(){
	return file;
}

OFXByteCode::OFX_Class* SyntacticElement::getOFXClass(){
	return headerClass;
}

bool SyntacticElement::testCastWith(SyntacticElement* test, int &p){
	if (syntactic_type==1){
		if (stricmp(name, test->name)==0){
			return true;
		} else {
			if (semantic_type!=NULL){
				p++;
				return semantic_type->testCastWith(test,p);
			} else {
				return false;
			}
		}
	}
}

// Fix-It: don't find only in the first level that I found the same name and semantic Arguments. 
MethodDefinition* SyntacticElement::getMethodByNameArgsAndVisibility(const char* name, clist* args, char ambito){
	if (syntactic_type==1){
		cnode* nodeName=this->methodList->getFirst();
		while (nodeName!=NULL){
			SyntacticElement* s_name=(SyntacticElement*) nodeName->getContents();
			if (stricmp(s_name->name, name)==0){
				//printf("Method pseudo-found\n");
				int num_args=args->count();
				cnode* nodeImpl=s_name->methodList->getFirst();
				MethodDefinition* ret=NULL;
				while (nodeImpl!=NULL){
					int best, tmp, increment;
					MethodDefinition * elem=(MethodDefinition*) nodeImpl->getContents();
					if (elem->getParams()->count()==num_args){
						cnode* aux_paramMethod=elem->getParams()->getFirst();
						cnode* aux_paramCall=args->getFirst();
						bool trobat=true;
						increment=0;
						while (aux_paramMethod!=NULL){
							tmp=0;
							SyntacticElement* syn_paramCall=(SyntacticElement*) aux_paramCall->getContents();
							SyntacticElement* syn_paramMethod=(SyntacticElement*) aux_paramMethod->getContents();
							//Fix-It: Change stricmp to (SyntacticElement*)->tstCastWith
							if (/*stricmp(syn_paramCall->getName(), syn_paramMethod->getSemantic()->getName())!=0*/
								!syn_paramCall->testCastWith(syn_paramMethod->getSemantic(),tmp)){
								trobat=false;
								break;
							} else {
								increment+=tmp;
							}
							aux_paramCall=aux_paramCall->getNext();
							aux_paramMethod=aux_paramMethod->getNext();
						}
						if (trobat){
							if (ret==NULL || best>increment){
								best=increment;
								ret=elem;
							}
							//return elem;
						}
					}
					nodeImpl=nodeImpl->getNext();
				}
				if (ret!=NULL)
					return ret;
				//
			}
			nodeName=nodeName->getNext();
		}
		if (this->semantic_type!=NULL){
			return this->semantic_type->getMethodByNameArgsAndVisibility(name, args, (ambito<2?ambito:2));
		}
	}
	return NULL;
}


clist* SyntacticElement::getMethodVisibles(char i){
	//At this moment, is basic options
	return this->methodList;
}

MethodDefinition::MethodDefinition(string name, clist* params, clist* vars, clist* code, SyntacticElement* returnType, int ambito,int line){
	if (params!=NULL){
		cnode* node=params->getFirst();
		bool open=false;
		while (node!=NULL){
			if (!open){
				open=true;
				name+="(";
			}else 
				name+=", ";
			
			name+=((SyntacticElement*) node->getContents())->getSemantic()->getName();
			node=node->getNext();
		}
		if (open)
			name+=")";
	}
	//printf(">%s<\n",name.c_str());
	this->name=name;
	if (params==NULL){
		this->params=new clist();
	} else {
		this->params=params;
	}
	if (code==NULL){
		this->code=new clist();
	} else {
		this->code=code;	
	}
	this->returnType=returnType;
	this->ambito=ambito;
	this->lineDefinition=line;
	if (vars==NULL){
		this->privateVars=new clist();
	} else {
		this->privateVars=vars;
	}
	
	constructor=false;
	
	isStatic=false;
	
}

void MethodDefinition::setSemanticArgs(clist* list){
	params=list;
}

clist* MethodDefinition::getSemanticArgs(){
	return params;
}

void MethodDefinition::setUID(int uid){
	UID=uid;
}

int MethodDefinition::getUID(){
	return UID;
}

clist* MethodDefinition::getPrivate(){
	return privateVars;
}

clist* MethodDefinition::getCode(){
	return code;
}

clist* MethodDefinition::getParams(){
	return params;
}

int MethodDefinition::getLine(){
	return lineDefinition;
}

string MethodDefinition::getName(){
	return name;
}

SyntacticElement* MethodDefinition::getReturn(){
	return returnType;
};


void	MethodDefinition::setReturn(SyntacticElement* ret){
	returnType=ret;
}

void  MethodDefinition::setStatic(bool v ){
	this->isStatic=v;
}

bool  MethodDefinition::getStatic(){
	return isStatic;
}