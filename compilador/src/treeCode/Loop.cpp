/*
 *  Loop.cpp
 *  compilador
 *
 *  Created by dracks on 27/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Loop.h"
#include "../tools.h"

extern int num_line;

Loop::Loop(int line_):Base(line_){}

void Loop::semantic(){
	for(vector<Base*>::iterator sentence=code.begin(); sentence!=code.end(); sentence++){
		(*sentence)->semantic();
	}
}
void Loop::addSentence(Base* sent){
		code.push_back(sent);
}

OFXByteCode::OFXJmpQueue* Loop::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue* ret=Base::ofxGenerate(obj);
	OFXByteCode::OFXJmpQueue* tmp=obj->getJmpQueue();
	int num_line=obj->getLine();
	for (int i=0; i<code.size();i++){
		obj->parseQueue(tmp->getNext());
		delete tmp;
		tmp=code[i]->ofxGenerate(obj);
	}
	obj->addInstruction(GOTO, num_line, "");
	obj->parseQueue(tmp->getNext(), num_line);
	return ret;
}

While::While(AbstractExpresion* cond, int line_):Loop(line_){
	condition=cond;
}
void While::semantic(){
	int tmp;
	SyntacticElement* tst=condition->getSemantic();
	if (tst!=NULL && !tst->testCastWith(searchElem("boolean",0), tmp)){
		char* str=(char*) malloc(sizeof(char)*1024);
		num_line=this->getLine();
		sprintf(str, "you cannot use %s as a Boolean", tst->getName().c_str());
		showError(str);
		free(str);
	}
	Loop::semantic();
}

OFXByteCode::OFXJmpQueue* While::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	//printf("While");
	OFXByteCode::OFXJmpQueue* ret=Base::ofxGenerate(obj);
	OFXByteCode::OFXJmpQueue* tmp=obj->getJmpQueue();
	int lineBegin=obj->getLine();
	condition->ofxGenerateLoad(obj);
	int lineGoto=obj->getLine();
	obj->addInstruction(GOTO_FALSE, lineGoto, "");
	ret->addNext(lineGoto);
	for (int i=0; i<code.size();i++){
		obj->parseQueue(tmp->getNext());
		delete tmp;
		tmp=code[i]->ofxGenerate(obj);
	}
	obj->parseQueue(tmp->getNext(), lineBegin);
	obj->addInstruction(GOTO, lineBegin, "");
	return ret;
}

OFXByteCode::OFXJmpQueue* DoWhile::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue* ret=Base::ofxGenerate(obj);
//	OFXByteCode::OFXJmpQueue* ret=obj->getJmpQueue();
	OFXByteCode::OFXJmpQueue* tmp=obj->getJmpQueue();
	int lineBegin=obj->getLine();
	for (int i=0; i<code.size();i++){
		tmp=code[i]->ofxGenerate(obj);
		obj->parseQueue(tmp->getNext());
		delete tmp;
	}
	condition->ofxGenerateLoad(obj);
	obj->addInstruction(GOTO_TRUE, lineBegin, "");

	return ret;
}

//	void generateByteCode();
/*
For::For(AbstractExpresion* Initializer, AbstractExpresion* cond, AbstractExpresion* Increment, int line_):While(cond, line_){
	this->Initializer=Initializer;
	this->Increment=Increment;
}

void For::semantic(){
	this->Initializer->semantic();
	this->Increment->semantic();
	While::semantic();
}
*/