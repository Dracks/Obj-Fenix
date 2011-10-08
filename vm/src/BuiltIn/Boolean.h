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
};

#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"

#include "../tools/Register.h"
#include "../SDK/BIMethod.h"

namespace ofxBI {
	
	class BooleanClass: public SDK::SuperClass {
	private:
		BooleanObject* bTrue;
		BooleanObject* bFalse;
	public:
		BooleanClass();
		~BooleanClass();
		void ofxBoolean(SDK::BICall* call);
		BooleanObject* getNewInstance(bool v);
		
		std::map< std::string, SDK::Method * > getRegisteredMethods();
	};
	
	class BooleanObject: public SDK::Primitive<bool> {
		friend class BooleanClass;
	protected:
		BooleanObject(bool v, SuperObject* base);
	public:
		~BooleanObject();
		void ofxAnd(SDK::BICall* call);
		void ofxOr(SDK::BICall* call);
	};
};


#endif
