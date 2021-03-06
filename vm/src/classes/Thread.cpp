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

#define startClock 
#define stopClock(p)
//*/
/*
#define startClock start=clock();
#define stopClock(p) stadistics[p].second+=clock()-start; stadistics[p].first++;
//*/
#define kjmp(p) goto *(jmp_asm[p->instruction]);
		kjmp(line);
	l_global:
		//printf("debug: l_global\n");
		//cout << "l_global" << endl;
		line++;
		kjmp(line);
	l_private:
		//cout << "l_private" << endl;
		//elem_aux=dataStack->get(ini_params+line->param);
		//printf("debug: l_private (%s)\n", elem_aux->getName());
		//startClock
		dataStack->push(dataStack->get(ini_params+line->param));
		//stopClock(1)
		line++;
		kjmp(line);
	l_attr:
		//cout << "l_attr" << endl;
		//startClock
		dataStack->push(checkAndCast<Super>(dataStack->pop())->getProperty(line->param));
		//stopClock(2)
		line++;
		kjmp(line);
	l_class:
		//cout << "l_class" << endl;
		//cout << "l_class: " << dataStack->getTop() << ":=" << data->getClass(line->param) << "(" << line->param <<")" << endl;
		//startClock
		dataStack->push(data->getClass(line->param));
		//stopClock(3)
		line++;
		kjmp(line);
	l_method:
		//cout << "l_method" << endl;
		//startClock
		elem_aux=dataStack->get();
		//printf("debug: l_method %s %d\n", elem_aux->getName());
		//cout << "l_method: " << checkAndCast<Super>(elem_aux)->getName() << " -> (" << line->param << ")" << endl;
		//cout << "l_method: " << checkAndCast<Super>(elem_aux)->getMethod(line->param) << endl;
		//cout << "l_method: " << checkAndCast<Super>(elem_aux)->getName() << " -> (" << line->param << ")"<< checkAndCast<Super>(elem_aux)->getMethod(line->param)->getName() << endl;
		//dataStack->push();
		//dataStack->push(elem_aux);
		cacheCall.push_back(checkAndCast<Super>(elem_aux)->getMethod(line->param));
		//cout << "cacheCall:" << cacheCall.back() << endl;
		//stopClock(4)
		line++;
		kjmp(line);
	l_constant:
		//cout << "l_constant" << endl;
		//startClock
		//	elem_aux=search_constant(line->param);
		//printf("debug: l_constant %s\n", elem_aux->getName());
		dataStack->push(data->getConstant(line->param));
		//stopClock(5)
		line++;
		kjmp(line);
	i_call:
		//cout << "i_call" << endl;
		//startClock
		//elem_aux=0;
		//printf("debug: i_call%s\n", dataStack->get(dataStack->getTop()-line->param-1)->getName().c_str());
		//cout << "debug: i_call " << dataStack->get(dataStack->getTop()-line->param-1)->getName() << endl;
		//cout << "debug: i_call" << dataStack->getTop() << "-" << line->param << "-" << 1 << endl;
		//Method* m=checkAndCast<Method>(dataStack->get(dataStack->getTop()-line->param-1));
		//cout << m->getName() << endl;
		//cout << "back" << cacheCall.back() << endl;
		int newLine=cacheCall.back()->call(dataStack);
		//cout << "out" << endl;
		cacheCall.pop_back();
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
		//stopClock(6)
		kjmp(line);
	i_ret:
		//cout << "i_ret" << endl;
		//printf("debug: i_ret %d\n", dataStack->getTop());
		//startClock
		elem_aux=NULL;
		if (line->param>-1){
			elem_aux=dataStack->get(ini_params+line->param);
		} else if (line->param==-1){
			elem_aux=dataStack->pop();
		}
		//cout << elem_aux->getName() << endl;
		dataStack->set(ini_params, elem_aux);
		
		dataStack->reseTop(ini_params);
		if (callStack->getTop()==0)
			return 0;
		// we need to restore context;
		pair<int, ASM_line*> retPair=callStack->pop();
		line=retPair.second;
		ini_params=retPair.first;
		//line=callStack->pop();
		//stopClock(7)
		kjmp(line);
	i_pop:
		//cout << "i_pop" << endl;
		//startClock
		dataStack->pop();
		//stopClock(8)
		line++;
		kjmp(line);
	i_push:
		//cout << "i_push" << endl;
		//startClock
		dataStack->push(0);
		//stopClock(9)
		line++;
		kjmp(line);
	i_goto:
		//cout << "i_goto" << endl;
		//startClock
		line=&this->code[line->param];
		//stopClock(10)
		kjmp(line);
	i_g_true:
		//cout << "i_g_true" << endl;
		//startClock
		//cout << "i_g_true:" << checkAndCast<BooleanObject>(dataStack->get())->getValue() << endl;
		//if (checkAndCast<BooleanObject>(dataStack->pop())->getValue()){
		if (((BooleanObject*) dataStack->pop())->getValue()){
			line=&this->code[line->param];
		} else
			line++;
		//stopClock(11)
		kjmp(line);
	i_g_false:
		//cout << "i_g_false" << endl;
		//startClock
		//cout << "i_g_false:" << checkAndCast<BooleanObject>(dataStack->get())->getValue() << endl;
		if (((BooleanObject*)dataStack->pop())->getValue()){
		//if (!checkAndCast<BooleanObject>(dataStack->pop())->getValue()){
			line++;
		} else
			line=&this->code[line->param];
		//stopClock(12)
		kjmp(line);
	i_s_attr:
		//cout << "i_s_attr" << endl;
		//startClock
		elem_aux=dataStack->get(ini_params);
		checkAndCast<Super>(elem_aux)->storePropiety(line->param, checkAndCast<SuperObject>(dataStack->pop()));
		//stopClock(13)
		line++;
		kjmp(line);
	i_s_private:
		//cout << "i_s_private" << endl;
		//startClock
		//elem_aux=0;
		//printf("%s\n",elem_aux->getName());
		//elem_aux=dataStack->pop();
		//printf("debug: i_s_private (%s)\n", elem_aux->getName());
		dataStack->set(ini_params+line->param, dataStack->pop());
		//stopClock(14)
		line++;
		kjmp(line);
	}
	
	vector<pair<int, int> > Thread::getStadistics(){
		return this->stadistics;
	}
}

