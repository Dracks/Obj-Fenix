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
	
	registerClass(ShellClass)
	
	class ShellClass: public SDK::SuperClass {
	public:
		ShellClass();
		~ShellClass();
		//StringObject* getNewInstance();
		
		inline void addInstanceMethod(string, int, SDK::Method*);
		inline void addInstanceProperty(string, int);
		
		inline void ofxShell(SDK::BICall* call);
		inline void ofxStdOut(SDK::BICall* call);
		inline void ofxStdErr(SDK::BICall* call);
		inline void ofxStdIn(SDK::BICall* call);
	};
}

#endif
