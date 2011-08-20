/*
 *  String.cpp
 *  vm
 *
 *  Created by dracks on 07/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "String.h"
#include "../tools.h"

namespace objfenix {
	
	//class CString: public BuiltInClass{
	
	CString::CString(int cid, ofxbytecode::Library* data):BuiltInClass(cid, data){
		name="CString";
	};
	Class* CString::getInstance(){
		return this->getInstance("");
	}
	String* CString::getInstance(string v){
		String* ret=new String(this->CID, v, this->data);
		BuiltInClass::getInstance(ret);
		return ret;
	}
	void CString::parseMethod(string name, int bytecodeUID){
		if (stricmp(name.c_str(),"add(String)")==0){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 1));
		} /*else if (stricmp(name.c_str(),"or(String)")==0){
			//this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 2));
		} */else {
			printf("CString:Problem with: %s\n", name.c_str());
		}
	}
	void CString::call(int n_method, ofxbytecode::Stack<Stackable*>* p, int n_args){
		int reset=p->getTop()-n_args-1;
		switch (n_method) {
			case 1: // add
				if (n_args==1){
					String* op1=(String*)p->pop(); // unstack argument
					String* op2=(String*)p->pop(); // unstack this
					//p->pop();
					p->set(reset, this->getInstance(op1->getValue() + op2->getValue()));
					
				}
				break;
			/*case 2:
				if (n_args==1){
					String* op1=(String*)p->pop(); // unstack argument
					String* op2=(String*)p->pop(); // unstack this
					//p->pop();
					p->set(reset, this->getInstane(op1->getValue() || op2->getValue()));
				}
				break;*/
			default:
				break;
		}
		p->reseTop(reset);
	};
	//void CString::setAtr(int i, Stackable* atr){/* throw exception */ };
	//};
	
	//class String: public CString{
	
	String::String(int cid, string v, ofxbytecode::Library* data):CString(cid, data){
		m_v=v;
		name="String";
	};
	
	inline string String::getValue(){
		return m_v;
	}
	//	};
}