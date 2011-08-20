/*
 *  OFXClass.h
 *  compilador
 *
 *  Created by dracks on 02/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
namespace OFXByteCode {
	class OFX_Class;
}
#ifndef OFXCLASS_H
#define OFXCLASS_H
//#include "../ASM_instructions.h"
#include "OFXByteCode.h"
#include <iostream>
#include <vector>
#include "../classes/SyntacticElement.h"
using namespace std;

namespace OFXByteCode {
	
	class OFX_ClassMethod{
	private:
		int UID; // The real UID
		string name;
		int line; //bytecode line to run this method.
		char constructor;
	public:
		int getUID();
		OFX_ClassMethod(int, string,char, int);
		void write(FILE*);
	};
	
	class OFX_ClassPropiety{
	private:
		int UID; // The real UID of the propiety
		string name; // The Propiety Name
	public:
		int getUID();
		OFX_ClassPropiety(int, string);
		void write(FILE*);
	};
	
	class OFX_Class{
	private:
		bool native;
		int UID;
		string name;
		
		vector<OFX_ClassMethod*> lMethods; //virtual(UID), Method implementation.
		vector<OFX_ClassPropiety*> lPropieties; //virtual(UID), Propiety specification.
	protected:
	public:
		OFX_Class(int, string, bool);
		void write(FILE*);
		int getUID();
		void addPropiety(SyntacticElement*);
		void addMethod(MethodDefinition*, OFXByteCode* );
		OFX_Class* clone(int, string, bool);
	};

}
#endif