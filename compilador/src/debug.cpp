/*
 *  debug.cpp
 *  compilerTest
 *
 *  Created by Jaume Singla Valls on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "debug.h"

#include <stdio.h>
#include <stdlib.h>

extern char* parsing_file;
extern int	num_line;
extern FILE* out_syntactic_debug;
extern FILE* out_semantic_debug;
extern FILE* out_bytecode_debug;
extern FILE* out_asm_debug;

void syntactic_debug(const char* str){
/*	syntactic_debug(string(str));
}
void syntactic_debug(string str)
{*/
	if (out_syntactic_debug!=NULL){
		fprintf(out_syntactic_debug,"syntactic_debug(%s):%d\tApplying rule %s\n",parsing_file, num_line, str);
		//sync();
		//out_syntactic_debug << "syntactic_debug("<< parsing_file << "):" << num_line << "\tApplying rule "<< str << std::endl;
	}
}

void semantic_debug(int id, string str){
	if (out_semantic_debug!=NULL){
		fprintf(out_semantic_debug,"semantic_debug:\t %d with: %s\n", id, str.c_str());
		//sync();
	}
}

void bytecode_debug(string s){
	if (out_bytecode_debug!=NULL){
		fprintf(out_bytecode_debug, "%s\n",s.c_str());
		//sync();
	}
}

void asm_bytecode_debug(int line, string ins, int param, string name){
	if (out_asm_debug!=NULL){
		fprintf(out_asm_debug, "\t%d:%s\t%d\t%s\n",line, ins.c_str(), param, name.c_str());
		//sync();
	}
}
void asm_bytecode_debug(string data){
	if (out_asm_debug!=NULL){
		fprintf(out_asm_debug, "%s\n",data.c_str());
		//sync();
	}
}