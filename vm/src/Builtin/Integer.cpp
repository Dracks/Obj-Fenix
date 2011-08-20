/*
 *  Integer.cpp
 *  vm
 *
 *  Created by Jaume Singla Valls on 09/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Integer.h"
#include "stdio.h"
#include "../tools.h"

#include "Boolean.h"
#include "String.h"

namespace objfenix {
	//class CInteger: public BuiltInClass{
	CInteger::CInteger(int CID, ofxbytecode::Library* data):BuiltInClass(CID, data){name="CInteger";};
	
	void CInteger::parseMethod(string, int bytecodeUID){
		if (stricmp(name.c_str(), "Integer(Object)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 0));
		} else if (stricmp(name.c_str(), "add(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 1));
		} else if (stricmp(name.c_str(), "sub(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 2));
		} else if (stricmp(name.c_str(), "mul(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 3));
		} else if (stricmp(name.c_str(), "div(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 4));
		} else if (stricmp(name.c_str(), "dif(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 5));
		} else if (stricmp(name.c_str(), "equal(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 6));
		} else if (stricmp(name.c_str(), "lower(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 7));
		} else if (stricmp(name.c_str(), "greater(Integer)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 8));
		} else if (stricmp(name.c_str(), "toString")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 9));
		} else if (stricmp(name.c_str(), "Integer(String)")){
			this->setMethod(bytecodeUID, name, new BuiltInMethod(this, 10));//*/
		} else{
			printf("CInteger:Problem with: %s\n", name.c_str());
		}
	}
	
	void CInteger::call(int n_method, ofxbytecode::Stack<Stackable*>* p, int n_args){
		//printf("Integer %d\n", n_method);
		int reset=p->getTop()-n_args-1;
		switch (n_method){
			case 0:
				if (n_args==1){
					
					Integer* op1=(Integer*)p->pop();
					if (op1->CID!=this->CID){
						printf("ERROR: Casting incorrect in CInteger from op1: %s\n", op1->name.c_str());
					}
					//Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, op1);
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 1:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, this->getInstance(op2->getValue()+ op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 2:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, this->getInstance(op2->getValue()- op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 3:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, this->getInstance(op2->getValue()* op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 4:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, this->getInstance(op2->getValue()/op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 5:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, ((CBoolean*) this->data->getClass("Boolean"))->getInstance(op2->getValue()!= op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 6:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, ((CBoolean*) this->data->getClass("Boolean"))->getInstance(op2->getValue()==op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 7:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, ((CBoolean*) this->data->getClass("Boolean"))->getInstance(op2->getValue()< op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 8:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					p->set(reset, ((CBoolean*) this->data->getClass("Boolean"))->getInstance(op2->getValue()> op1->getValue()));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 9:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					//Integer* op2=(Integer*)p->pop();
					//p->pop();
					string s= "" + op1->getValue();
					p->set(reset, ((CString*) this->data->getClass("String"))->getInstance(s));
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
			case 10:
				if (n_args==1){
					Integer* op1=(Integer*)p->pop();
					Integer* op2=(Integer*)p->pop();
					//p->pop();
					//p->set(reset, this->getInstance(op2->getValue()- op1->getValue()));
					printf("No implementat el Integer(String)");
					//printf("Integer operation: %d (%d)\n", ((Integer*)p->get(reset))->m_v, op1->m_v);
				}
				break;
		}
		p->reseTop(reset);
	}
	
	Integer* CInteger::getInstance(int v){
		
	};
	
	Class* CInteger::getInstance(){return NULL;};
	
	//virtual void CInteger::setAtr(int i, Stackable* atr){/* throw exception */ };
	
	//class Integer: public CInteger{
	
	Integer::Integer(int cid, int v, ofxbytecode::Library* data):CInteger(cid, data){m_v=v; name="Integer";};
	
	int Integer::getValue(){return m_v;};
		//Class* getAtr(int i){/* throw exception */ return 0;};
		//Stackable* getMethod(int i){};
		//void call(Pila* p, ASM_line* l, int i){};
		//virtual Integer* getInstance(int v);
		//virtual Class* getInstance(){return new Integer(m_v);};
		//virtual void setAtr(int i, Stackable* atr){/* throw exception */ };
	//};
	
	
	
	

}