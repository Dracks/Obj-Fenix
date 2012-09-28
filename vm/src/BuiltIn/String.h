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
	/*
	 def add (e:String) return String;
	 def sufix (p:Integer) return String;
	 def prefix (p:Integer) return String;
	 def substring (ini:Integer, end:Integer) return String;
	 def length return Integer;
	 def split(e:String) return List;
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
	private:
		StringClass* classInstance;
	protected:
		StringObject(StringClass* ci, string v);
	public:
		~StringObject();
		void ofxAdd(SDK::BICall* call);
		void ofxPrefix(SDK::BICall* call);
		void ofxSufix(SDK::BICall* call);
		void ofxSubstring(SDK::BICall* call);
		void ofxLength(SDK::BICall* call);

		//void ofxSub(BICall* call);
		//void ofxEqual(BICall* call);
	};
}

#endif
