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
/*
#define LOAD_GLOBAL		0
#define LOAD_PRIVATE	1
#define LOAD_ATTR		2
#define LOAD_CLASS		3
#define LOAD_METHOD		4
#define LOAD_CONSTANT	5
#define CALL			6
/*
 ...
 Method
 Param1
 ...
 Paramn
 -- 
 ...
 valRet
 *
#define RET				7
#define POP_TOP			8
#define GOTO			9
#define GOTO_TRUE		10
#define GOTO_FALSE		11
#define STORE_ATTR		12
/*
 ...
 Data
 Object.attr
 *
#define STORE_PRIVATE	13
/*
 ...
 Data
 *
#define PUSH_TOP		14
*/
typedef struct {
	ASMBytecode instruction;
	int param;
} ASM_line;

/*
typedef struct {
	int instruction;
	int param;
} ASM_line;*/

#endif