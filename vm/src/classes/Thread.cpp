/*
 *  thread.cpp
 *  vm
 *
 *  Created by dracks on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Thread.h"

#include "../SDK/Super.h"
#include "stdio.h"
#include "../BuiltIn/Boolean.h"

#include <time.h>

using namespace SDK;
using namespace ofxBI;

namespace ofxbytecode{
	
/*Thread::charge_instructions(){
	//INSTRUCTIONS=calloc()
	//INSTRUCTIONS[]=&Thread::asm;
	jmp_asm[]=&&;
	jmp_asm[]=&&;
	jmp_asm[]=&&;*
	
}*/
	Thread::Thread(ASM_line* code, Library* data){
		this->code=code;
		this->dataStack=new Stack<Stackable*>(1024);
		this->callStack=new Stack<pair<int, ASM_line*> >();
		this->data=data;
		/*this->pila.numTop=0;
		 this->pila.pila=new calloc(sizeof(Object*)*1024);
		 this->pila.top=this->pila.pila;*/
		stadistics=vector<pair<int, int> >(20, make_pair<int,int>(0,0));
		
	}
	int Thread::run(int num_line){
		
		clock_t start;
		
		jmp_asm[LOAD_GLOBAL]=&&l_global;
		jmp_asm[LOAD_PRIVATE]=&&l_private;
		jmp_asm[LOAD_ATTR]=&&l_attr;
		jmp_asm[LOAD_CLASS]=&&l_class;
		jmp_asm[LOAD_METHOD]=&&l_method;
		jmp_asm[LOAD_CONSTANT]=&&l_constant;
		jmp_asm[CALL]=&&i_call;
		jmp_asm[RET]=&&i_ret;
		jmp_asm[POP_TOP]=&&i_pop;
		jmp_asm[PUSH_TOP]=&&i_push;
		jmp_asm[GOTO]=&&i_goto;
		jmp_asm[GOTO_TRUE]=&&i_g_true;
		jmp_asm[GOTO_FALSE]=&&i_g_false;
		jmp_asm[STORE_ATTR]=&&i_s_attr;
		jmp_asm[STORE_PRIVATE]=&&i_s_private;
		
		ASM_line* line=&(this->code[num_line]);
		int ini_params=dataStack->getTop();
		Stackable* elem_aux;
/*
#define startClock 
#define stopClock(p)
//*/
#define startClock start=clock();
#define stopClock(p) stadistics[p].first++; stadistics[p].second+=clock()-start;
#define kjmp(p) goto *(jmp_asm[p->instruction]);
		kjmp(line);
	l_global:
		//printf("debug: l_global\n");
		line++;
		kjmp(line);
	l_private:
		//elem_aux=dataStack->get(ini_params+line->param);
		//printf("debug: l_private (%s)\n", elem_aux->getName());
		startClock
		dataStack->push(dataStack->get(ini_params+line->param));
		stopClock(1)
		line++;
		kjmp(line);
	l_attr:
		startClock
		dataStack->push(checkAndCast<Super>(dataStack->pop())->getProperty(line->param));
		stopClock(2)
		line++;
		kjmp(line);
	l_class:
		//cout << "l_class: " << dataStack->getTop() << ":=" << data->getClass(line->param) << "(" << line->param <<")" << endl;
		startClock
		dataStack->push(data->getClass(line->param));
		stopClock(3)
		line++;
		kjmp(line);
	l_method:
		startClock
		elem_aux=dataStack->pop();
		//printf("debug: l_method %s %d\n", elem_aux->getName());
		//cout << "l_method: " << checkAndCast<Super>(elem_aux)->getName() << " -> (" << line->param << ")" << endl;
		//cout << "l_method: " << checkAndCast<Super>(elem_aux)->getName() << " -> (" << line->param << ")"<< checkAndCast<Super>(elem_aux)->getMethod(line->param)->getName() << endl;
		dataStack->push(checkAndCast<Super>(elem_aux)->getMethod(line->param));
		dataStack->push(elem_aux);
		stopClock(4)
		line++;
		kjmp(line);
	l_constant:
		startClock
		//	elem_aux=search_constant(line->param);
		//printf("debug: l_constant %s\n", elem_aux->getName());
		dataStack->push(data->getConstant(line->param));
		stopClock(5)
		line++;
		kjmp(line);
	i_call:
		startClock
		//elem_aux=0;
		//printf("debug: i_call%s\n", dataStack->get(dataStack->getTop()-line->param-1)->getName().c_str());
		//cout << "debug: i_call " << dataStack->get(dataStack->getTop()-line->param-1)->getName() << endl;
		//cout << "debug: i_call" << dataStack->getTop() << "-" << line->param << "-" << 1 << endl;
		Method* m=checkAndCast<Method>(dataStack->get(dataStack->getTop()-line->param-1));
		//cout << m->getName() << endl;
		int newLine=m->call(dataStack);
		int arguments=line->param;
		line++;
		// If the implementation of call is native or is with C call, it was 0, another case, we need to change context
		if (newLine!=0){
			//cout << "debug: i_call ->" << newLine << endl;
			callStack->push(pair<int, ASM_line*>(ini_params, line));
			line=&(this->code[newLine]);
			//line=newLine;
			ini_params=dataStack->getTop()-arguments;
		}
		stopClock(6)
		kjmp(line);
	i_ret:
		//printf("debug: i_ret %d\n", dataStack->getTop());
		startClock
		elem_aux=NULL;
		if (line->param>-1){
			elem_aux=dataStack->get(ini_params+line->param);
		} else if (line->param==-1){
			elem_aux=dataStack->pop();
		}
		//cout << elem_aux->getName() << endl;
		dataStack->set(ini_params-1, elem_aux);
		
		dataStack->reseTop(ini_params);
		if (callStack->getTop()==0)
			return 0;
		// we need to restore context;
		pair<int, ASM_line*> retPair=callStack->pop();
		line=retPair.second;
		ini_params=retPair.first;
		//line=callStack->pop();
		stopClock(7)
		kjmp(line);
	i_pop:
		startClock
		dataStack->pop();
		stopClock(8)
		line++;
		kjmp(line);
	i_push:
		startClock
		dataStack->push(0);
		stopClock(9)
		line++;
		kjmp(line);
	i_goto:
		startClock
		line=&this->code[line->param];
		stopClock(10)
		kjmp(line);
	i_g_true:
		startClock
		//cout << "i_g_true:" << checkAndCast<BooleanObject>(dataStack->get())->getValue() << endl;
		if (checkAndCast<BooleanObject>(dataStack->pop())->getValue()){
			line=&this->code[line->param];
		} else
			line++;
		stopClock(11)
		kjmp(line);
	i_g_false:
		startClock
		//cout << "i_g_false:" << checkAndCast<BooleanObject>(dataStack->get())->getValue() << endl;
		if (!checkAndCast<BooleanObject>(dataStack->pop())->getValue()){
			line=&this->code[line->param];
		} else
			line++;
		stopClock(12)
		kjmp(line);
	i_s_attr:
		startClock
		elem_aux=dataStack->get(ini_params);
		checkAndCast<Super>(elem_aux)->storePropiety(line->param, checkAndCast<SuperObject>(dataStack->pop()));
		stopClock(13)
		line++;
		kjmp(line);
	i_s_private:
		startClock
		//elem_aux=0;
		//printf("%s\n",elem_aux->getName());
		//elem_aux=dataStack->pop();
		//printf("debug: i_s_private (%s)\n", elem_aux->getName());
		dataStack->set(ini_params+line->param, dataStack->pop());
		stopClock(14)
		line++;
		kjmp(line);
	}
	
	vector<pair<int, int> > getStadistics(){
		return this->stadistics;
	}
}

