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
	
	
	/**
	 * @brief The implementation of String class
     */
	class StringClass: public SDK::SuperClass {
	public:
		StringClass();
		~StringClass();
		StringObject* getNewInstance(string v);

		void ofxString(SDK::BICall* call);
		std::map< std::string, SDK::Method * > getRegisteredMethods();
	};
	
	/**
	 * @brief The implementation of String Object
	 */
	class StringObject: public SDK::Primitive<string> {
		friend class StringClass;
	protected:
		StringObject(string v, SDK::ofxMap* base);
	public:
		~StringObject();
		void ofxAdd(SDK::BICall* call);
		//void ofxSub(BICall* call);
		//void ofxEqual(BICall* call);
	};
}

#endif
