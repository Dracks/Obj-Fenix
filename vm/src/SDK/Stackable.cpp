/*
 *  Stackable.cpp
 *  vm
 *
 *  Created by Jaume Singla Valls on 06/04/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Stackable.h"

namespace objfenix{
	
	//class Stackable{
	
	Stackable::Stackable(string p_name, int type){name=p_name, int type};
	Stackable::~Stackable(){};
		//virtual bool getNative()=0;
	int Stackable::getType(){return type;};
	string Stackable::getName(){return name;};
}