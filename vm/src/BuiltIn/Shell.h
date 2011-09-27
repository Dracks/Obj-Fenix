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
	
	RegisterClass(ShellClass)
	
	class ShellClass: public SDK::Superclass {
	public:
		ShellClass();
		~ShellClass();
		//StringObject* getNewInstance();
		
		inline void addInstanceMethod(string, int, Method*);
		inline void addInstanceProperty(string, int);
		
		inline void ofxShell(BuiltInCall* call);
		inline void ofxStdOut(BuiltInCall* call);
		inline void ofxStdErr(BuiltInCall* call);
		inline void ofxStdIn(BuiltInCall* call);
	};
}

#endif
