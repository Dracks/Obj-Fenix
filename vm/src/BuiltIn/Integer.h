//
//  Integer.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Integer_h
#define vm_Integer_h
namespace ofxBI{
	class IntegerClass;
	class IntegerObject;	
}


#include "../tools/Register.h"
#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"
#include "Boolean.h"

namespace ofxBI {
	
	registerClass(IntegerClass)
	
	class IntegerClass: public SDK::SuperClass {
	public:
		IntegerClass();
		~IntegerClass();
		IntegerObject* ofxInteger(BuiltInCall* call);
		IntegerObject* getNewInstance(int v);
	}
	
	class IntegerObject: public SDK::Primitive<int> {
		friend class IntegerClass;
	protected:
		IntegerObject(int v, SuperObject* base);
	public:
		~IntegerObject();
		IntegerObject* ofxAdd(BICall* call);
		IntegerObject* ofxSub(BICall* call);
		BooleanObject* ofxEqual(BICall* call);
	}
}



#endif
