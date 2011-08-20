/*
 *  Method.cpp
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Method.h"
#include "stdio.h"

namespace objfenix {
	//class BuiltInMethod: public Method{
	BuiltInMethod::BuiltInMethod(BuiltInClass* obj, int m){
		//printf("BuiltInMethod");
		name="BuiltInMethod";
		m_numMethod=m;
		m_obj=obj;
	}
	bool BuiltInMethod::isNative(){return true;}
	BuiltInMethod::~BuiltInMethod(){};
	//void BuiltInMethod::setAtr(int i, Class* atr){};
	//Class* BuiltInMethod::getAtr(int i){/*throw exception */ };
	//Method* BuiltInMethod::getMethod(int i){/*throw exception */};
	int BuiltInMethod::call(ofxbytecode::Stack<Stackable*>* p, ASM_line* code, int params){
		//printf("BuiltInMethod: %s\n", m_obj->getName());
		//m_obj->call(m_numMethod, p, params);
		((BuiltInClass*) p->get(p->getTop()-params))->call(m_numMethod, p, params);
		return 0;
		
	}
	
	//class OFXMethod: public Method{
	OFXMethod::OFXMethod(char constructor, int line){
		m_line=line;
		name="OFXMethod";
	}
	OFXMethod::~OFXMethod(){};
	bool OFXMethod::isNative(){return false;}
	//Class* OFXMethod::getAtr(int i){/*throw exception */};
	//Stackable* OFXMethod::getMethod(int i){/*throw exception */};
	//virtual void call(Pila* p, ASM_line* code, int params){
	int OFXMethod::call(ofxbytecode::Stack<Stackable*>* p, ASM_line* code, int params){
		/*
		 * Ih this Method is a constructor, we create new instance for the object, and replace the old object
		 */
		if (this->constructor)
			p->set(p->getTop()-params,((OFXClass*) p->get(p->getTop()-params))->getInstance());
		return m_line;
	}
	
}