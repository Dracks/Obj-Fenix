/*
 *  ASM_instructions.h
 *  vm
 *
 *  Created by dracks on 06/03/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ASM_instructions_h
#define ASM_instructions_h
#define version 0.1

typedef enum ASMBytecode{
	LOAD_GLOBAL, LOAD_PRIVATE, LOAD_ATTR, LOAD_CLASS, LOAD_METHOD, LOAD_CONSTANT,
	CALL, RET, 
	POP_TOP,PUSH_TOP, 
	GOTO, GOTO_TRUE, GOTO_FALSE, 
	STORE_ATTR, STORE_PRIVATE, 
	SIZE_INSTRUCTIONS
};

typedef struct {
	ASMBytecode instruction;
	int param;
} ASM_line;

#endif