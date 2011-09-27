//
//  BIMethod.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_BIMethod_h
#define vm_BIMethod_h

namespace SDK{

	class BIMethod;
	class BICall;
}

#include "Super.h"


namespace SDK{
	template<class Template>
	class BIMethod: public Method{
	private:
		void (Template::*method)(BICall*);
		//string name;
		int nArguments;
	public:
		BIMethod(string name, int arguments, void (Template::*method)(BICall*)): Method(name){
			//this->name=name;
			this->nArguments=arguments;
			this->method=method;
		}
		~BIMethod(){};
		virtual int call(Stack<Stackable>* stack){
			(checkAndCast<Template>(stack->get(stack->getTop()-nArguments))->*method)(new BICall(this->getName, stack, nArguments));
			return 0;
		}
	};
	
	
	class BICall{
		int nArguments;
		int baseStack;
		Stack<Stackable>* stack;
		string name;
	public:
		BICall(string name, Stack<Stackable>* stack, int arguments){
			this->name=name;
			this->stack=stack;
			this->nArguments=arguments;
			this->baseStack=stack->getTop()-arguments;
		}
		
		~BICall(){};
		
		template<T>
		T* get(int arg ){
			if (nArguments>=arg && arg>0){
				return checkAndCast(stack->get(baseStack+arg))
			} else {
				return NULL;
			}
		}
		
		void clear(){
			this->stack->reseTop(baseStack-1);
		}
		
		void clearAndSetReturn(Super* retValue){
			this->clear();
			this->stack->set(stack->getTop(), retValue);
		}
	};
}



#endif
