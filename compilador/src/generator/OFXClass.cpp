/*
 *  OFXClass.cpp
 *  compilador
 *
 *  Created by dracks on 02/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "OFXClass.h"
#include "../treeCode/Base.h"
#include "../debug.h"
#include "../tools.h"


namespace OFXByteCode {
	using namespace std;	
	//class OFX_ClassMethod{
	OFX_ClassMethod::OFX_ClassMethod(int uid, string name,char constructor, char isStatic, int line){
		this->UID=uid;
		this->name=name;
		this->line=line;
		this->constructor=constructor;
		this->isStatic=isStatic;
	}
	int OFX_ClassMethod::getUID(){
		return UID;
	}
	void OFX_ClassMethod::write(FILE* obj){
		string str="\t\tUID:\t"; str+=convert<int>(this->UID);str+="\n";
		str+="\t\tByteCodeLine:\t";str+=convert<int>(this->line);str+="\n";
		str+="\t\tConstructor:\t";str+=convert<int>(this->constructor);str+="\n";
		str+="\t\tstatic?:\t";str+=convert<bool>(this->isStatic);str+="\n";
		str+="\t\tName:\t(";str+=convert<int>(this->name.size());str+=")";str+=this->name;;
		asm_bytecode_debug(str);
		fwrite(&this->UID,sizeof(int),1,obj);
		fwrite(&this->line, sizeof(int),1,obj);
		fwrite(&this->constructor, sizeof(char),1,obj);
		fwrite(&this->isStatic, sizeof(char),1,obj);
		int size=this->name.length()+1;
		fwrite(&size,sizeof(int),1,obj);
		fwrite(this->name.c_str(),sizeof(char),size,obj);
	}
	
	//class OFX_ClassPropiety{
	OFX_ClassPropiety::OFX_ClassPropiety(int uid, string name){
		this->UID=uid;
		this->name=name;
	}
	
	int OFX_ClassPropiety::getUID(){
		return UID;
	}
	void OFX_ClassPropiety::write(FILE* obj){
		string str="\t\tUID:\t"; str+=convert<int>(this->UID);str+="\n";
		str+="\t\tName:\t (";str+=convert<int>(this->name.size());str+=")";str+=this->name;
		asm_bytecode_debug(str);
		
		fwrite(&this->UID,sizeof(int),1,obj);
		int size=this->name.length()+1;
		fwrite(&size,sizeof(int),1,obj);
		fwrite(this->name.c_str(),sizeof(char),size,obj);
	}
	
	//class OFX_Class{
	OFX_Class::OFX_Class(int uid, int father, string name, bool native){
		this->UID=uid;
		this->fatherUID=father;
		this->name=name;
		this->native=native;
	}
	void OFX_Class::write(FILE* obj){
		string str="\tUID:\t";str+=convert<int>(this->UID);str+="\n";
		str+="\tFatherUID:\t";str+=convert<int>(this->fatherUID);str+="\n";
		str+="\tnative?:\t";str+=convert<bool>(this->native);str+="\n";
		str+="\tname:\t(";str+=convert<int>(this->name.length()+1);str+=")";str+=this->name;
		asm_bytecode_debug(str);
		
		fwrite(&this->UID, sizeof(int), 1, obj);
		fwrite(&this->fatherUID, sizeof(int), 1, obj);
		fwrite(&this->native, sizeof(char),1,obj);
		int size=this->name.length()+1;
		fwrite(&size, sizeof(int), 1, obj);
		fwrite(this->name.c_str(), sizeof(char), size, obj);
		
		str="\tPropieties (";str+=convert<int>(lPropieties.size());str+="):";
		asm_bytecode_debug(str);
		//Save the number of propieties and methods in the class.
		int count=lPropieties.size();
		fwrite(&count, sizeof(int), 1, obj);
		for (int i=0; i<count; i++){
			lPropieties[i]->write(obj);
		}
		count=lMethods.size();
		fwrite(&count, sizeof(int), 1, obj);
		str="\tMethods (";str+=convert<int>(lMethods.size());str+="):";
		asm_bytecode_debug(str);
		for (int i=0; i<count; i++){
			lMethods[i]->write(obj);
		}//*/
	}
	
	int OFX_Class::getUID(){
		return UID;
	}
	
	void OFX_Class::addPropiety(SyntacticElement* elem){
		OFX_ClassPropiety* tmp=new OFX_ClassPropiety(elem->getUID(), elem->getName());
		lPropieties.push_back(tmp);
	}
	
	void OFX_Class::addMethod(MethodDefinition* elem, OFXByteCode* bytecode){
		string s="\tAfegim metode:";
		s+=elem->getName();
		bytecode_debug(s);
		//printf("%s\n",s.c_str());
		OFX_ClassMethod* tmp=new OFX_ClassMethod(elem->getUID(), elem->getName(), elem->isConstructor(), elem->getStatic(), bytecode->getLine());
		// Put this in the virtual Table
		int tst=elem->getUID();
		for (int i=0; i<lMethods.size(); i++){
			if (lMethods[i]->getUID()==tst){
				lMethods[i]=tmp;
				tmp=NULL;
				i=lMethods.size();
			}
		}
		if (tmp!=NULL){
			lMethods.push_back(tmp);
		}
		
		if (!this->native){
			//Set the UID for the arguments;
			int countVars=1;
			cnode* aux=elem->getParams()->getFirst();
			while (aux!=NULL){
				((SyntacticElement*) aux->getContents())->setUID(countVars);
				countVars++;
				aux=aux->getNext();
			}
			
			// We need to create the positions of the diferents private vars;
			aux=elem->getPrivate()->getFirst();
			while (aux!=NULL){
				((SyntacticElement*) aux->getContents())->setUID(countVars);
				bytecode->addInstruction(PUSH_TOP,0, "(reservant:"+((SyntacticElement*) aux->getContents())->getName()+")"); //In this case we need to save the position of the variable in the stack
				countVars++;
				aux=aux->getNext();
			}
			
			OFXJmpQueue* next;
			aux=elem->getCode()->getFirst();
			while (aux!=NULL){
				next=((Base*) aux->getContents())->ofxGenerate(bytecode);
				bytecode->parseQueue(next->getNext());
				aux=aux->getNext();
			}
			bytecode->addInstruction(RET,-1, ""); // we ever need a return
			bytecode->addInstruction(SIZE_INSTRUCTIONS, elem->getUID(), "");
		}
	}
	
	OFX_Class* OFX_Class::child(int uid, string name, bool native){
		//printf("Cloning class: %s to %s\n", this->name.c_str(), name.c_str());
		OFX_Class* ret=new OFX_Class(uid, this->UID, name, native);
		
		return ret;
	}	
}