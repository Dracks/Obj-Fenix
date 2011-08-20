/*
 *  SemanticAnalisis.h
 *  compilador
 *
 *  Created by Jaume Singla Valls on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "classes/clist.h"
#include "classes/syntacticElement.h"
namespace SemanticAnalisis {
	
	using namespace std;

	void semanticValidation(clist* objects);
	void validateObject(SyntacticElement* object);
}