/*
 * vm
 * Copyright (C) Fernando Arroba Rubio 2011 <gnotxor@gmail.com>
 * 
 * vm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * vm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

namespace objfenix {
	class Class;
	class BuiltInClass;
}

#ifndef __CLASS_H
#define __CLASS_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Stackable.h"
#include "Method.h"

#include "../classes/Library.h"

//#include "../classes/Stack.h"
using namespace std;

namespace objfenix {

	class Class: public Stackable {
	protected:
		vector<Method*> methodList;
		vector<Class*> propietyList;
		map<string, int> propietyNames;
		map<string, int> methodNames;
		int CID;
		
		virtual ~Class();
	public:
		Class(int CID);
		virtual Class* getInstance()=0;
		
		// Get Method and Attribute by UID
		Method* getMethod(int);
		Class* getAtr(int);
		// Get Method and Atribute by name
		inline Method* getMethod(string);
		inline Class* getAtr(string);
		// in the VM, to store atribute
		void setAtr(int i, Class* atr);
		// Store atribute by name.
		void setAtr(string i, Class* atr);
		
		// Define Method with MethodClass*
		virtual void setMethod(int uid, string name, Method* m);
		virtual void setAtr(int uid, string name);
		
		long getID();
	};
	
	class BuiltInClass: public Class{
	protected:
		// Sempre els estic ficant i treient, i mai soc capaç de saber perque cony necessito aquests. Si tinc els noms!
		/*vector<int> methodTrans;
		vector<int> propietyTrans;*/
		ofxbytecode::Library* data;
	public:
		BuiltInClass(int CID, ofxbytecode::Library* data): Class(CID){ this->data=data;};
		virtual void call(int i, ofxbytecode::Stack<Stackable*>* p, int j)=0;
		virtual Class* getInstance(BuiltInClass* instance);
		virtual int call(ofxbytecode::Stack<Stackable*>*, ASM_line*, int){};
		//virtual void setMethod(string, int bytecodeUID)=0;
	};

	class OFXClass: public Class{
	protected:
		//Class* m_attr;
		//int* methodLines;
		virtual ~OFXClass();
	public:
		OFXClass(int cid);
		virtual OFXMethod* addMethod(string name, int UID, char constructor, int line);
		virtual void addAttribute(string name, int UID, int line);
		virtual Class* getInstance();
		virtual int call(ofxbytecode::Stack<Stackable*>*, ASM_line*, int){};
	};
	
	class OFXInstance: public OFXClass{
	protected:
		virtual ~OFXInstance();
	public:
		OFXInstance(int cid);
	};
	
	
/*	
 class BuiltInClass: public Class{
	public:
		ASM_line* call(ofxbytecode::Stack<Stackable*>* p, ASM_line* l, int i){return 0;};
		virtual void call(int num, ofxbytecode::Stack<Stackable*>* pila, int params)=0;
		virtual Stackable* getMethod(int i);
	};*/

}
#endif //__CLASS_H
