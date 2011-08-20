/*
 *  condition.cpp
 *  compilador
 *
 *  Created by Jaume Singla Valls on 03/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Condition.h"
#include "../tools.h"
#include "../debug.h"
#include <vector>

void Condition::semantic(){
	SyntacticElement* cond=condition->getSemantic();
	if (strcmp(cond->getName().c_str(),"Integer")!=0 &&strcmp(cond->getName().c_str(),"Boolean")!=0){
		char* str=(char*) malloc(sizeof(char)*1024);
		sprintf(str, "The expression condition of this line must be a Boolean");
		showError(str);
		free(str);
	}
	for(vector<Base*>::iterator sentence=code.begin(); sentence!=code.end(); sentence++){
		(*sentence)->semantic();
	}
	if (alternative!=NULL)
		alternative->semantic();
};

OFXByteCode::OFXJmpQueue* Condition::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue*	ret=Base::ofxGenerate(obj);
	OFXByteCode::OFXJmpQueue*	tmp=obj->getJmpQueue();
	condition->ofxGenerateLoad(obj);
	int line=obj->getLine();
	obj->addInstruction(GOTO_FALSE, obj->getLine(), "");
	for (int i=0; i<code.size(); i++){
		obj->parseQueue(tmp->getNext());
		delete tmp;
		tmp=code[i]->ofxGenerate(obj);
	}
	tmp->addNext(line);
	if (alternative!=NULL){
		ret->addNext(obj->getLine());
		obj->addInstruction(GOTO, obj->getLine(), "");
		
		obj->parseQueue(tmp->getNext());
		delete tmp;
		tmp=alternative->ofxGenerate(obj);
	}
	for (int i=0; i<tmp->getNext().size();i++){
		ret->addNext(tmp->getNext()[i]);
	}
	delete tmp;
	return ret;
}

void Else::semantic(){
	for(vector<Base*>::iterator sentence=code.begin(); sentence!=code.end(); sentence++){
		(*sentence)->semantic();
	}
};

OFXByteCode::OFXJmpQueue* Else::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue*	ret=Base::ofxGenerate(obj);
	OFXByteCode::OFXJmpQueue*	tmp=obj->getJmpQueue();

	for (int i=0; i<code.size(); i++){
		obj->parseQueue(tmp->getNext());
		delete tmp;
		tmp=code[i]->ofxGenerate(obj);
	}
	ret->addNext(obj->getLine());
	obj->addInstruction(GOTO, obj->getLine(), "");
	for (int i=0; i<tmp->getNext().size();i++){
		ret->addNext(tmp->getNext()[i]);
	}
	delete tmp;
	
	return ret;
}



