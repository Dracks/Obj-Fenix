//
//  BIMethod.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_BIMethod_h
#define vm_BIMethod_h

class BIMethod;
class BICall;

#include "Super.h"

template<class Template>
class BIMethod: public Method{
private:
	void (Template::*method)(BICall*);
	string name;
	int nArguments;
public:
	BIMethod(string name, int arguments, void (Template::*method)(BICall*)){
		this->name=name;
		this->nArguments=arguments;
		this->method=method;
	}
	virtual int call(Stack<Stackable>* stack){
		(checkAndCast<Template>(stack->get(stack->getTop()-nArguments))->*method)(new BICall(name, stack, nArguments));
		
		return 0;
	}
}


class BICall{
	int nArguments;
	int baseStack;
	Stack<Stackable>* stack;
	string name=name;
public:
	BICall(string name, Stack<Stackable>* stack, int arguments){
		this->name=name;
		this->stack=stack;
		this->nArguments=arguments;
		this->baseStack=stack->getTop()-arguments;
	}
	
	template<T>
	T* getParam(int arg ){
		if (nArguments>=arg && arg>0){
			return checkAndCast(stack->get(baseStack+arg))
		} else {
			return NULL;
		}
	}
	
	void clear(){
		
	}
	
	void clearAndSetReturn(Super* retValue){
		this->clear();
		this->stack->
	}
}



#endif
