//
//  Shell.cpp
//  vm
//
//  Created by Dracks on 25/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>

#include "Shell.h"
#include "String.h"

namespace ofxBI{
	using namespace SDK;
	
//	class ShellClass: public SDK::Superclass {
	ShellClass::ShellClass():SuperClass("Shell") {}
	
	ShellClass::~ShellClass(){}
	
	void ShellClass::addInstanceMethod(string name , int id, Method* call){
		this->addMethod(name, id, call); 
	}
	
	void ShellClass::addInstanceProperty(string name, int id){
		this->addProperty(name, id);
	}
		
	void ShellClass::ofxShell(BICall* call){
		call->clearAndSetReturn(this);
		
	}
	
	void ShellClass::ofxStdOut(BICall* call){
		std::cout << call->get<StringObject>(1)->getValue() << std::endl;
		call->clear();
		
	}
	
	void ShellClass::ofxStdErr(BICall* call){
		std::cerr << call->get<StringObject>(1)->getValue()<< std::endl;
		call->clear();
	}
	
	void ShellClass::ofxStdIn(BICall* call){
		string input;
		cin >> input;
		call->clearAndSetReturn(checkAndCast<StringClass>(ofxbytecode::Library::getLibrary()->getClass("String"))->getNewInstance(input));
	}
}