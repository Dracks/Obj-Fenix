/*
 *  tools.h
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#include "classes/syntacticElement.h"
#include <sstream>
/** Mapejarem un poc el symtab **/
int addElement(string lexema, int type);
SyntacticElement* insertToken(string lexema, int type, int espai=-1);
SyntacticElement* insertThisToken(SyntacticElement* clase);
SyntacticElement* searchElem(string lexema);
SyntacticElement* searchElem(string lexema, int espai);
//sym_value_type* newElem();


void showError(string str);

void showWarning(string, int);

float toNumber(char* cadena);

//char* copyTag(string text, int length);

char* strtoup(string str);

int stricmp(string str1, string str2);

char* parseStringInput(string str);

char* strCopy(const char* text);

template<class T>
string convert(T number){

	std::ostringstream ss;//create a stringstream
	ss << number;//add number to the stream
	return ss.str();//return a string with the contents of the stream
}