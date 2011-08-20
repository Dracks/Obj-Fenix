/*
 *  Espresion.h
 *  compilador
 *
 *  Created by dracks on 27/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef EXPRESION_H
#define EXPRESION_H

#include "Base.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "../classes/syntacticElement.h" 
using namespace std;

class AbstractExpresion: public Base{
public:
	AbstractExpresion(SyntacticElement* elem_, int line_):Base(line_){
		this->elem=elem_;
		this->parent=NULL;
		this->methodCache=NULL;
		//printf("test:%s \n", this->elem->getName());
	};
	
	virtual void createInstruction(OFXByteCode::OFXByteCode* obj);
	
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
	virtual void ofxGenerateLoad(OFXByteCode::OFXByteCode* obj);
	virtual ASM_line ofxGenerateReplace(OFXByteCode::OFXByteCode* obj);
	
	virtual void getName(string&);
	virtual SyntacticElement* getSemantic(){
		printf("we have a big problem\n");
		return this->elem->getSemantic();
	};
	virtual bool verifyVariable(){return this->elem->getSyntactic()==3 || this->elem->getSyntactic()==5;};
	void semantic(){this->getSemantic();};
	SyntacticElement* getElem(){return elem;}
	void setParent(SyntacticElement* parent);
protected:
	SyntacticElement* parent;
	SyntacticElement* elem;
	MethodDefinition* methodCache;
	vector<AbstractExpresion*> listParametros;
};

class Assignation: public Base{
private:
	AbstractExpresion* dst;
	AbstractExpresion* src;
public:
	Assignation(AbstractExpresion* dst_, AbstractExpresion* src_,int line_): Base(line_){
		dst=dst_;
		src=src_;
	};
	virtual void semantic();
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
};

class Return: public Base{
private:
	AbstractExpresion* ret;
	SyntacticElement* m_semantic;
public:
	Return(AbstractExpresion* ret_, int line_);
	virtual void semantic();
	virtual void setSemantic(SyntacticElement* sem);
	virtual bool isReturn(){return true;};
	virtual OFXByteCode::OFXJmpQueue* ofxGenerate(OFXByteCode::OFXByteCode* obj);
};

/*class Call: public AbstractExpresion{
	// Contains the "expresions" of each parameter 
	vector<AbstractExpresion*> listParametros;
};*/

 /*
  * a propiety is defined as a variable {dot variable}
  */
class Subpropiety: public AbstractExpresion{
private:
	int methodUID;
	Subpropiety* subElement;
public:
	Subpropiety(SyntacticElement* elem_, int line_);
	virtual void getName(string&);
	virtual SyntacticElement* semanticNext(SyntacticElement* parent);
	virtual bool verifyVariable();
	//virtual SyntacticElement* semanticNextStatic(SyntacticElement* parent);
	void setExtension(Subpropiety* subElement_){subElement=subElement_;}
	void addParamCall(AbstractExpresion* param){listParametros.push_back(param);}
	virtual SyntacticElement* getSemantic();
	virtual void ofxGenerateLoad(OFXByteCode::OFXByteCode* obj);
	virtual ASM_line ofxGenerateReplace(OFXByteCode::OFXByteCode* obj);
};

#endif


