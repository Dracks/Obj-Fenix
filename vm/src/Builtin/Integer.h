/*
 *  Integer.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 09/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef INTEGER_H
#define INTEGER_H


namespace objfenix {
	class Integer;
}

#include "class.h"

namespace objfenix {
	class CInteger: public BuiltInClass{
	private:
	public:
		CInteger(int CID, ofxbytecode::Library* data);
		//Class* getAtr(int i){/* throw exception */ return 0;};
		//Stackable* getMethod(int i){};
		//void call(Pila* p, ASM_line* l, int i){};
		void parseMethod(string, int bytecodeUID);
		void call(int i, ofxbytecode::Stack<Stackable*>* p, int j);
		virtual Integer* getInstance(int v);
		virtual Class* getInstance();
		//virtual void setAtr(int i, Stackable* atr){/* throw exception */ };
	};
	
	class Integer: public CInteger{
	private:
		int m_v;
	protected:
		Integer(int cid, int v, ofxbytecode::Library* data);
	public:
		inline int getValue();
		//Class* getAtr(int i){/* throw exception */ return 0;};
		//Stackable* getMethod(int i){};
		//void call(Pila* p, ASM_line* l, int i){};
		//virtual Integer* getInstance(int v);
		//virtual Class* getInstance(){return new Integer(m_v);};
		//virtual void setAtr(int i, Stackable* atr){/* throw exception */ };
	};
}

#endif