%{
	
#include <stdio.h>
#include <stdlib.h>
#include "syntactic_parser.h"
#include "../src/main.h"
#include "../src/tools.h"
#include "../src/debug.h"
//#include "../src/classes/clist.h"
#include "../src/classes/syntacticElement.h"
#include "../src/treeCode/Base.h"
#include "../src/treeCode/Loop.h"
#include "../src/treeCode/Condition.h"//*/
#include "../src/treeCode/Expresion.h"
	
#define YYLMAX 100
#define YES 1
#define NO 0
#define FALSE 0
#define TRUE 1
	
	extern FILE *yyout;
	extern int yylineno;
	extern int num_line;
	extern int num_column;
	extern int espai_actual;
	extern char* parsing_file;
	extern int yylex();
	extern void yyerror(char*);
	extern clist list_files_compile;
	extern clist list_objects_builded;
	extern SyntacticElement* main_object;
	int regs[26];
	char * str ;
	int tmp_num_line;
	
	char ambitoActual=0;
	SyntacticElement* actualClass;
	SyntacticElement* tmpSyntactic;
	clist listReturnStatments;
%}
// enum varType {enter, real, string, caracter, boolea};

%union{

	struct SyntacticElement* data;
	struct clist* list;
	struct AbstractExpresion* expresion;
	struct Base*  sentence;
	bool boolean;
}

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' MOD_TOKEN
%left UMENYS

%error-verbose


%token <data>ID_SUBTYPE <data> ID_FUNCTION
%token CLASS_TOKEN DEF_TOKEN PROGRAM_TOKEN  END_TOKEN IMPORT_TOKEN INTERFACE_TOKEN PACKAGE_TOKEN NATIVE_TOKEN THIS_TOKEN INHERIT_TOKEN BEGIN_TOKEN
%token ELIF_TOKEN IF_TOKEN  ELSE_TOKEN RETURN_TOKEN
%token PROTECTED_TOKEN PUBLIC_TOKEN PRIVATE_TOKEN
%token WHILE_TOKEN DO_TOKEN LOOP_TOKEN FOR_TOKEN IN_TOKEN
%token LEXICAL_ERROR AND_TOKEN

 
%token  LE_OP GE_OP
%token DIF_OP POT_OP ASSIG DOS_PUNTOS 
%token <data> IDENTIFIER 
%token <data> NUMERIC_LITERAL CHARACTER_LITERAL STRING_LITERAL CONSTANT_VALUE


%start program;
//%start linea;
 
%%
program : option_defining_program 
		list_modules_import
option_package_definition {syntactic_debug("program <-- option_package_definition")}
list_class_definition {syntactic_debug("program <-- Option_defining_program list_modules_import option_package_Definition list_class_definition");};


option_defining_program: PROGRAM_TOKEN IDENTIFIER ':' { syntactic_debug("option_defining_program <-- Program Identifier :"); 
	if (main_object!=NULL){
		str=(char*)malloc(1024*sizeof(char));
		sprintf(str,"Two classes for program defined, ignorign(%s)",tmpSyntactic->getName().c_str());
		showError(str);
		free(str);
//		showError("Two classes for program defined")
	} else {
		main_object=$<data>2;
	}
}
| {syntactic_debug("option_defining_program <-- nothing");};


list_modules_import: list_modules_import module_import {syntactic_debug("list_modules_import <-- list_modules_import module_import");}
| /*nothing*/ {syntactic_debug("list_modules_import <-- nothing")};

option_package_definition: PACKAGE_TOKEN IDENTIFIER ';' {syntactic_debug("option_package_definition <-- PACKAGE_TOKEN IDENTIFIER ;")}
	| {syntactic_debug("option_package_definition <-- nothing")};

module_import: IMPORT_TOKEN CONSTANT_VALUE ';'{syntactic_debug("module_import <-- import STRING"); list_files_compile.add(strCopy($<data>2->getName().c_str()))};

list_class_definition: list_class_definition class_interface_definition {syntactic_debug("list_class_definition <-- list_class_definition class_interface_definition")}
		| class_interface_definition {syntactic_debug("list_class_definition <-- class_interface_definition")};

class_interface_definition: class_definition {syntactic_debug("class_interface_definition <-- class_definition")}
		/*| interface_definition  {syntactic_debug("class_interface_definition <-- interface_definition")};*/

class_definition: CLASS_TOKEN option_native IDENTIFIER option_inherit{
	tmpSyntactic=$<data>3; 
	//printf("algo xirria - %s - %d\n", tmpSyntactic->getName(), tmpSyntactic->getSyntactic());
	if (tmpSyntactic->getSyntactic()==0){
		//printf("Vamus per parts!\n");
		tmpSyntactic->setSyntactic(1);
		actualClass=tmpSyntactic;
		printf("Debug definition class: %s in namespace: %d pointer: %p ", tmpSyntactic->getName().c_str(), espai_actual, tmpSyntactic);
		actualClass->setUID(getNextClassID());
		espai_actual=actualClass->getUID()+2;
		actualClass->setSpaceName(espai_actual);
		printf("with UID: %d\n", actualClass->getUID());
		insertThisToken(tmpSyntactic);
		tmpSyntactic=searchElem("this");
		if (tmpSyntactic==NULL){
			exit(-1);
		}
		tmpSyntactic=insertToken(strCopy(actualClass->getName().c_str()), IDENTIFIER, actualClass->getSpaceName());
		//tmpSyntactic=new SyntacticElement(actualClass->getName(), IDENTIFIER, num_line, parsing_file);
		tmpSyntactic->setSyntactic(2);
		clist* aux=new clist();
		SyntacticElement* aux2=new SyntacticElement("", IDENTIFIER, num_line, parsing_file);
		aux2->setSemantic(searchElem("Object",0));
		//assert(aux2!=NULL);
		aux->add(aux2);
		//MethodDefinition* cast=new MethodDefinition(actualClass->getName(), aux, new clist(), actualClass, 3, num_line);
		tmpSyntactic->addMethodImplementation(aux, new clist(), new clist(), actualClass, 3, num_line);
		actualClass->addMethod(tmpSyntactic);
//		insertToken(<#char *lexema#>, <#int type#>, <#int espai#>)
		//tmpSyntactic->setSyntactic(5);
		//tmpSyntactic->setSemantic(actualClass);
		//printf("Vamus per parts2!\n");
	} else if (tmpSyntactic->getSyntactic()==1){
		//fprintf(stderr, "ERROR line %d")
		//printf("I de fet, xirria molt!\n");
		str=(char*)malloc(1024*sizeof(char));
		sprintf(str,"Redeclaration class %s",tmpSyntactic->getName().c_str());
		showError(str);
		free(str);
	} //*/
	/*Aqui iria la herencia, de momento a NULL que vendria a ser el objeto padre. */
	actualClass->setSemantic($<data>4);
}':'
	list_acces_level_block
END_TOKEN {
	char* str=(char*)malloc(sizeof(char)*1024);
	sprintf(str, "class_definition <-- class option_native identifier(%s): list_acces_level_block end", actualClass->getName().c_str());
	syntactic_debug(str);
	free(str);
	
	list_objects_builded.add(actualClass);
	actualClass->setNative($<boolean>2);
	
	espai_actual=0;
	ambitoActual=0;
}

option_native: NATIVE_TOKEN {syntactic_debug("option_native <-- native"); $<boolean>$=YES;}
| {syntactic_debug("option_native <-- nothing"); $<boolean>$=NO;};

option_inherit: INHERIT_TOKEN IDENTIFIER {$<data>$=$<data>2;}
| {$<data>$=searchElem("Object");}

list_acces_level_block:
level_definition_token ':'
	list_definitions
END_TOKEN list_acces_level_block {syntactic_debug("list_acces_level_block <-- level_definition_token : list_definitions end list_acces_level_block")}
//| list_definitions list_acces_level_block {syntactic_debug("list_acces_level_block <-- list_definitions list_acces_level_block")}
| {syntactic_debug("list_acces_level_block <-- nothing")} ;

level_definition_token: PUBLIC_TOKEN {syntactic_debug("level_definition_token <-- public");ambitoActual=0;}
| PRIVATE_TOKEN {syntactic_debug("level_definition_token <-- private");ambitoActual=2;}
| PROTECTED_TOKEN {syntactic_debug("level_definition_token <-- protected");ambitoActual=1};

list_definitions: definition list_definitions {syntactic_debug("list_definitions <-- definition list_definitions")}
| definition {syntactic_debug("list_definitions <-- definition")};

/*
list_definitions: definition list_definitions_rec {syntactic_debug("list_definitions <-- definition list_definitions")}

list_definitions_rec: definition list_definitions_rec
|;
*/
definition: propiety_definition {syntactic_debug("definition <-- propiety_definition")}
| method_definition {syntactic_debug("definition <-- method_definition")};

propiety_definition: list_propiety ':' {name_space_push(0)} IDENTIFIER {name_space_pop();} ';' {syntactic_debug("propiety_definition <-- list_propiety : IDENTIFIER ;");
	cnode* nodeAux= $<list>1->getFirst();
	while (nodeAux!=NULL){
		tmpSyntactic=(SyntacticElement*)nodeAux->getContents();
		if (tmpSyntactic->getSyntactic()==0){
			tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic($<data>4);
			tmpSyntactic->setSyntactic(3);
			actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		nodeAux=nodeAux->getNext();
	}//*/
	delete $<list>1;
}
| error ';' {syntactic_debug("propiety_definition <-- error ;")} ;

list_propiety:  IDENTIFIER list_propiety_concat {syntactic_debug("list_propiety <-- IDENTIFIER list_propiety_concat "); $<list>$=$<list>2;$<list>$->addFirst($<data>1);};

list_propiety_concat: ',' IDENTIFIER list_propiety_concat {syntactic_debug("list_propiety_concat <-- , IDENTIFIER list_propiety_concat"); $<list>$=$<list>3;$<list>$->addFirst($<data>2);}
	| {syntactic_debug("list_propiety_concat <-- nothing "); $<list>$=new clist()};

method_definition : DEF_TOKEN IDENTIFIER {sym_push_scope(); tmp_num_line=num_line;} option_definition_parameters option_return implementation_option
		{
			syntactic_debug("method_definition <-- def IDENTIFIER option_definition_parameters option_return implementation_option");
			//printf("debug_espai_actual: %d\n", espai_actual);
			sym_pop_scope();
			MethodDefinition* impl;
			//printf("$>%s<\n", $<data>2->getName().c_str());
			if ($<data>2->getSyntactic()==1){ 
				//this is a constructor
				$<data>2=insertToken(strCopy($<data>2->getName().c_str()), IDENTIFIER);
			}
			if ($<list>6!=NULL)
				impl=$<data>2->addMethodImplementation($<list>4,(clist*) $<list>6->getFirst()->getContents(),(clist*) $<list>6->getLast()->getContents(), $<data>5, ambitoActual, tmp_num_line);
			else
				impl=$<data>2->addMethodImplementation($<list>4,NULL,NULL, $<data>5, ambitoActual, tmp_num_line);
			bool found=FALSE;
			//printf("·>%s<\n", impl->getName().c_str());
			
			if (stricmp($<data>2->getName(), actualClass->getName())==0){
				impl->setAsConstructor(true);
				impl->setReturn(actualClass);
			}
		//	printf("Provant aquest element:%s - %d de la clase %s - %d\n", $<data>2->getName(),$<data>2->getSyntactic(), actualClass->getName(), actualClass->getSyntactic());
			if (actualClass->getMethodList()!=NULL){
				cnode* aux=actualClass->getMethodList()->getFirst();
				while (aux!=NULL && !found){
					SyntacticElement* tst=(SyntacticElement*)aux->getContents();
					if (strcmp(tst->getName().c_str(), $<data>2->getName().c_str())==0)
						found=TRUE;
					aux=aux->getNext();
				}
			}
			//impl->setnReturnStatments(listReturnStatments.count());
			cnode* aux=listReturnStatments.getFirst();
			while (aux!=NULL){
				((Return*) aux->getContents())->setSemantic($<data>5);
				aux=aux->getNext();
			}
			listReturnStatments.clear();
			
			if (!found){
				actualClass->addMethod($<data>2);
				$<data>2->setSyntactic(2);
			}
			//printf("->%s<\n", impl->getName().c_str());
		};

option_definition_parameters: '(' definition_parameter list_definition_parameters ')'{
		$<list>$=$<list>3;
		$<list>$->addFirst($<data>2);
	}
		| {$<list>$=new clist();};
		
list_definition_parameters: ',' definition_parameter list_definition_parameters{
		$<list>$=$<list>3; 
		$<list>$->addFirst($<data>2);
	}
		| {$<list>$=new clist();};
		
definition_parameter: IDENTIFIER ':' {name_space_push(0)} IDENTIFIER {
		SyntacticElement* tmpSyntactic=$<data>1;
		//printf("Definition_parameter: espai_actual: %d %s %p\n", espai_actual, $<data>4->getName(), $<data>4);
		name_space_pop();
		if (tmpSyntactic->getSyntactic()==0){
			tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic($<data>4);
			tmpSyntactic->setSyntactic(5);
			//actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		$<data>$=tmpSyntactic;
};
		
	option_return: RETURN_TOKEN {name_space_push(0)}IDENTIFIER { name_space_pop();$<data>$=$<data>3;};
		| {$<data>$=NULL;};

implementation_option:':' var_declaration_list BEGIN_TOKEN list_sentences END_TOKEN 
		{
			//printf("Data: espai_actual: %d\n", espai_actual);
			syntactic_debug("implementation_option <-- : var_declaration_list BEGIN list_sentences END");
			$<list>$=new clist(); 
			$<list>$->add($<list>2); 
			$<list>$->add($<list>4);
		}
		| ';' {syntactic_debug("implementation_option <-- ;"); $<list>$=NULL};

var_declaration_list: var_declaration ';' var_declaration_list{
	cnode* aux=$<list>1->getFirst();
	while (aux!=NULL){
		$<list>3->add(aux->getContents());
		//((SyntacticElement*) aux->getContents())->setSyntactic(5);
		aux=aux->getNext();
	}
	$<list>$=$<list>3;
	delete $<list>1;
}
			| /**/ {$<list>$=new clist();};

var_declaration: list_propiety ':'  {name_space_push(0)} IDENTIFIER{
	cnode* nodeAux= $<list>1->getFirst();
	name_space_pop();
	while (nodeAux!=NULL){
		tmpSyntactic=(SyntacticElement*)nodeAux->getContents();
		if (tmpSyntactic->getSyntactic()==0){
			//tmpSyntactic->setAmbito(ambitoActual);
			tmpSyntactic->setSemantic($<data>4);
			tmpSyntactic->setSyntactic(5);
			//actualClass->addPropiety(tmpSyntactic);
		} else {
			str=(char*)malloc(1024*sizeof(char));
			sprintf(str, "Redeclaration of variable %s", tmpSyntactic->getName().c_str());
		}
		nodeAux=nodeAux->getNext();
	}//*/
	$<list>$=$<list>1;
	//delete $<list>1;
}
		
//implementation:
//		list_sentences END_TOKEN  {syntactic_debug("implementation <-- : list_sentences end");$<list>$=$<list>2;}

list_sentences : list_sentences sentence {$<list>$=$<list>1; $<list>$->add($<sentence>2);}
		| {$<list>$=new clist();}

sentence:  condition_sentence
	| loop_options_sentence
	| call_sentence
	| return_sentence
		
		
call_sentence: expression option_assign_sentence ';'{
		//$<expresion>1->setParent(actualClass);
		if ($<expresion>2!=NULL){
			$<sentence>$=new Assignation($<expresion>1, $<expresion>2, num_line);
		//	$<expresion>2->setParent(actualClass);
		} else {
			$<sentence>$=$<expresion>1;
		}
	}
		
		
option_assign_sentence: ASSIG expression {
	syntactic_debug("assign_sentence <-- expression := expression ;");
	//$<sentence>$=new Assignation($<expresion>1,$<expresion>3, num_line);
	$<expresion>$=$<expresion>2;
}
			| {$<expresion>$=NULL};

return_sentence: RETURN_TOKEN option_expression ';'{
			//AbstractExpresion* debug=$<expresion>1;
			$<sentence>$=new Return($<expresion>2, num_line);
			listReturnStatments.add($<sentence>$);
		}
				
				
option_expression: expression {$<expresion>$=$<expresion>1;}
	| {$<expresion>$=NULL;};

		/** Aqui tengo que modificar un poco el arbol para facilitar el trabajo. Ya que internamente, los elseif seran anidados, facilidad de codigo */
condition_sentence: IF_TOKEN conditional_sentence ':'
	list_sentences
	option_elsif_sentences_list
	//option_else_sentence
END_TOKEN{
	Condition* tmp=new Condition($<expresion>2,$<sentence>5, num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	delete $<list>4;
	$<sentence>$=tmp;
};

option_elsif_sentences_list: ELIF_TOKEN conditional_sentence ':'
	list_sentences
	option_elsif_sentences_list
{
	Condition* tmp=new Condition($<expresion>2,$<sentence>5, num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentence>$=tmp;
	delete $<list>4;
}
| ELSE_TOKEN ':' 
		list_sentences
{
	Else* tmp=new Else(num_line);
	cnode* aux=$<list>3->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentence>$=tmp;
	delete $<list>3;
	
}
		|{$<sentence>$=NULL};
/*
option_else_sentence: ELSE_TOKEN ':' 
	list_sentences
|;*/

conditional_sentence: expression 
			/*{$<expression>1->setParent(actualClass); $<expression>$=$<expression>1;};*/

loop_options_sentence: /*for_sentence
	| */while_sentence
	| do_sentence
	| loop_sentence;

/*for_sentence:
FOR_TOKEN IDENTIFIER IN_TOKEN expression ':'
	list_sentences
END_TOKEN 
{
	//For* tmp=new For();
};*/

while_sentence:
WHILE_TOKEN conditional_sentence ':'
	list_sentences
END_TOKEN
{
	//printf("While token\n");
	While* tmp=new While($<expresion>2, num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentence>$=tmp;
};

do_sentence:
DO_TOKEN ':'
	list_sentences
END_TOKEN
{
	/*DoWhile* tmp=new DoWhile(conditional_sentence, num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentece>$=tmp;*/
};
			
			
loop_sentence:
LOOP_TOKEN ':'
	list_sentences
END_TOKEN
{
	Loop* tmp=new Loop(num_line);
	cnode* aux=$<list>4->getFirst();
	while (aux!=NULL){
		tmp->addSentence((Base*) aux->getContents());
		aux=aux->getNext();
	}
	$<sentence>$=tmp;
};
 /* variable: IDENTIFIER option_extension_expression */

value: IDENTIFIER {$<data>$=$<data>1;}
			| CONSTANT_VALUE {
	$<data>$=$<data>1; 
				$<data>$->setSyntactic(6);
	str=(char*) malloc(sizeof(char)*1024);
	sprintf(str,"Constant Value %s %d", $<data>1->getName().c_str(), $<data>1->getParser());
	syntactic_debug(str);
	free(str);
}
			| '(' expression ')' {$<data>$=new SyntacticElement((void*)$<expresion>2, num_line, parsing_file);};

expression: value {
	//printf("Test\n");
	//if ($<data>1==NULL)
	//printf("Verifico %s %d, %d\n", $<data>1->getName(), $<data>1->getUID(), $<data>1->getSyntactic());
	// Tractar el canvi d'espais de noms per cada variable
	SyntacticElement* aux;
	if ($<data>1->getSyntactic()==1)
		aux=$<data>1;
	else 
		aux=$<data>1->getSemantic();
	if (aux!=NULL){ //we know what class is defined the identifier
	//	printf("Test in it\n");
		if (aux->getSyntactic()==0){
			name_space_push(1);
		} else{
			name_space_push(aux->getSpaceName()); //we change to the spacename of this class
		}
	//	printf("It can be?\n");
	} else {
	//	printf("Un altre cami\n");
		name_space_push(1); //if we don't know what class is this variable, we only change to the undefined namespace, waiting the semantic parser, that it should solve this.
	}
}
option_extension_expression {
	//printf("%s\n", $<data>1->getSemantic()->getName().c_str());
	Subpropiety* aux=new Subpropiety($<data>1,num_line);
	aux->setParent(actualClass);
	aux->setExtension((Subpropiety*) $<expresion>3);
	name_space_pop();
	/*if (stricmp($<data>1->getName(), "this")!=0 && $<data>1->getParser()==IDENTIFIER && $<data>1->getSyntactic()<4 && $<data>1->getSyntactic()>1){
		//printf("Good %d\n", espai_actual);
		Subpropiety* aux2=new Subpropiety(searchElem("this"),num_line);
		//printf("Shit!\n");
		aux2->setExtension(aux);
		$<expresion>$=aux2;
	} else{
		$<expresion>$=aux;
				//printf("Bad\n");
	}*/
	$<expresion>$=aux;
	syntactic_debug("expression <-- IDENTIFIER option_extension_expression");
}
/*| CONSTANT_VALUE {
	$<expresion>$=new AbstractExpresion($<data>1,num_line);
}*/
/*
option_extension_expression: '.' IDENTIFIER {
	SyntacticElement* aux=$<data>1->getSemantic();
	if (aux!=NULL){ //we know what class is defined the identifier
		if (aux->getSyntactic()==0)
			name_space_push(1);
		else
			name_space_push(aux->getSpaceName()); //we change to the spacename of this class
	} else {
		name_space_push(1); //if we don't know what class is this variable, we only change to the undefined namespace, waiting the semantic parser, that it should solve this.
	}
} option_call_parameters_parent option_extension_expression {
	name_space_pop();
	Subpropiety* aux=new Subpropiety($<data>2,num_line);
	cnode* tmp=$<list>4->getFirst();
	while (tmp!=NULL){
		aux->addParamCall((AbstractExpresion*) tmp->getContents());
		tmp=tmp->getNext();
	}
	aux->setExtension((Subpropiety*) $<expresion>5);
	$<expresion>$=aux;
	syntactic_debug("option_extension_expression <-- . IDENTIFIER option_call_parameters_parent option_expression_expression");
}
|  IDENTIFIER push_espai_claseActual option_call_parameters {
	name_space_pop();
	//printf("%d.%d no se que cony passa '%s'\n", num_line, num_column, $<data>1->getName());
	syntactic_debug("option_extension_expression <-- IDENTIFIER option_call_parameters");
	Subpropiety* aux=new Subpropiety($<data>1,num_line);
	//aux->setExtension(NULL);
	cnode* tmp=$<list>3->getFirst();
	while (tmp!=NULL){
		aux->addParamCall((AbstractExpresion*) tmp->getContents());
		tmp=tmp->getNext();
	}
	$<expresion>$=aux;
}
			| {$<expresion>$=NULL;
	syntactic_debug("option_extension_expression <-- nothing");
	};*/
			
option_extension_expression: '.' IDENTIFIER {
	SyntacticElement* aux=$<data>1->getSemantic();
	if (aux!=NULL){ //we know what class is defined the identifier
		if (aux->getSyntactic()==0)
			name_space_push(1);
			else
				name_space_push(aux->getSpaceName()); //we change to the spacename of this class
			} else {
				name_space_push(1); //if we don't know what class is this variable, we only change to the undefined namespace, waiting the semantic parser, that it should solve this.
			}
	} option_call_parameters_parent option_extension_expression {
		name_space_pop();
		Subpropiety* aux=new Subpropiety($<data>2,num_line);
		cnode* tmp=$<list>4->getFirst();
		while (tmp!=NULL){
			aux->addParamCall((AbstractExpresion*) tmp->getContents());
			tmp=tmp->getNext();
		}
		aux->setExtension((Subpropiety*) $<expresion>5);
		$<expresion>$=aux;
		syntactic_debug("option_extension_expression <-- . IDENTIFIER option_call_parameters_parent option_expression_expression");
	}
|  IDENTIFIER push_espai_claseActual option_call_parameters {
		name_space_pop();
		//printf("%d.%d no se que cony passa '%s'\n", num_line, num_column, $<data>1->getName());
		syntactic_debug("option_extension_expression <-- IDENTIFIER option_call_parameters");
		Subpropiety* aux=new Subpropiety($<data>1,num_line);
		//aux->setExtension(NULL);
		cnode* tmp=$<list>3->getFirst();
		while (tmp!=NULL){
			aux->addParamCall((AbstractExpresion*) tmp->getContents());
			tmp=tmp->getNext();
		}
		$<expresion>$=aux;
	}
| {$<expresion>$=NULL;
		syntactic_debug("option_extension_expression <-- nothing");
};


option_call_parameters_parent: '(' push_espai_claseActual  expression list_call_parameters ')'
			{
				name_space_pop();
				//sym_pop_scope();
				$<list>$=$<list>4;
				$<list>$->addFirst($<expresion>3);
			}
	| {$<list>$=new clist();}

push_espai_claseActual: {
			name_space_push(actualClass->getSpaceName());
			//printf("%d debug namespace (%s)-> %d\n", num_line, actualClass->getName(), actualClass->getUID());
			//sym_push_scope(actualClass->getUID());
			//sym_push_scope();
};

option_call_parameters: expression {
	//name_space_pop();
	syntactic_debug("option_call_parameters <-- 2/2");
	//sym_pop_scope();
	$<list>$=new clist();
	$<list>$->addFirst($<expresion>1);
}
	| {$<list>$=new clist()};

list_call_parameters: ','  expression list_call_parameters {
	$<list>$=$<list>3;
	$<list>$->addFirst($<expresion>2);
}
| {$<list>$=new clist();};


/*interface_definition: INTERFACE_TOKEN option_native  IDENTIFIER ':'
	list_interface_declarations
END_TOKEN
| error END_TOKEN;

list_interface_declarations: list_interface_declarations method_declaration ;
| ;

method_declaration: DEF_TOKEN IDENTIFIER option_definition_parameters option_return ';'*/


		
%%



