//
//  ofxMethod.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_ofxMethod_h
#define vm_ofxMethod_h

namespace SDK{
	class OfxMethod;
	class OfxConstructor;
}

#include "Super.h"
#include "OfxClass.h"

namespace SDK{
	/**
	 * @class OfxMethod
	 * @brief The object for internal calls in Virtual Machine
     */
	class OfxMethod: public Method{
	protected:
		int lineToCall;
	public:
		/**
		 * @brief Constructor
		 * @param name the name of the objective Fenix Instance
		 * @param line the line that will jump where call this method
    	 */
		OfxMethod(string name, int line): Method(name){
			lineToCall=line;
		}
		virtual ~OfxMethod(){}
		/**
		 * @brief return the line to be call
		 * @return line to jump in the VM call
    	 */
		virtual int call(ofxbytecode::Stack<Stackable*>*){
			return lineToCall;
		}
	};
	
	class OfxConstructor: public OfxMethod{
	private:
		OfxClass* base;
	public:
		OfxConstructor(string name, int line, OfxClass* base): OfxMethod(name, line){this->base=base;}
		~OfxConstructor(){}
		/**
		 * @brief build a new instance, set as the object to call, and call to the object you need
		 * @return line to jump in the VM call
    	 */
		virtual int call(ofxbytecode::Stack<Stackable*>* stack){
			//Accedir a la clase OfxClass i generar nova instancia
			stack->pop();
			stack->push(base->getNewInstance());
			return lineToCall;
		}
	};
}

#endif
