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

	template<class Template>
	class BIMethod;
	class BICall;
}

#include "Super.h"
#include "../classes/Stack.h"


namespace SDK{
	/**
	 * @class BIMethod
	 * @brief Class that represents a BuildIn Call in the ofx VM
     */
	template<class Template>
	class BIMethod: public Method{
	private:
		void (Template::*method)(BICall*);
		//string name;
		int nArguments;
	public:
		/**
		 * @brief Constructor
		 * @param name the Name of the method
		 * @param arguments number of arguments in this method call
		 * @param method function to call in the buildIn
    	 */
		BIMethod(string name, int arguments, void (Template::*method)(BICall*)): Method(name){
			//this->name=name;
			this->nArguments=arguments;
			this->method=method;
		};
		~BIMethod(){};
		
		/**
		 * @brief call the Build in method and return 0
		 * @param stack Stack of call, to obtain the parameters
		 * @return 0, as it is a BICall
    	 */
		virtual int call(ofxbytecode::Stack<Stackable*>* stack){
			int x=stack->getTop()-nArguments;
			Template* obj=checkAndCast<Template>(stack->get(x));
			BICall* c=new BICall(this->getName(), stack, nArguments);
			(obj->*method)(c);
			delete c;
			return 0;
		};
	};
	
	
	/**
	 * @class BICall
	 * @brief Class that represents the call from VM to BI methods, it contains stack, and you can extract parameters and set return value. 
     */
	class BICall{
		int nArguments;
		int baseStack;
		ofxbytecode::Stack<Stackable*>* stack;
		string name;
	public:
		/**
		 * @brief Constructor
		 * @param name the Name of method you call. (for debug)
		 * @param stack The stack from the Virtual Machine
		 * @param arguments Number of arguments of the methods,.
    	 */
		BICall(string name, ofxbytecode::Stack<Stackable*>* stack, int arguments);
		
		~BICall();
		
		/**
		 * @brief get an argument from the call, it checkAndCast argument as the type you specify
		 * @param arg Argument number.
		 * @return argument or null.
    	 */
		template<class T>
		T* get(int arg ){
			if (nArguments>=arg && arg>0){
				return checkAndCast<T>(stack->get(baseStack+arg));
			} else {
				return NULL;
			}
		}
		
		/**
		 * @brief clear the stack from arguments.
    	 */
		void clear();
		
		/**
		 * @brief clear the arguments from stack, and set the return value of the method
		 * @param retValue the value that you wish return to Virtual Machine
    	 */
		void clearAndSetReturn(Super* retValue);
	};
}



#endif
