//
//  ofxClass.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_ofxClass_h
#define vm_ofxClass_h

namespace SDK{
	class OfxClass;
	class OfxObject;
}

#include "SuperClass.h"
#include "SuperObject.h"

namespace SDK{
	
	/**
	 * @class OfxClass
	 * @brief Class that contains an objective Fenix class
     */
	class OfxClass: public SuperClass{
	private:
		SuperClass* parent;
	public:
		OfxClass(std::string, SuperClass*);
		~OfxClass();
		
		/**
		 * @brief get a New instance of this objective Fenix class
		 * @return an instance of OfxObject that represents an instance of the Obj-Fenix class
    	 */
		OfxObject* getNewInstance();
	};
	
	/**
	 * @class OfxObject
	 * @brief Representation of an Ofx Instance. It has the link to parent object
	 *
     */
	class OfxObject: public SuperObject{
	private:
		SuperObject* parent;
	public:
		OfxObject(std::string, Super*);
		~OfxObject();
	};
}


#endif
