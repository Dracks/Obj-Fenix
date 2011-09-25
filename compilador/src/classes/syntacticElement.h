/*
 *  Identifier.h
 *  compilador
 *
 *  Created by dracks on 19/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
class MethodDefinition;
class SyntacticElement;

#ifndef SyntacticElement_h
#define SyntacticElement_h 1
#include "clist.h"
#include "../generator/OFXClass.h"
#include <string>

using namespace std;

int getNextClassID();

class SyntacticElement{
public:
		SyntacticElement(string name, int type, int line, char* file);
	SyntacticElement(void*, int line, char* file);
	void setSyntactic(int _val);
	void setSemantic(struct SyntacticElement* _val);
	void setUID(int _val);
	void addMethod(struct SyntacticElement* _val);
	MethodDefinition* addMethodImplementation(clist* params,clist* vars,  clist* code, SyntacticElement* returnType, int ambito, int num_line);
	void addPropiety(struct SyntacticElement* _val);
	void setAmbito(int _val);
	string getName();
	char getSyntactic();
	int getParser();
	SyntacticElement* getSemantic(){return semantic_type;};
	SyntacticElement* searchSubElement(const char* name);
	clist* getMethodList();
	clist* getMethodVisibles(char _ambito);
	clist* getPropietyListFrom(char _ambito);
	void setSpaceName(int);
	int getSpaceName();
	int getUID();
	
	void setNextMethodUID(int v){nextMethodUID=v;};
	int getNextMethodUID(){return nextMethodUID++;};
	
	void setNextPropietyUID(int v){nextPropietyUID=v;};
	int getNextPropietyUID(){return nextPropietyUID++;};
	
	// Every time it was been called when you are in a class, NEVER in other options.
	MethodDefinition* getMethodByNameArgsAndVisibility(const char* name, clist* args, char ambito);
	
	void setNative(bool n){this->native=n;};
	bool getNative(){return native;};
	
	void setSemanticValidated(bool v){semanticValidated=v;};
	bool getSemanticValidated(){return semanticValidated;};
	
	struct SyntacticElement* clone();
	
	int getLine();
	char* getFile();
	
	OFXByteCode::OFX_Class* getOFXClass();
	void setOFXClass(OFXByteCode::OFX_Class* v){headerClass=v;}
	
	bool testCastWith(SyntacticElement* test, int &profundity);
	
	void* getPackage();
	
	void setStatic(bool);
	
	bool getStatic();
	
private:
	int lineDefinition;
	char* file;
	int UID;
	int spaceName;
	int nextMethodUID;
	int nextPropietyUID;
	string name; //this is the tag of the element
	char ambito; // Para variables... 0=> Global, 1=> protejido, 2=> privada, 3=>metodo.
	char syntactic_type; // nodefinit=0,class=1,method=2,propiety=3,language=4, method variable=5, constant=6, package=7
	bool native; // 
	bool semanticValidated; // boolean for test if the semantic validator is passed for this or not.
	int parserType;
	bool isStatic; //in propiety(or method) define it as static .
	
	SyntacticElement* semantic_type;
//	clist* possibilities;	// a method add, the list of Method_definitions that it has.
//	clist* listPropiety[3]; // The list of propieties, on 0, the private, on 1 the protected and 2 public.
//	clist* listMethod[3];	// the list of method, the same as listPropiety
	// Con la sobreCarga de operadores, me acabo de dar cuenta, que no nos vale esto de 3 listas de metodos. Por 
	// lo que cada elemento de la sobrecarga debera contener a que ambito pertenece.
	clist* methodList;
	clist* propietyList; //Por estandarizacion, este tambien tirara de ambito propio.
	
	OFXByteCode::OFX_Class* headerClass;
	//int lineImplementation;
	
	void* packageContents;
};

class MethodDefinition{
private:
	char ambito;
	int UID;
	int lineDefinition;
	SyntacticElement* returnType;
	clist* privateVars;
	clist* params; //Contendra variables
	clist* semanticArgs;
	clist* code; // Contendra el codigo del metodo para la validacion semantica. El codigo ira en bloques
	
	int lineImplementation;
	string name;
	
	bool isStatic;
	
	//int nReturnStatments;
	
	bool constructor;
	
public:
	MethodDefinition(string name, clist* params, clist* vars, clist* code, SyntacticElement* returnType, int ambito, int line);
	void setSemanticArgs(clist* list);
	clist* getSemanticArgs();
	void setUID(int uid);
	int getUID();
	clist* getPrivate();
	clist* getParams();
	clist* getCode();
	int getAmbito();
	int getLine();
	SyntacticElement* getReturn();
	void	setReturn(SyntacticElement*);
	
	int getLineImpl(){return lineImplementation;};
	void setLineImpl(int v){lineImplementation=v;};
	
	void setAsConstructor(bool c){constructor=c;};
	bool isConstructor(){return constructor;};
	
	//int getnReturnStatments(){return nReturnStatments;};
	//void setnReturnStatments(int n){nReturnStatments=n;};
	
	string getName();
	
	void setStatic(bool);
	
	bool getStatic();
	//void addParam();
};

#endif
