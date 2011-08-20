/*
 *  String.h
 *  vm
 *
 *  Created by dracks on 07/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

namespace objfenix {
	class String;
}

#ifndef STRING_H
#define STRING_H

#include "class.h"

namespace objfenix {
	class CString: public BuiltInClass{
	public:
		CString(int cid, ofxbytecode::Library* data);
		Class* getInstance();
		String* getInstance(string v);
		void parseMethod(string, int bytecodeUID);
		void call(int i, ofxbytecode::Stack<Stackable*>* p, int j);
		//virtual void setAtr(int i, Stackable* atr){/* throw exception */ };
		//void setMethod(int uid, string name, Method* m);
	};
	
	class String: public CString{
	private:
		string m_v;
	protected:
		
	public:
		String(int cid, string v, ofxbytecode::Library* data);
		inline string getValue();
		//Class* getAtr(int i){/* throw exception */ return 0;};
		//Stackable* getMethod(int i){};
		//void call(Pila* p, ASM_line* l, int i){};
		Class* getInstane(){return NULL;};
	};
	
	/*class String: public BuiltInClass{
	private:
		string m_str;
	protected:
		String(string str):BuiltInClass(-1){m_str=str;name="String";};
	public:
		string getValue(){return m_str;};
		Class* getAtr(int i){return NULL;};
		Method* getMethod(int i){return NULL;};
		//void call(Pila* p, ASM_line* l, int i){};
		void call(int i, ofxbytecode::Stack<Stackable*>* p, int j){};
		Class* getInstane(){return NULL;};
		virtual void setAtr(int i, Stackable* atr){};
	};*/
}

#endif