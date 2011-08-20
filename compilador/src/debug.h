/*
 *  debug.h
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <string.h>
#include <iostream>
using namespace std;

//We have a problem, the syntactic_debug at this moment cannot convert to string.
void syntactic_debug(const char* str);
//void syntactic_debug(string str);
void semantic_debug(int id, string str);
void bytecode_debug(string s);
void asm_bytecode_debug(int line, string ins, int param, string);
void asm_bytecode_debug(string data);