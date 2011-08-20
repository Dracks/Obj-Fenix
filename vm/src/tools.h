/*
 *  tools.h
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <sstream>
/** Mapejarem un poc el symtab **/
//sym_value_type* newElem();

using namespace std;
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