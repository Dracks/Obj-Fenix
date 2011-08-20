/*
 *  Boolean.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 01/06/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H


namespace objfenix {
	class Integer;
}

#include "class.h"

namespace objfenix {
	class CBoolean: public BuiltInClass{
	public:
		CBoolean(int CID, ofxbytecode::Library* data);
		Class* getInstance();
		Class* getInstance(bool v);
		void parseMethod(string, int bytecodeUID);
		void call(int i, ofxbytecode::Stack<Stackable*>* p, int j);
		//virtual void setAtr(int i, Stackable* atr){/* throw exception */ };
	};
	
	class Boolean: public CBoolean{
	private:
		bool m_v;
	protected:
	public:
		Boolean(int cid, bool v, ofxbytecode::Library* data);
		inline bool getValue();
		//Class* getAtr(int i){/* throw exception */ return 0;};
		//Stackable* getMethod(int i){};
		//void call(Pila* p, ASM_line* l, int i){};
		Class* getInstane(){return NULL;};
	};
}

#endif