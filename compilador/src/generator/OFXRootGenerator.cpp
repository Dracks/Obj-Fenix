/*
 *  OFXRootGenerator.cpp
 *  compilador
 *
 *  Created by dracks on 01/05/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "OFXRootGenerator.h"
#include "../debug.h"
#include "OFXByteCode.h"
#include "../main.h"

namespace OFXByteCode{
	
	void buildByteCode(clist* listObjects, int uid_main, FILE* binary){
		bytecode_debug("Generant bytecode");
		OFXByteCode* bytecodeGenerator=new OFXByteCode();
		cnode* aux=listObjects->getFirst();
		while (aux!=NULL) {
			bytecodeGenerator->addClass((SyntacticElement*) aux->getContents());
			aux=aux->getNext();
		}
		bytecodeGenerator->write(binary, uid_main);
	}
	
}