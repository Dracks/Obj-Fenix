//
//  List.cpp
//  vm
//
//  Created by Dracks on 28/09/12.
//
//

#include "List.h"
#include "Integer.h"

namespace ofxBI {
	using namespace SDK;
	
	registerClass(ListClass)
	
	//class ListClass: public SDK::SuperClass{
	ListClass::ListClass(): SuperClass(6){
		this->setName("List");
	}
	ListClass::~ListClass(){
		
	}
	ListObject* ListClass::getNewInstance(){
		return new ListObject(this);
	}
		
	void ListClass::ofxList(SDK::BICall* call){
		call->clearAndSetReturn(this->getNewInstance());
	}
	
	void ListClass::ofxListObject(SDK::BICall* call){
		call->clearAndSetReturn(call->get<ListObject>(1));
	}
	
	std::map< std::string, SDK::Method * > ListClass::getRegisteredMethods(){
		map< string, Method*> ret=SuperClass::getRegisteredMethods();

		ret["List"]=new BIMethod<ListClass>("List",0,&ListClass::ofxList);
		ret["List(Object)"]=new BIMethod<ListClass>("List(Object)",1,&ListClass::ofxListObject);
//ret["add(String)"]=new BIMethod<StringObject>("add(String)",1,&StringObject::ofxAdd);
		ret["get(Integer)"]=new BIMethod<ListObject>("get(Integer)", 1, &ListObject::ofxGet);
		ret["add(Object)"]=new BIMethod<ListObject>("add(Object)", 1, &ListObject::ofxAdd);
		ret["length"]=new BIMethod<ListObject>("length", 0, &ListObject::ofxLength);
		ret["addFirst(Object)"]=new BIMethod<ListObject>("addFirst(Object)", 1, &ListObject::ofxAddFirst);
		ret["first"]=new BIMethod<ListObject>("first", 0, &ListObject::ofxFirst);
		ret["removeFirst"]=new BIMethod<ListObject>("removeFirst", 0, &ListObject::ofxRemoveFirst);
		ret["last"]=new BIMethod<ListObject>("last", 0, &ListObject::ofxLast);
		ret["pop"]=new BIMethod<ListObject>("pop", 0, &ListObject::ofxPop);
		
		return ret;
	}

	
	//class ListObject: public SDK::Primitive<vector<SDK::SuperObject*> >{

	ListObject::ListObject(ListClass* ci):Primitive<vector<SuperObject*> >(vector<SuperObject*>(0, NULL), ci->getCache()){
		
	}

	ListObject::~ListObject(){
	}
	
	void ListObject::ofxGet(SDK::BICall* call){
		int element=call->get<IntegerObject>(1)->getValue();
		call->clearAndSetReturn(this->value[element]);
	}
	
	void ListObject::ofxAdd(SDK::BICall* call){
		this->value.push_back(call->get<SuperObject>(1));
		call->clearAndSetReturn(this);
		
	}
	void ListObject::ofxLength(SDK::BICall* call){
		call->clearAndSetReturn(checkAndCast<IntegerClass>(ofxbytecode::Library::getLibrary()->getClass("Integer"))->getNewInstance(this->value.size()));
	}
	void ListObject::ofxAddFirst(SDK::BICall* call){
		this->value.insert(this->value.begin(), call->get<SuperObject>(1));
	}
	void ListObject::ofxFirst(SDK::BICall* call){
		call->clearAndSetReturn(this->value.front());
	}
	void ListObject::ofxRemoveFirst(SDK::BICall* call){
		SuperObject* e=this->value.front();
		this->value.erase(this->value.begin());
		call->clearAndSetReturn(e);
	}
	void ListObject::ofxLast(SDK::BICall* call){
		call->clearAndSetReturn(this->value.back());
	}
	void ListObject::ofxPop(SDK::BICall* call){
		SuperObject* e=this->value.back();
		this->value.pop_back();
		call->clearAndSetReturn(e);
	}

}