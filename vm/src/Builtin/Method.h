/*
 *  Method.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

namespace objfenix {
	class Method;
	class BuiltInMethod;
	class OFXMethod;
}

#ifndef METHOD_H
#define METHOD_H

#include "Stackable.h"
#include "class.h"
//#include "object.h"



namespace objfenix {
	
	class Method: public Stackable{
	protected:
		virtual ~Method(){};
	public:
		Method(){};
		virtual bool isNative()=0;
		virtual Class* getAtr(int i){return NULL;};
		virtual void setAtr(int, Class*){};
		virtual Method* getMethod(int i){return NULL;};
	};
	
	class BuiltInMethod: public Method{
		int m_numMethod;
		BuiltInClass* m_obj;
	public:
		BuiltInMethod(BuiltInClass* obj, int m);
		virtual bool isNative();
		virtual ~BuiltInMethod();
		//virtual void setAtr(int i, Stackable* atr);
		//virtual Stackable* getAtr(int i);
		//virtual Method* getMethod(int i);
		virtual int call(ofxbytecode::Stack<Stackable*>* p, ASM_line* code, int params);
	};

	class OFXMethod: public Method{
		int m_line;
		char constructor;
	public:
		OFXMethod(char constructor, int line);
		~OFXMethod();
		virtual bool isNative();
		//virtual Stackable* getAtr(int i);
		//virtual Method* getMethod(int i);
		//virtual void call(Pila* p, ASM_line* code, int params){
		virtual int call(ofxbytecode::Stack<Stackable*>* p, ASM_line* code, int params);
	};
}

#endif