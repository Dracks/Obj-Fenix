/*
 *  thread.h
 *  vm
 *
 *  Created by dracks on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef THREAD_H
#define THREAD_H

namespace ofxbytecode {
	class Thread;
}

#include "../ASM_instructions.h"
#include "../Builtin/Stackable.h"
#include "Stack.h"
#include "Library.h"
#include <utility>
using namespace std;

typedef struct{
	objfenix::Stackable** pila;
	int numTop;
	//objfenix::Object* top;
	int top;
} Pila;//*/

//static void* jmp_asm[SIZE_INSTRUCTIONS];

namespace ofxbytecode{
	class Thread {
	private:
		ASM_line* code;
		Stack<objfenix::Stackable*>* dataStack;
		Stack<pair<int,ASM_line*> >*	callStack;
		void* jmp_asm[SIZE_INSTRUCTIONS];
		Library* data;
	public:
		
//		static void charge_instructions();
		Thread(ASM_line* code, Library* data);
		int run(int line);
	};
}

#endif