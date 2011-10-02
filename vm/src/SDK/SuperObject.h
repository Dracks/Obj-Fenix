//
//  SuperObject.h
//  vm
//
//  Created by Dracks on 15/09/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef vm_SuperObject_h
#define vm_SuperObject_h


namespace SDK{
	class SuperObject;
	template <class T>
	class Primitive;
};

#include "Super.h"

namespace SDK{
	/**
	 * @class SuperObject
	 * @brief The class base of all Instances in the objective Fenix.
     */
	class SuperObject: public Super{
	public:
		/**
		 * @brief Constructor
		 * @param name the Name of the object
		 * @param obj the base for build the new instance
    	 */
		SuperObject(std::string name, Super* obj):Super(name){};
		~SuperObject(){};
	};
	
	/**
	 * @class Primitive
	 * @brief Is a template class for the base of all primitive BuiltIn Instances in the OFX
     */
	template<class Template>
	class Primitive: public SuperObject{
	protected: 
		Template value;
		/**
		 * @brief Primitive
		 * @param v the value primitive of the object
		 * @param base the Base for call and construct SuperObject
    	 */
		Primitive(Template v, SuperObject* base): SuperObject(base->getName(), base){
			value=v;
		}
	public:
		/**
		 * @brief get the primitive value that it save
		 * @return the value
    	 */
		inline Template getValue(){
			return value;
		}
	};
};

#endif
