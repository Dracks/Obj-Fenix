//
//  Shell.h
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_Shell_h
#define vm_Shell_h

namespace ofxBI{
	class ShellClass;
	//class StringObject;	
}

#include "../tools/Register.h"
#include "../SDK/SuperClass.h"
#include "../SDK/SuperObject.h"
#include "Boolean.h"

namespace ofxBI{
	
	
	
	class ShellClass: public SDK::SuperClass {
	public:
		ShellClass();
		~ShellClass();
		//StringObject* getNewInstance();
		
		void addInstanceMethod(string, int, SDK::Method*);
		void addInstanceProperty(string, int);
		
		void ofxShell(SDK::BICall* call);
		void ofxStdOut(SDK::BICall* call);
		void ofxStdErr(SDK::BICall* call);
		void ofxStdIn(SDK::BICall* call);
		
		std::map< std::string, SDK::Method * > getRegisteredMethods();
	};
}

#endif
