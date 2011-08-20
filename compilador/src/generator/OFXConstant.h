/*
 *  OFXConstant.h
 *  compilador
 *
 *  Created by dracks on 02/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

//#include "../ASM_instructions.h"
#ifndef OFXCONSTANT_H
#define OFXCONSTANT_H

#include <vector>
#include <iostream>

using namespace std;

namespace OFXByteCode{
	class OFX_Constant{
	private:
		char type;
	protected:
		int UID;
	public:
		OFX_Constant(int, char);
		virtual void write(FILE*);
	};
	
	class OFX_Constant_Bool: public OFX_Constant{
	private:
		char value;
	public:
		OFX_Constant_Bool(int, char);
		void write(FILE*);
	};
	
	class OFX_Constant_Char: public OFX_Constant{
	private:
		char value;
	public:
		OFX_Constant_Char(int, char);
		void write(FILE*);
	};
	
	class OFX_Constant_Int: public OFX_Constant{
	private:
		int value;
	public:
		OFX_Constant_Int(int, int);
		void write(FILE*);
	};
	
	class OFX_Constant_Float: public OFX_Constant{
	private:
		float value;
	public:
		OFX_Constant_Float(int, float);
		void write(FILE*);
	};
	
	class OFX_Constant_String: public OFX_Constant{
	private:
		string value;
	public:
		OFX_Constant_String(int, string);
		void write(FILE*);
	};
}
#endif