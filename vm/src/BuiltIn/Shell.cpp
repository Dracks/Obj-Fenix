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

ofxtools::RegisterClass<ofxBI::ShellClass> startupShell();

namespace ofxBI{
	using namespace SDK;
	
	//registerClass(ShellClass);
	/*namespace RegistradorDeShellClass { 
		ofxtools::RegisterClass<ShellClass> startup; 
	}*/
	
	//class ShellClass: public SDK::Superclass {
	ShellClass::ShellClass():SuperClass(7) {
		this->setName("Shell");
	}
	
	ShellClass::~ShellClass(){}
	
	void ShellClass::addInstanceMethod(string name , int id, Method* call){
		this->addMethod(name, id, call); 
	}
	
	void ShellClass::addInstanceProperty(string name, int id){
		this->addProperty(name, id);
	}//*/
		
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
	
	std::map< std::string, SDK::Method * > ShellClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();
		ret["Shell(Object)"]=new BIMethod<ShellClass>("Shell(Object)",1,&ShellClass::ofxShell);
		ret["stdout(String)"]=new BIMethod<ShellClass>("stdout(String)",1,&ShellClass::ofxStdOut);
		ret["stderr(String)"]=new BIMethod<ShellClass>("stderr(String)",1,&ShellClass::ofxStdErr);
		ret["stdin"]=new BIMethod<ShellClass>("stdin",0,&ShellClass::ofxStdIn);
		//ret[""]=new BIMethod<>("",,);
		return ret;
	}
}
