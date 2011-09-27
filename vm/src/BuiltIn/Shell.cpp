//
//  Shell.cpp
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

namespace ofxBI{
	
	
//	class ShellClass: public SDK::Superclass {
	ShellClass::ShellClass(){}
	
	ShellClass::~ShellClass(){}
	
	void ShellClass::addInstanceMethod(string name , int id, Method* call){
		this->addMethod(name, id, call); 
	}
	
	void ShellClass::addInstanceProperty(string name, int id){
		this->addProperty(name, id)
	}
		
	void ShellClass::ofxShell(BuiltInCall* call){
		call->clearAndSetReturn(this);
		
	}
	
	void ShellClass::ofxStdOut(BuiltInCall* call){
		std::cout << call->get<StringObject>(1)->getValue() << std::endl;
		call->clear();
		
	}
	
	void ShellClass::ofxStdErr(BuiltInCall* call){
		std::cerr << call->get<StringObject>(1)->getValue()<< std::endl;
		call->clear();
	}
	
	void ShellClass::ofxStdIn(BuiltInCall* call){
		string input;
		cin >> input;
		call->clearAndReturn(checkAndCast<StringClass>(ofxbytecode::Library::getData()->getClass("String"))->getNewInstance(input));
	}
}