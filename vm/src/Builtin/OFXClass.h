/*
 *  OFXClass.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
namespace objfenix {
	class OFXClass;
}

#ifndef OFXCLASS_H
#define OFXCLASS_H

#include "class.h"

namespace objfenix {
	//class 
	class OFXClass: public Class{
	protected:
		vector<OfxMethod*> methodList;
		vector<Stackable*> propietyList;
		set<string, iny> propietyNames;
		
		//Class* m_attr;
		//int* methodLines;
		virtual ~OFXClass();
	public:
		OFXClass();
		virtual addMethod
		bool getNative(){return false;};
		virtual Stackable* getAtr(int i);
		virtual Stackable* getMethod(int i);
		long getID() {return CID;};
	};
	
}

#endif