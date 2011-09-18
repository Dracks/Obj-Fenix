//
//  Boolean.h
//  vm
//
//  Created by Dracks on 18/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Boolean_h
#define vm_Boolean_h

namespace ofxBI{
	class BooleanClass;
	class BooleanObject;	
}


#include "../tools/Register.h"
#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"

namespace ofxBI {
	
	registerClass(BooleanClass)
	
	class BooleanClass: public SDK::SuperClass {
	public:
		BooleanClass();
		~BooleanClass();
		BooleanClass* ofxBoolean(BuiltInCall* call);
		BooleanClass* getNewInstance(int v);
	}
	
	class BooleanObject: public SDK::Primitive<bool> {
		friend class BooleanClass;
	protected:
		BooleanObject(bool v, SuperObject* base);
	public:
		~BooleanObject();
		IntegerObject* ofxAnd(BICall* call);
		IntegerObject* ofxOr(BICall* call);
	}
}


#endif
