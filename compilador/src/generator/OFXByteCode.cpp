/*
 *  OFXByteCode.cpp
 *  compilador
 *
 *  Created by Jaume on 21/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "OFXByteCode.h"
#include "../tools.h"
#include "../debug.h"

using namespace std;

namespace OFXByteCode{
	
	string getInstructionName(ASMBytecode);
	
	//class OFXJmpQueue{
	OFXJmpQueue::OFXJmpQueue(){}
	OFXJmpQueue::~OFXJmpQueue(){};
	vector<int> OFXJmpQueue::getNext(){return qNext;}
	vector<int> OFXJmpQueue::getTrue(){return qTrue;}
	vector<int> OFXJmpQueue::getFalse(){return qFalse;}
	
	void OFXJmpQueue::addNext(int v){
		qNext.push_back(v);
	}
	void OFXJmpQueue::addTrue(int v){
		qTrue.push_back(v);
	}
	void OFXJmpQueue::addFalse(int v){
		qFalse.push_back(v);
	}
	
	
	//class OFXByteCode{
	OFXByteCode::OFXByteCode(){}
	OFXByteCode::~OFXByteCode(){}
	int OFXByteCode::getLine(){
		return nextLine;
	}
	OFXJmpQueue* OFXByteCode::getJmpQueue(){
		return new OFXJmpQueue();
	}
	void OFXByteCode::parseQueue(vector<int> list, int parseline){
		bytecode_debug("Parsejant instruccions");
		if (parseline==-1)
			parseline=nextLine;
		for (int i=0; i<list.size(); i++){
			bytecode[list[i]].param=parseline;
		}
		
	}
	
	void OFXByteCode::addConstant(SyntacticElement* elem){
		string s="Afegint constant: ";
		s+=elem->getName();
		bytecode_debug(s);
		OFX_Constant* tmp;
		if (elem->getUID()==0){
			elem->setUID(lConstants.size()+1);
			string tipusConstant=elem->getSemantic()->getName();
			if (stricmp("Boolean", tipusConstant)==0){
				tmp=new OFX_Constant_Bool(elem->getUID(), stricmp("True", elem->getName())==0);
				//At this moment, we cannot use the words true or false in the SRC, it cannot be added.
			} else if (stricmp("Character", tipusConstant)==0){
				//At this moment, we don't have the class Character
			} else if (stricmp("Integer", tipusConstant)==0){
				tmp=new OFX_Constant_Int(elem->getUID(),atoi(elem->getName().c_str()));
			} else if (stricmp("Float", tipusConstant)==0){
				//At this moment we don't have the class Float.
			} else if (stricmp("String", tipusConstant)==0){
				tmp=new OFX_Constant_String(elem->getUID(), elem->getName());
			}
			lConstants.push_back(tmp);
		}
	}
	
	OFX_Class* OFXByteCode::addClass(SyntacticElement* elem){
		string s="Afegint Clase: ";
		s+=elem->getName();
		//bytecode_debug(s);
		OFX_Class* obj;
		
		if (elem->getSemantic()!=NULL){
			OFX_Class* parent;
			if ((parent=elem->getSemantic()->getOFXClass())==NULL)
				parent=this->addClass(elem->getSemantic());
			//We start especification with the same methods, and virtual UID.
			obj=parent->child(elem->getUID(), elem->getName(), elem->getNative());			
		} else {
			obj=new OFX_Class(elem->getUID(), 0, elem->getName(), elem->getNative());
		}
		bytecode_debug(s);

		cnode* nod=elem->getPropietyListFrom(3)->getFirst();
		while (nod!=NULL){
			obj->addPropiety((SyntacticElement*)nod->getContents());
			nod=nod->getNext();
		}
			
		nod=elem->getMethodList()->getFirst();
		while (nod!=NULL){
			SyntacticElement* methodName=(SyntacticElement*)nod->getContents();
			cnode* nodImpl=methodName->getMethodList()->getFirst();
			while (nodImpl){
				obj->addMethod((MethodDefinition*) nodImpl->getContents(), this);
				nodImpl=nodImpl->getNext();
			}
			nod=nod->getNext();
		}
		lClass.push_back(obj);
		elem->setOFXClass(obj);
		return obj;
		
	}
	void OFXByteCode::setMainClass(SyntacticElement* elem){
		mainclass=elem->getUID();
	}
	
	int OFXByteCode::addInstruction(ASMBytecode ins, int param, string data){
		string s="ByteCode:";
		s+=convert<int>(nextLine);
		s+="\t";
		s+=getInstructionName(ins);
		s+="\t";
		s+=convert<int>(param);
		bytecode_debug(s);
		//printf("%s\n", s.c_str());
		ASM_line instruction;
		instruction.instruction=ins;
		instruction.param=param;
		bytecode.push_back(instruction);
		bytecodeDebug.push_back(data);
		//bytecode[nextLine]=instruction;
		nextLine++;
	}
	
	void OFXByteCode::write(FILE* objecte, int program_uid){
		long capcalera_offset=0;
		fseek(objecte, 0, SEEK_SET);
		t_HeaderSave headerSave;
		headerSave.ByteCodeVersion=1;
		headerSave.uid_programClass=program_uid;
		headerSave.n_ByteCode=bytecode.size();
		headerSave.n_Class=lClass.size();
		headerSave.n_Constants=lConstants.size();
		string str="Header:\n";
		str+="\tMain Program:\t"; str+=convert<int>(program_uid); str+="\n";
		str+="\tList Constants size:\t";str+=convert<int>(lConstants.size());str+="\n";
		str+="\tList class size:\t";str+=convert<int>(lClass.size());str+="\n";
		str+="\tSize bytecode:\t";str+=convert<int>(bytecode.size());
		asm_bytecode_debug(str);
		fwrite(&headerSave, sizeof(headerSave), 1, objecte);
		
		//printf("LLista de constants: %d\n", lConstants.size());
		//Locate a point to the constants.
		str="Constants:";
		asm_bytecode_debug(str);
		headerSave.p_Constants=ftell(objecte);
		for (int i=0; i<lConstants.size(); i++){
			//printf("constant index: %d\n", i);
			lConstants[i]->write(objecte);
		}
		
		str="Class:";
		asm_bytecode_debug(str);		
		//Locate a point to the Classes
		headerSave.p_Class=ftell(objecte);
		for (int i =0; i<lClass.size(); i++){
			lClass[i]->write(objecte);
		}
		
		str="ByteCode:";
		asm_bytecode_debug(str);
		//Locate a point to the bytecode
		headerSave.p_ByteCode=ftell(objecte);
		for (int i =0; i< bytecode.size(); i++){
			asm_bytecode_debug(i, getInstructionName(bytecode[i].instruction), bytecode[i].param, bytecodeDebug[i]);
			fwrite(&(bytecode[i]),sizeof(ASM_line), 1, objecte);
		}
		fseek(objecte, 0, SEEK_SET);
		fwrite(&headerSave, sizeof(headerSave), 1, objecte);
	}
	
	string getInstructionName(ASMBytecode ins){
		switch (ins){
			case LOAD_GLOBAL:
				return "LOAD_GLOBAL";
				break;
			case LOAD_PRIVATE:
				return "LOAD_PRIVATE";
				break;
			case LOAD_ATTR:
				return "LOAD_ATTR";
				break;
			case LOAD_CLASS:
				return "LOAD_CLASS";
				break;
			case LOAD_METHOD:
				return "LOAD_METHOD";
				break;
			case LOAD_CONSTANT:
				return "LOAD_CONSTANT";
				break;
			case CALL:
				return "CALL";
				break;
			case RET:
				return "RET";
				break;
			case POP_TOP:
				return "POP_TOP";
				break;
			case PUSH_TOP:
				return "PUSH_TOP";
				break;
			case GOTO:
				return "GOTO";
				break;
			case GOTO_TRUE:
				return "GOTO_TRUE";
				break;
			case GOTO_FALSE:
				return "GOTO_FALSE";
				break;
			case STORE_ATTR:
				return "STORE_ATTR";
				break;
			case STORE_PRIVATE:
				return "STORE_PRIVATE";
				break;
				/*case :
				 return "";
				 break;*/
			default:
				return "SIZE_INSTRUCTIONS";
		}
	}
}