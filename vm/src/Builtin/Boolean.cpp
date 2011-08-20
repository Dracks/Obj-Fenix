/*
 *  Boolean.cpp
 *  vm
 *
 *  Created by Jaume Singla Valls on 01/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Boolean.h"
#include "../tools.h"

namespace objfenix {
	
	//class CBoolean: public BuiltInClass{
	
	CBoolean::CBoolean(int cid, ofxbytecode::Library* data):BuiltInClass(cid, data){
		name="CBoolean";
	};
	Class* CBoolean::getInstance(){
		return this->getInstance(false);
	}
	Class* CBoolean::getInstance(bool v){
		Boolean* ret=new Boolean(CID, v, data);
		BuiltInClass::getInstance(ret);
		return ret;
	}
	void CBoolean::parseMethod(string name , int bytecodeUID){
		if (stricmp(name.c_str(),"and(Boolean)")==0){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 1));
		} else if (stricmp(name.c_str(),"or(Boolean)")==0){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 2));
		} else {
			printf("CBoolean:Problem with: %s\n", name.c_str());
		}
	}
	void CBoolean::call(int n_method, ofxbytecode::Stack<Stackable*>* p, int n_args){
		int reset=p->getTop()-n_args-1;
		switch (n_method) {
			case 1: // And
				if (n_args==1){
					Boolean* op1=(Boolean*)p->pop(); // unstack argument
					Boolean* op2=(Boolean*)p->pop(); // unstack this
					//p->pop();
					p->set(reset, this->getInstance(op1->getValue() && op2->getValue()));
					
				}
				break;
			case 2:
				if (n_args==1){
					Boolean* op1=(Boolean*)p->pop(); // unstack argument
					Boolean* op2=(Boolean*)p->pop(); // unstack this
					//p->pop();
					p->set(reset, this->getInstance(op1->getValue() || op2->getValue()));
				}
				break;
			default:
				break;
		}
		p->reseTop(reset);
	};
	//void CBoolean::setAtr(int i, Stackable* atr){/* throw exception */ };
	//};
	
	//class Boolean: public CBoolean{
	
	Boolean::Boolean(int cid, bool v, ofxbytecode::Library* data):CBoolean(cid, data){
		m_v=v;
		name="Boolean";
	};
	
	bool Boolean::getValue(){
		return m_v;
	}
	//	};
}
