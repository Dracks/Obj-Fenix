/*
 *  OFXConstant.cpp
 *  compilador
 *
 *  Created by dracks on 02/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "OFXConstant.h"
#include "../tools.h"
#include "../debug.h"

namespace OFXByteCode{
	//class OFX_Constant{
	
	OFX_Constant::OFX_Constant(int id, char t){
		UID=id;
		type=t;
	}
	void OFX_Constant::write(FILE* object){
		string str="\t\ttype:\t";str+=convert<int>(this->type);str+="\n";
		str+="\t\tUID:";str+=convert<int>(this->UID);
		asm_bytecode_debug(str);
		//printf("write constant %d tipus %d \n", UID, type);
		//First save the ID, and next the type of the constant
		fwrite(&type, sizeof(char), 1, object);
		fwrite(&UID, sizeof(int), 1, object);
	}
	
	//class OFX_Constant_Bool: public OFX_Constant{
	OFX_Constant_Bool::OFX_Constant_Bool(int id, char v):OFX_Constant(id, 1){
		this->value=v;
	}
	void OFX_Constant_Bool::write(FILE* object){
		OFX_Constant::write(object);
		string str="\t\tBoolean:\t";str+=convert<int>(this->value);
		asm_bytecode_debug(str);
		fwrite(&value, sizeof(char), 1, object);
	}
	
	//class OFX_Constant_Char: public OFX_Constant{
	OFX_Constant_Char::OFX_Constant_Char(int id, char v): OFX_Constant(id, 2){
		this->value=v;
	}
	void OFX_Constant_Char::write(FILE* object){
		OFX_Constant::write(object);
		string str="\t\tchar:\t";str+=this->value;
		asm_bytecode_debug(str);
		fwrite(&value, sizeof(char), 1, object);
	}
	
//	class OFX_Constant_Int: public OFX_Constant{
	OFX_Constant_Int::OFX_Constant_Int(int id, int v):OFX_Constant(id, 3){
		this->value=v;
	}
	void OFX_Constant_Int::write(FILE* object){
		OFX_Constant::write(object);
		string str="\t\tInteger:\t";str+=convert<int>(this->value);
		asm_bytecode_debug(str);
		fwrite(&value, sizeof(int), 1, object);
	}
	
//	class OFX_Constant_Float: public OFX_Constant{
	OFX_Constant_Float::OFX_Constant_Float(int id, float v): OFX_Constant(id, 4){
		this->value=v;
	}
	void OFX_Constant_Float::write(FILE* object){
		OFX_Constant::write(object);
		string str="\t\tFloat:\t";str+=convert<float>(this->value);
		asm_bytecode_debug(str);
		fwrite(&value, sizeof(float), 1, object);
	}
	
//	class OFX_Constant_String: public OFX_Constant{
	OFX_Constant_String::OFX_Constant_String(int id, string v): OFX_Constant(id, 5){
		this->value=v;
	}
	void OFX_Constant_String::write(FILE* object){
		OFX_Constant::write(object);
		string str="\t\tString:\t(";str+=convert<int>(this->value.length());str+=")";str+=value;
		asm_bytecode_debug(str);
		//printf("\tconstant string: %s\n", value.c_str());
		//We need to save the size of the string.
		int size=value.length()+1;
		fwrite(&size, sizeof(int), 1, object);
		fwrite(value.c_str(), sizeof(char), size, object);
	}
	
}