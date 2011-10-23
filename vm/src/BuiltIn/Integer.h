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
	
	
	
	class IntegerClass: public SDK::SuperClass {
		IntegerObject* cache;
	public:
		IntegerClass();
		~IntegerClass();
		void ofxInteger(SDK::BICall* call);
		IntegerObject* getNewInstance(int v);
		
		std::map< std::string, SDK::Method * > getRegisteredMethods();
	};
	
	class IntegerObject: public SDK::Primitive<int> {
		friend class IntegerClass;
	protected:
		IntegerObject(int v, SDK::ofxMap* base);
	public:
		~IntegerObject();
		void ofxInc(SDK::BICall* call);
		void ofxDec(SDK::BICall* call);
		void ofxAdd(SDK::BICall* call);
		void ofxSub(SDK::BICall* call);
		void ofxEqual(SDK::BICall* call);
		void ofxLower(SDK::BICall* call);
		void ofxToString(SDK::BICall* call);
	};
}



#endif
