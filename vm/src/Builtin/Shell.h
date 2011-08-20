/*
 *  Shell.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "class.h"
#include "String.h"

namespace objfenix {
	class Shell : public BuiltInClass{
	protected:
		void print(String* s);
	public:
		Shell(ofxbytecode::Library* data):BuiltInClass(-1, data){name="Shell";}
		void call(int num, ofxbytecode::Stack<Stackable*>* pila, int params);
		//Stackable* getMethod(int num);
		
		Class* getAtr(int i){};
		//virtual void call(ofxbytecode::Stack<Stackable*>* p, ASM_line* l, int i){};
		Stackable* getInstane(){};
		virtual void setAtr(int i, Stackable* atr){};
	};
}