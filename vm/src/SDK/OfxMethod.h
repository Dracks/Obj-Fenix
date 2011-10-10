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
		OfxMethod(int type, int line);
	public:
		/**
		 * @brief Constructor
		 * @param name the name of the objective Fenix Instance
		 * @param line the line that will jump where call this method
    	 */
		OfxMethod(std::string name, int line);
		virtual ~OfxMethod();
		/**
		 * @brief return the line to be call
		 * @return line to jump in the VM call
    	 */
		virtual int call(ofxbytecode::Stack<Stackable*>*);
	};
	
	class OfxConstructor: public OfxMethod{
	private:
		OfxClass* base;
	public:
		OfxConstructor(std::string name, int line, OfxClass* base);
		~OfxConstructor();
		/**
		 * @brief build a new instance, set as the object to call, and call to the object you need
		 * @return line to jump in the VM call
    	 */
		virtual int call(ofxbytecode::Stack<Stackable*>* stack);
	};
}

#endif
