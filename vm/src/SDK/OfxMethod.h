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

namespace SDK{
	class OfxMethod: public Method{
	protected:
		int lineToCall;
	public:
		OfxMethod(string name, int line): public Method(name){
			lineToCall=line;
		}
		virtual ~OfxMethod(){}
		virtual int call(Stack<Stackable>*){
			return lineToCall;
		}
	};
	
	class OfxConstructor: public Method{
		virtual int call(Stack<Stackable>*){
			//Accedir a la clase OfxClass i generar nova instancia
			return lineToCall
		}
	};
}

#endif
