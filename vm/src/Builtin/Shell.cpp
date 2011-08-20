/*
 *  Shell.cpp
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Shell.h"
#include "stdio.h"
#include "object.h"
#include "Method.h"

using namespace std;

namespace objfenix {
	void Shell::print(String* s){
		printf("%s", s->getValue().c_str());
	}
	
	void Shell::call(int num, ofxbytecode::Stack<Stackable*>* pila, int params){
		switch(num){
			case 1:
				if (params!=1){
					/* throw exception */
				} else {
					Shell::print((String*) pila->pop());
					pila->pop();
					//pila->top-=1;
				}
		}
	}
	
	/*Stackable* Shell::getMethod(int i){
		return new BuiltInMethod(this, i);
	}*/
}
