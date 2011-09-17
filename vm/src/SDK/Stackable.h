/*
 *  Stackable.h
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

namespace SDK {
	class Stackable;
}

#include "../ASM_instructions.h"
#include "../classes/Thread.h"
#include "../classes/Stack.h"
#include "Method.h"
#include "Class.h"

#include <string>

#ifndef STACKABLE_H
#define STACKABLE_H


namespace SDK{
	
	template <class T>
	inline T* checkAndCast(Stackable* obj) {
		//T* obj=dynamic_cast<T*>(obj);
		return dynamic_cast<T*>(obj);
	}
	
	class Stackable{
	private:
		std::string name;
		int type;
	protected:
		Stackable(std::string p_name, int type);
		virtual ~Stackable();
	public:
		//virtual bool getNative()=0;
		inline int getType();
		inline std::string getName();
/*		virtual Class* getAtr(int i)=0;
		virtual void setAtr(int i, Class* atr)=0;
		virtual Method* getMethod(int i)=0;
		//virtual void call(Pila* p, ASM_line* code, int params)=0;
		virtual int call(ofxbytecode::Stack<Stackable*>*, ASM_line*, int)=0;*/
	};
}

#endif