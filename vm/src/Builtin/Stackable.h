/*
 *  Stackable.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


namespace objfenix {
	class Stackable;
}


#include "../ASM_instructions.h"
#include "../classes/Thread.h"
#include "../classes/Stack.h"
#include "Method.h"
#include "Class.h"

#include <string>

#ifndef STACKABLE_H
#define STACKABLE_H


void run(ofxbytecode::Stack<objfenix::Stackable*> pila, ASM_line* code, int params, int line);
using namespace std;
namespace objfenix{
	
	class Stackable{
	protected:
		string name;
		int type;
	public:
		//virtual bool getNative()=0;
		Stackable(){}
		int getType(){return type;};
		virtual ~Stackable(){};
		string getName(){return name;};
		virtual Class* getAtr(int i)=0;
		virtual void setAtr(int i, Class* atr)=0;
		virtual Method* getMethod(int i)=0;
		//virtual void call(Pila* p, ASM_line* code, int params)=0;
		virtual int call(ofxbytecode::Stack<Stackable*>*, ASM_line*, int)=0;
	};
}

#endif