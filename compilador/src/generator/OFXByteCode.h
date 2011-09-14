/*
 *  OFXByteCode.h
 *  compilador
 *
 *  Created by Jaume on 21/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

/****
 * Header
 *	 - ByteCodeID
 *	 - @Program UID
 *	 - @Constants / nºConstants
 *	 - @LlistClasses / nºClasses
 *	 - @ByteCode / nºByteCodeInstractions
 ****
 * Constants 
 *	 - ID=>{BOOLEAN| CHARACTER| INTEGER| FLOAT| STRING}
 *	 - Value => char|char|int|float|{size(value)+string}
 ****
 * ListClasses:
 *	 - UID: int
 *	 - fatherUID: int
 *	 - Native: Boolean 
 *   - (length:int) NameClass: string(length) 
 *	 - propiety
 *			- UID
 *			- name
 *   - Method
 *			- UID
 *			- @Bytecode_line
 *			- {size(name)+name}
 ****
 * ByteCode
 *	 - ASM_Line[]
 ****/

/****
 *	Call Stack:
 *		|=======================|
 *		|	Call/Return Value	|
 *		|	This				|	< ini_params
 *		|	Argument 1			|
 *		|	Argument n			|
 *		|	Private	1			|	< ini_params+n+1
 *		|	Private m			|
 *		|=======================|
 *		|	Operation zone		|
 */

#ifndef OFXBYTECODE_H
#define OFXBYTECODE_H
namespace OFXByteCode {
	
	typedef struct headerSave{
		int		 ByteCodeVersion;
		int		 uid_programClass;
		long int p_Constants; // Position where found the sections.
		int		 n_Constants;
		long int p_Class;
		int		 n_Class;
		long int p_ByteCode;
		int		 n_ByteCode;
	} t_HeaderSave;
	
	class OFX_JmpQueue;
	class OFXByteCode;
}

#include "../ASM_instructions.h"
#include "../classes/SyntacticElement.h"
#include "OFXClass.h"
#include "OFXConstant.h"
#include <vector>

namespace OFXByteCode {

	using namespace std;

	class OFXJmpQueue{
	private:
		vector<int> qNext;
		vector<int> qTrue;
		vector<int> qFalse;
	protected:
	public:		
		OFXJmpQueue();
		~OFXJmpQueue();
		vector<int> getNext();
		vector<int> getTrue();
		vector<int> getFalse();
		void addNext(int);
		void addTrue(int);
		void addFalse(int);
	};
	
	
	class OFXByteCode{
	private:
		int mainclass;
		vector<ASM_line> bytecode;
		int nextLine;
		vector<OFX_Constant*> lConstants;
		vector<OFX_Class*> lClass;
		vector<string>	bytecodeDebug;
	public:
		OFXByteCode();
		~OFXByteCode();
		int getLine();
		OFXJmpQueue* getJmpQueue();
		void parseQueue(vector<int>, int=-1);
		void addConstant(SyntacticElement*);
		OFX_Class* addClass(SyntacticElement*);
		void setMainClass(SyntacticElement*);
		
		void write(FILE*, int);
		
		int addInstruction(ASMBytecode, int, string);
	};

}
#endif
/*
class OFXAsm{
	vector<ASM_Line> code;
}

class OFXHeader{
	vector<OFXConstant> list_constants;
	vector<OFXClass> list_class;
}

class OFXByteCode {
	OFXHeader*	head;
	OFXAsm*		code;
}*/