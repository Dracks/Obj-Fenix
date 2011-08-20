/*
 *  Expresion.cpp
 *  compilador
 *
 *  Created by Jaume Singla Valls on 03/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "../debug.h"
#include "../tools.h"
#include "../../build/syntactic_parser.h"

#include "Expresion.h"

extern int num_line;

void AbstractExpresion::setParent(SyntacticElement*p){
	parent=p;
};

Subpropiety::Subpropiety(SyntacticElement* elem_, int line_):AbstractExpresion(elem_, line_){
	//printf("elem_: %s \n", this->elem->getName().c_str());
	methodUID=-1; //we don't have method
	subElement=NULL;
	//elem=elem_;
}

void AbstractExpresion::getName(string &name){
	name.append(this->elem->getName());
}

OFXByteCode::OFXJmpQueue* AbstractExpresion::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue* ret=Base::ofxGenerate(obj);
	this->ofxGenerateLoad(obj);
	obj->addInstruction(POP_TOP,0, "");
	return ret;
}

void AbstractExpresion::ofxGenerateLoad(OFXByteCode::OFXByteCode* obj){
	this->createInstruction(obj);
}

ASM_line AbstractExpresion::ofxGenerateReplace(OFXByteCode::OFXByteCode* obj){
	ASM_line tmp;
	tmp.instruction=SIZE_INSTRUCTIONS;
	tmp.param=0;
	return tmp;
}

void AbstractExpresion::createInstruction(OFXByteCode::OFXByteCode* obj){
	int count=0;
	OFXByteCode::OFXJmpQueue* tmp;
	switch (this->elem->getSyntactic()) {
		case 1:
			//printf("Load Class: %s\n", this->elem->getName().c_str());
			obj->addInstruction(LOAD_CLASS, this->elem->getUID(), "("+this->elem->getName()+")");
			break;
		case 2:
			//printf("Load Method: %s \n", this->elem->getName().c_str());
			//printf("Debug2 %s\n", this->methodCache->getName().c_str());
			if (parent!=NULL){
				obj->addInstruction(LOAD_PRIVATE,0, "(this)");
			}
			obj->addInstruction(LOAD_METHOD, this->methodCache->getUID(),"("+this->methodCache->getName()+")");
			for (int j=0;j<listParametros.size();j++){
				listParametros[j]->ofxGenerateLoad(obj);
				count++;
				//delete tmp; //In this point, we don't have jmpQueue
			}
			obj->addInstruction(CALL, count,"("+this->methodCache->getName()+")");
			break;
		case 3:
			if (parent!=NULL){
				obj->addInstruction(LOAD_PRIVATE,0, "(this)");
			}
			obj->addInstruction(LOAD_ATTR, this->elem->getUID(), "("+this->elem->getName()+")");
			break;
		case 4:
			obj->addInstruction(SIZE_INSTRUCTIONS,-1, "");
			break;
		case 5:
			obj->addInstruction(LOAD_PRIVATE, this->elem->getUID(), "("+this->elem->getName()+")");
			break;
		case 6:
			obj->addConstant(this->elem);
			obj->addInstruction(LOAD_CONSTANT, this->elem->getUID(), "("+this->elem->getName()+")");
			break;
		case 7:
			((AbstractExpresion* ) this->elem->getPackage())->ofxGenerateLoad(obj);
			break;
		default:
			obj->addInstruction(SIZE_INSTRUCTIONS,-2, "");
			break;
	}
}

//class Return: public Base{

Return::Return(AbstractExpresion* ret_, int line_):Base(line_){
	string dbg="";
	ret_->getName(dbg);
	//printf("debug: %s", dbg.c_str());
	ret=ret_;
}
void Return::semantic(){
	int tmp;
	if (m_semantic!=NULL){
		if (ret!=NULL){
			SyntacticElement* sem=ret->getSemantic();
			//Fix-It: Change stricmp to (SyntacticElement*)->tstCastWith
			if (/*stricmp(m_semantic->getName(), sem->getName())!=0*/ 
				!m_semantic->testCastWith(sem, tmp)){
				num_line=this->getLine();
				string s="You cannot cast the type ";
				s+=m_semantic->getName();
				s+="to ";
				s+=sem->getName();
				s+=" for return the value";
				showError((char*) s.c_str());
			}
		} else {
			num_line=this->getLine();
			string s="You cannot use a void return in this function";
			showError(s);
		}
	} else {
		if (ret!=NULL){
			SyntacticElement* sem=ret->getSemantic();
			if (sem!=NULL){
				string s="You cannot return ";
				s+=sem->getName();
				s+=" type value in this function";
				showWarning(s, this->getLine());
			}
		}
	}
}

void Return::setSemantic(SyntacticElement* sem){
	m_semantic=sem;
}

OFXByteCode::OFXJmpQueue* Return::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue* retV=Base::ofxGenerate(obj);
	if (ret!=NULL){
		ret->ofxGenerateLoad(obj);
		obj->addInstruction(RET, 0, ""); 
	} else {
		obj->addInstruction(RET,-1, "");
	}
	return retV;
	
	//return ret;
}
//virtual OFXByteCode::OFXJmpQueue* Return::ofxGenerateReplace(OFXByteCode::OFXByteCode* obj);


void Assignation::semantic(){
	//printf("%d, Validant %s\n",this->getLine(), s.c_str());
	SyntacticElement* reemplacar=dst->getSemantic();
	SyntacticElement* orig=src->getSemantic();
	if (reemplacar!=NULL && orig!=NULL){
		//printf("Igualacio: %s, %s, %d\n",reemplacar->getName(), orig->getName(),stricmp(reemplacar->getName(), orig->getName()));
		int tmp;
		if (/*stricmp(reemplacar->getName(), orig->getName())!=0*/
			!orig->testCastWith(reemplacar, tmp)){
			char* str=(char*) malloc(1024*sizeof(char));
			num_line=this->getLine();
			sprintf(str, "You cannot convert from %s to %s",orig->getName().c_str(),reemplacar->getName().c_str());
			showError(str);
			free(str);
			return;
		}
	}
	//if (reemplacar!=NULL){
//		dst->getName(s);
//		printf("%d, Validant %s\n",this->getLine(), s.c_str());
	string s;
	dst->getName(s);
	if (!dst->verifyVariable()){
		char* str=(char*) malloc(1024*sizeof(char));
		num_line=this->getLine();
		sprintf(str, "You cannot replace value of %s",s.c_str());
		showError(str);
		free(str);
	}
	
	//}
	//printf("end\n");
}

OFXByteCode::OFXJmpQueue* Assignation::ofxGenerate(OFXByteCode::OFXByteCode* obj){
	OFXByteCode::OFXJmpQueue* ret=Base::ofxGenerate(obj);
	ASM_line save=dst->ofxGenerateReplace(obj);
	src->ofxGenerateLoad(obj);
	obj->addInstruction(save.instruction, save.param, "");
	return ret;
}

SyntacticElement* Subpropiety::getSemantic(){
//	printf("->\n");
	string aux=this->elem->getName();
	//printf("-> %s\n", aux);
	//this->elem;
	if (this->elem->getSyntactic()==2 && this->listParametros.size()==0 && this->subElement!=NULL){
		SyntacticElement* aux2=searchElem(this->elem->getName(),0);
		if (aux2!=NULL)
			this->elem=aux2;
	}
	if ((this->elem->getSyntactic()==0 || this->elem->getSyntactic()==2 || this->elem->getSyntactic()==3)&& this->elem->getParser()!=CONSTANT_VALUE){
		//printf("Aqui tamos!\n");
		if (this->parent!=NULL)
			return this->semanticNext(this->parent);
		else {
			printf("Se nos escapo alguna cosa en %s", this->elem->getName().c_str());
			return NULL;
		}
/*		num_line=this->elem->getLine();
		char* str=(char*) malloc(sizeof(char)* 1024);
		sprintf(str, "The element %s is not defined", this->elem->getName().c_str());
		showError(str);
		free(str);
		return NULL;*/
	}
	if (this->elem->getSyntactic()!=1 && this->elem->getSemantic()!=NULL &&this->elem->getSemantic()->getSyntactic()!=1){
		num_line=this->elem->getLine();
		char* str=(char*) malloc(sizeof(char)*1024);
		sprintf(str, "The class %s is not a valid class", this->elem->getSemantic()->getName().c_str());
		showError(str);
		free(str);
		return NULL;
	}
	if (stricmp(aux,"this")==0){
		return this->subElement->semanticNext(this->elem->getSemantic());
	} else if (stricmp(aux,"super")==0){
		// It needs a special options...
	} else if (this->elem->getSyntactic()==5 || this->elem->getParser()==CONSTANT_VALUE){
		//printf("It's a private or a constant value\n");
		//printf("semantic: %s\n", this->elem->getSemantic()->getName());
		if (this->subElement!=NULL){
			return ((Subpropiety*) this->subElement)->semanticNext(this->elem->getSemantic());
		} else{
			return this->elem->getSemantic();
		}
	} else if (this->elem->getSyntactic()==1){ //we have a class, and it seems a static call.
		//((Subpropiety*) this->subElement)->semanticNextStatic(this->elem);
		//printf("Test %s\n", this->elem->getName().c_str());
		return ((Subpropiety*) this->subElement)->semanticNext(this->elem);
	} else if (this->elem->getSyntactic()==7){
		if (this->subElement==NULL)
			return ((AbstractExpresion*) this->elem->getPackage())->getSemantic();
		else {
			return this->subElement->semanticNext(((AbstractExpresion*) this->elem->getPackage())->getSemantic());
		}
	} else{
		printf("We have a problem in '%s' with Parser %d - %d\n", this->elem->getName().c_str(), this->elem->getParser(), CONSTANT_VALUE);
		return NULL;
/*		SyntacticElement* vthis=searchElem("this"); // We need to move this to the syntacticParser.
		if (vthis!=NULL)
			return this->semanticNext(vthis->getSemantic());
		else {
			printf("El problema el tenim al buscar this\n");
			return NULL;
		}*/

	}
}
void Subpropiety::getName(string &name){
	name.append(this->elem->getName());
	if (this->subElement!=NULL){
		name.append(".");
		this->subElement->getName(name);
	}
}
SyntacticElement* Subpropiety::semanticNext(SyntacticElement* parent){
	SyntacticElement* aux;
	/*printf("*parent: %s\n", parent->getName().c_str());
	printf("yo: %s\n", this->elem->getName().c_str());
	//*/
	char* debugText=(char*) malloc(sizeof(char)*1024);
	if (this->elem->getSyntactic()==0){
		sprintf(debugText, "Finding the propiety or method %s in class %s UID: %d", this->elem->getName().c_str(), parent->getName().c_str(), parent->getUID());
		semantic_debug(this->elem->getLine(), debugText);
		
		//aux=searchElem(this->elem->getName(),parent->getUID());
		aux=parent->searchSubElement(this->elem->getName().c_str());
		//if (lookup(this->elem->getName(),aux, parent->getSemantic()->getUID())){
		if (aux!=NULL){
			this->elem=aux;
		} else {
			char* str=(char*) malloc(sizeof(char)*1024);
			num_line=this->getLine();
			sprintf(str, "Cannot found lexem '%s' in %s class", this->elem->getName().c_str(), parent->getName().c_str());
			showError(str);
			free(str);
			return NULL;
		}
	}
	
	if (this->elem->getSyntactic()==1){
		//It doesn't happen never
		printf("SemanticNext: We have a class!\n");
	} else if (this->elem->getSyntactic()==2){
		//well we need to search if one of the implementation is equals to our call, using the semantic types of the call.
		//printf("We have a function!\n");
		clist* listTypesArgs=new clist();
		//vector<SyntacticElement*> listTypesArgs;
		SyntacticElement* tmp;
		for (int j=0;j<listParametros.size();j++){
			tmp=listParametros[j]->getSemantic();
			AbstractExpresion* debug=listParametros[j];
			//printf("We have %s\n", tmp->getName());
			if (tmp==NULL){
				delete listTypesArgs;
				return NULL;
			}
			listTypesArgs->add(tmp);
		}
		//At this moment, we don't have visibility, in the future it is need to change.
		this->methodCache=parent->getMethodByNameArgsAndVisibility(this->elem->getName().c_str(), listTypesArgs, 3);
		if (methodCache==NULL){
			num_line=this->getLine();
			//char* str=(char*) malloc(sizeof(char)*1024);
			//sprintf(str, "Cannot found method %s with arguments {Complete this}", this->elem->getName().c_str());
			string str="Cannot found method" + this->elem->getName() + " with arguments (";
			cnode* nodeType=listTypesArgs->getFirst();
			while (nodeType!=NULL){
				str+=((SyntacticElement*) nodeType->getContents())->getName();
				nodeType=nodeType->getNext();
			}
			str+=")";
			showError(str);
			//free(str);
			return NULL;
		}
		//printf("Debug MethodCache: %s\n",methodCache->getName().c_str());
		aux=methodCache->getReturn();
		/*if (aux!=NULL)
			printf("Tornem el tipus: %s\n", aux->getName());
		else 
			printf("Tornem null");*/
		//search the implementation. And need to indicate which funcion is.
		
	} else if (this->elem->getSyntactic()==3){
		aux=this->elem->getSemantic();
	} else if (this->elem->getSyntactic()==4){
		char* str=(char*) malloc(sizeof(char)*1024);
		sprintf(str, "Cannot found lexem '%s' in '%s' class", this->elem->getName().c_str(), parent->getName().c_str());
		showError(str);
		free(str);
		return NULL;
	} else if(this->elem->getSyntactic()==7){
		aux=((AbstractExpresion*) this->elem->getPackage())->getSemantic();
	}
	//printf("Teoria: %s - %p - %p\n", aux->getName(), this->subElement, aux);
	
	if (this->subElement!=NULL && aux!=NULL){
		aux=this->subElement->semanticNext(aux);
		//if (this->elem->getSyntactic()==2)
		//	printf("Debug2 MethodCache: %s\n",methodCache->getName().c_str());
		return aux;
	} else if (this->subElement==NULL) {
		return aux;
	}else {
		//printf("We have an error\n");
		semantic_debug(this->getLine(), "We have an error");
		return NULL;
	}
}

bool Subpropiety::verifyVariable(){
	if (this->subElement==NULL){
		return AbstractExpresion::verifyVariable();
	} else {
		return this->subElement->verifyVariable();
	}
}

void Subpropiety::ofxGenerateLoad(OFXByteCode::OFXByteCode* obj){
	//OFXJmpQueue ret=Base::ofxGenerate(obj);
	this->createInstruction(obj);
	//printf("ofxGenerateLoad: %s\n", this->elem->getName().c_str());
	if (this->subElement!=NULL){
		this->subElement->ofxGenerateLoad(obj);
	}
	//return ret;
}
ASM_line Subpropiety::ofxGenerateReplace(OFXByteCode::OFXByteCode* obj){
	ASM_line ret;
	ret.instruction=SIZE_INSTRUCTIONS;
	ret.param=-3;
	if (subElement!=NULL){
		this->createInstruction(obj);
		return subElement->ofxGenerateReplace(obj);
	} else {
		switch (this->elem->getSyntactic()) {
			case 3:
				ret.instruction=STORE_ATTR;
				ret.param=this->elem->getUID();
				break;
			case 5:
				ret.instruction=STORE_PRIVATE;
				ret.param=this->elem->getUID();
				break;
		}
	}
	return ret;
}