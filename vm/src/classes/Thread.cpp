/*
 *  thread.cpp
 *  vm
 *
 *  Created by dracks on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Thread.h"
//#include "../Builtin/Integer.h"
#include "../SDK/Super.h"
#include "stdio.h"
#include "../BuiltIn/Boolean.h"
//#include "../Builtin/Stackable.h"

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
		
	}
	int Thread::run(int num_line){
		
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
#define kjmp(p) goto *(jmp_asm[p->instruction]);
		kjmp(line);
	l_global:
		//printf("debug: l_global\n");
		line++;
		kjmp(line);
	l_private:
		//elem_aux=dataStack->get(ini_params+line->param);
		//printf("debug: l_private (%s)\n", elem_aux->getName());
		dataStack->push(dataStack->get(ini_params+line->param));
		line++;
		kjmp(line);
	l_attr:
		dataStack->push(checkAndCast<Super>(dataStack->pop())->getProperty(line->param));
		line++;
		kjmp(line);
	l_class:
		cout << "l_class: " << dataStack->getTop() << ":=" << data->getClass(line->param) << "(" << line->param <<")" << endl;
		dataStack->push(data->getClass(line->param));
		line++;
		kjmp(line);
	l_method:
		elem_aux=dataStack->pop();
		//printf("debug: l_method %s %d\n", elem_aux->getName());
		cout << "l_method: " << checkAndCast<Super>(elem_aux)->getName() << " -> (" << line->param << ")"<< checkAndCast<Super>(elem_aux)->getMethod(line->param)->getName() << endl;
		dataStack->push(checkAndCast<Super>(elem_aux)->getMethod(line->param));
		dataStack->push(elem_aux);
		line++;
		kjmp(line);
	l_constant:
		//	elem_aux=search_constant(line->param);
		//printf("debug: l_constant %s\n", elem_aux->getName());
		dataStack->push(data->getConstant(line->param));
		line++;
		kjmp(line);
	i_call:
		//elem_aux=0;
		//printf("debug: i_call%s\n", dataStack->get(dataStack->getTop()-line->param-1)->getName().c_str());
		//cout << "debug: i_call" << dataStack->get(dataStack->getTop()-line->param-1) << endl;
		cout << "debug: i_call" << dataStack->getTop() << "-" << line->param << "-" << 1 << endl;
		Method* m=checkAndCast<Method>(dataStack->get(dataStack->getTop()-line->param-1));
		//cout << m->getName() << endl;
		int newLine=m->call(dataStack);
		line++;
		// If the implementation of call is native or is with C call, it was 0, another case, we need to change context
		if (newLine!=0){
			cout << "debug: i_call ->" << newLine << endl;
			callStack->push(pair<int, ASM_line*>(ini_params, line));
			line=&(this->code[newLine]);
			//line=newLine;
			ini_params=dataStack->getTop()-line->param;
		}
		kjmp(line);
	i_ret:
		printf("debug: i_ret %d\n", dataStack->getTop());
		if (line->param>-1){
			dataStack->set(ini_params-1, dataStack->get(ini_params+line->param));
		} else if (line->param==-1){
			dataStack->set(ini_params-1, dataStack->pop());
		}
		dataStack->reseTop(ini_params);
		if (callStack->getTop()==0)
			return 0;
		// we need to restore context;
		pair<int, ASM_line*> retPair=callStack->pop();
		line=retPair.second;
		ini_params=retPair.first;
		//line=callStack->pop();
		kjmp(line);
	i_pop:
		dataStack->pop();
		line++;
		kjmp(line);
	i_push:
		dataStack->push(0);
		line++;
		kjmp(line);
	i_goto:
		line++;
		kjmp(line);
	i_g_true:
		if (checkAndCast<BooleanObject>(dataStack->pop())->getValue()!=0){
			line=&this->code[line->param];
		} else
			line++;
		kjmp(line);
	i_g_false:
		if (checkAndCast<BooleanObject>(dataStack->pop())->getValue()==0){
			line=&this->code[line->param];
		} else
			line++;
		kjmp(line);
	i_s_attr:
		elem_aux=dataStack->get(ini_params);
		checkAndCast<Super>(elem_aux)->storePropiety(line->param, checkAndCast<SuperObject>(dataStack->pop()));
		line++;
		kjmp(line);
	i_s_private:
		//elem_aux=0;
		//printf("%s\n",elem_aux->getName());
		//elem_aux=dataStack->pop();
		//printf("debug: i_s_private (%s)\n", elem_aux->getName());
		dataStack->set(ini_params+line->param, dataStack->pop());
		line++;
		kjmp(line);
	}
}

