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
};

//#include "../ASM_instructions.h"
//#include "../classes/Thread.h"
//#include "../classes/Stack.h"
//#include "Method.h"
//#include "Class.h"

#include <string>

#ifndef STACKABLE_H
#define STACKABLE_H


namespace SDK{
	
	/**
	 * @fn template <class T> inline T* checkAndCast(Stackable* obj)
	 * @param obj the object to cast
	 * @return Template <class T>
	 * @brief Check If an object can be casted and casted if true, if it is false, (future) throws exception
	 */
	template <class T>
	inline T* checkAndCast(Stackable* obj) {
		//T* obj=dynamic_cast<T*>(obj);
		return dynamic_cast<T*>(obj);
		//return (T*) obj;
	};
	
	
	/**
	 * @class Stackable
	 * @brief Is the class package for the Virtual Machine Stack
	 */
	class Stackable{
	private:
		std::string ofxName;
		std::string name;
		int type;
	protected:
		/**
		 * @param p_name the name of the object (Integer, Boolean, String...)
		 * @param type the type of the object (The UID, identified in the bytecode)
		 */
		//Stackable(std::string p_name, int type);
		Stackable(int type);
		
		virtual ~Stackable();
		
		virtual void setName(std::string name);
	public:
		//virtual bool getNative()=0;
		/**
		 * @return integer
		 * @brief get the integuer type of the stackable object
		 */
		int getType();
		
		/**
		 * @return string
		 * @brief get the name of the stackable object
		 */
		std::string getName();
/*		virtual Class* getAtr(int i)=0;
		virtual void setAtr(int i, Class* atr)=0;
		virtual Method* getMethod(int i)=0;
		//virtual void call(Pila* p, ASM_line* code, int params)=0;
		virtual int call(ofxbytecode::Stack<Stackable*>*, ASM_line*, int)=0;*/
	};
};

#endif