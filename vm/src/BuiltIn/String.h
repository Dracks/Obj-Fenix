//
//  String.h
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_String_h
#define vm_String_h

namespace ofxBI{
	class StringClass;
	class StringObject;	
}


#include "../tools/Register.h"
#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"
#include "Boolean.h"

namespace ofxBI {
	
	RegisterClass(IntegerClass)
	
	class StringClass: public SDK::SuperClass {
	public:
		StringClass();
		~StringClass();
		StringObject* getNewInstance(string v);

		void ofxString(BuiltInCall* call);
	};
	
	class StringObject: public SDK::Primitive<string> {
		friend class IntegerClass;
	protected:
		StringObject(int v, SuperObject* base);
	public:
		~StringObject();
		void ofxAdd(BICall* call);
		//void ofxSub(BICall* call);
		//void ofxEqual(BICall* call);
	};
}

#endif
