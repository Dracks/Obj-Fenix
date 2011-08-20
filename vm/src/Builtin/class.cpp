/*
 * vm
 * Copyright (C) Fernando Arroba Rubio 2011 <gnotxor@gmail.com>
 *
 * vm is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * vm is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "class.h"

#include <stdio.h>
namespace objfenix {
		
	//class Class: public Stackable {
	Class::Class(int CID){
		this->CID=CID;
		name="Class";
	}

	Class::~Class() {
		// destructor
	}
	
	Method* Class::getMethod(int e ){
		return methodList[e];
	}
	Class* Class::getAtr(int e ){
		return propietyList[e];
	}
	
	Method* Class::getMethod(string e ){
		return methodList[methodNames[e]];
	}
	Class* Class::getAtr(string e ){
		return propietyList[propietyNames[e]];
	}
	
	long Class::getID() {return CID;};
	
	void Class::setAtr(int i, Class* atr){
		propietyList[i]=(Class*) atr;
	}
	
	void Class::setAtr(string name, Class* atr){
		propietyList[propietyNames[name]]= atr;
	}
	
	void Class::setMethod(int uid, string name, Method* m){
		methodList[uid]=m;
		methodNames[name]=uid;
	};

	
	//class BuiltInClass: public Class{
	
		//virtual void setMethod(string, int bytecodeUID)=0;
	//}
	
	//class OFXClass: public Class{
	Class* BuiltInClass::getInstance(BuiltInClass* ret){
		
		//ret->methodTrans=this->methodTrans;
		ret->methodList=this->methodList;
		//ret->propietyTrans=this->propietyTrans;
		ret->propietyList=this->propietyList;
		ret->propietyNames=this->propietyNames;
		ret->methodNames=this->methodNames;
		return ret;
	}
	
	OFXClass::~OFXClass(){}
	OFXClass::OFXClass(int cid):Class(cid){
		name="OFXClass";
	}
	
	OFXMethod* OFXClass::addMethod(string name, int UID, char constructor, int line){
		methodNames[name]=UID;
		methodList[UID]=new OFXMethod(constructor, line);
	}
	
	void OFXClass::addAttribute(string name, int UID, int line){
		propietyList[UID]=NULL;
		propietyNames[name]=UID;
	}
		//bool getNative(){return false;};
	/*Method* OFXClass::getMethod(int i){
		return this->methodList[i];
	}*/
	
	Class* OFXClass::getInstance(){
		OFXInstance* ret=new OFXInstance(this->CID);
		ret->methodList=this->methodList;
		ret->propietyList=this->propietyList;
		ret->propietyNames=this->propietyNames;
		ret->methodNames=this->methodNames;
		return ret;
	}

	
	//class OFXInstance: public OFXClass{
	
	OFXInstance::~OFXInstance(){}
	
	OFXInstance::OFXInstance(int cid):OFXClass(cid){
		name="OFXInstance";
	}
}

