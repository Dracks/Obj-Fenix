%{
	
#include <stdio.h>
#include <stdlib.h>
#include "syntactic_parser.h"
#include "../src/main.h"
	
#define YYLMAX 100
	
	extern FILE *yyout;
	extern int yylineno;
	extern int num_line;
	extern int num_column;
	extern int yylex();
	extern void yyerror(char*);
	int regs[26];
	char * str;
	
	 extern int espai_actual; 
	
	list pila; /* Pila per netejar les llistes o sigui recol-lector de basura. */
	list* actual;
	node* aux;
	node* aux2;
	struct sym_node* var;
	struct sym_node* var2;
%}
// enum varType {enter, real, string, caracter, boolea};

%union{
	struct sym_node* data;
	/* struct sym_node temp; */
	struct list* listRule;
	/* int type;	*/
}

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' MOD_TOKEN
%left UMENYS

%error-verbose

%token ABS_TOKEN AND_TOKEN ARRAY_TOKEN BEGIN_TOKEN CONSTANT_TOKEN
%token IS_TOKEN ELSE_TOKEN END_TOKEN FOR_TOKEN FUNCTION_TOKEN
%token IF_TOKEN IN_TOKEN LOOP_TOKEN THEN_TOKEN
%token MOD_TOKEN NOT_TOKEN NULL_TOKEN OF_TOKEN
%token OR_TOKEN PROCEDURE_TOKEN RANGE_TOKEN RECORD_TOKEN RETURN_TOKEN
%token TYPE_TOKEN WHEN_TOKEN WHILE_TOKEN FLOAT_TOKEN
/* %token INTEGER_TOKEN STRING_TOKEN BOOLEAN_TOKEN CHARACTER_TOKEN */
%token <data>ID_SUBTYPE <data> ID_FUNCTION <data> ID_VAR <data> ID_ENUM 
%token LEXICAL_ERROR 

 
%token  LE_OP GE_OP
%token DIF_OP POT_OP ASSIG DOS_PUNTOS 
%token <data> IDENTIFIER 
%token <data> NUMERIC_LITERAL CHARACTER_LITERAL STRING_LITERAL

// %type <listRule> parameter_association rec_actual_parameter_part


%start program;
//%start linea;
 
%%

defining_identifier : IDENTIFIER					{fprintf(yyout,"line %d.%d\tRULE:\tdefining_identifier <- identifier(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1;};

type_declaration : full_type_declaration			{fprintf(yyout,"line %d.%d\tRULE:\ttype_declaration <- full_type_declaration\n",num_line, num_column);};

full_type_declaration : TYPE_TOKEN defining_identifier IS_TOKEN type_definition ';'		{fprintf(yyout,"line %d.%d\tRULE:\tfull_type_declaration <- type defining_identifier(%s) is type_definition;\n",num_line, num_column,$<data>2->valor); 
	var=$<data>2;
	var->type=ID_SUBTYPE;
	var2=$<data>4;
	var->params=$<data>4->params;
	aux=getFirst(var->params);
	int* type=getContents(aux);
	if (*type==1){
		if (var->params->num>256){
			str=malloc(sizeof(char)*1024);sprintf(str, "enumeration type only accept 256 values.", $<data>1->valor);yyerror(str); free(str);
			YYERROR;
		}
		aux=getNext(aux);
		while(aux!=NULL){
			var=getContents(aux);
			fprintf(yyout,"line %d.%d\tTS\t: assign ID_ENUM type and semantic type (%s) to enumeration_value (%s).\n",num_line,num_column,$<data>2->valor, var->valor);
			var->semantic_type=$<data>2;
			var->type=ID_ENUM;
			aux=getNext(aux);
		}
	} /*else if (*type=10){
		fprintf(yyout,"line %d.%d\tTS\t: assign ID_SUBTYPE type and semantic type record to (%s).\n",num_line,num_column, var->valor);
	}*/
	free($<data>4);
					fprintf(yyout,"line %d.%d\tTS\t: changing type symbol(%s) to ID_SUBTYPE and applying the correct values.\n",num_line,num_column,$<data>2->valor);}
			| error ';'							{fprintf(yyout, "line %d.%d\tRULE:\tfull_type_declaration with error \n",num_line, num_column);};

type_definition : enumeration_type_definition		{fprintf(yyout,"line %d.%d\tRULE:\tenumeration_type_definition\n",num_line, num_column);}
			| integer_type_definition				{fprintf(yyout,"line %d.%d\tRULE:\tinteger_type_definition\n",num_line, num_column);}
			| array_type_definition					{fprintf(yyout,"line %d.%d\tRULE:\tarray_type_definition\n",num_line, num_column);}
			| record_type_definition				{fprintf(yyout,"line %d.%d\tRULE:\trecord_type_definition\n",num_line, num_column);};

subtype_indication : subtype_mark option_constraint	{fprintf(yyout,"line %d.%d\tRULE:\tsubtype_indication <- subtype_mark option_constraint \n",num_line, num_column);$<data>$=$<data>1;};
option_constraint: constraint						{fprintf(yyout, "line %d.%d\tRULE:\toption_constrain<- constraint \n",num_line, num_column);}
			|										{fprintf(yyout, "line %d.%d\tRULE:\toption_constraint with nothing \n",num_line, num_column);};

subtype_mark: ID_SUBTYPE							{fprintf(yyout,"line %d.%d\tRULE:\tsubtype_name <- identifier\n",num_line, num_column);$<data>$=$<data>1};
constraint : scalar_constraint						{fprintf(yyout,"line %d.%d\tRULE:\tscalar_constraint \n",num_line, num_column);};

scalar_constraint : range_constraint				{fprintf(yyout,"line %d.%d\tRULE:\trange_constraint\n",num_line, num_column);};

object_declaration : defining_identifier_list ':' option_constant object_declaration_type';'		{fprintf(yyout,"line %d.%d\tRULE:\tobject_declaration <- defining_identifier_list ':' [constant] object_declaration_type;\n",num_line, num_column);
	aux=getFirst($<listRule>1);
	while(aux!=NULL){
		var=(struct sym_node*)getContents((node*)aux);
		fprintf(yyout,"line %d.%d\tTS\t: changing symbol(%s) to ID_VAR and semantic type to:(%s)\n",num_line,num_column,var->valor, $<data>4->valor);
		var->type=ID_VAR;
		var->semantic_type=$<data>4; 
		aux=getNext(aux);
	}
	var2=$<data>4;
	aux=getFirst(var2->params);
	int* type=getContents(aux);
/*	printf("Debug:%d %s \n",*type, var2->valor); */
};

object_declaration_type: subtype_indication option_assign {fprintf(yyout,"line %d.%d\tRULE:\tobject_declaration_type <- subtype_indication option_assign;\n",num_line, num_column);}
			| array_type_definition					{fprintf(yyout,"line %d.%d\tRULE:\tobject_declaration_type <- array_type_definition;\n",num_line, num_column);};

option_constant :										{fprintf(yyout, "line %d.%d\tRULE:\toption_constant with nothing \n",num_line, num_column);}
			| CONSTANT_TOKEN					{fprintf(yyout, "line %d.%d\tRULE:\toption_constant<- constant\n",num_line, num_column);};
option_assign : ASSIG expression					{fprintf(yyout, "line %d.%d\tRULE:\toption_assign<- ASSIGN expression\n",num_line, num_column);$<data>$=$<data>2}
			|										{fprintf(yyout, "line %d.%d\tRULE:\toption_assign with nothing \n",num_line, num_column); $<data>$=NULL};

defining_identifier_list : defining_identifier	rec_defining_identifier_list		{fprintf(yyout,"line %d.%d\tRULE:\tdefining_identifier_list <- defining_identifier rec_defining_identifier_list\n",num_line, num_column);$<listRule>$=$<listRule>2; addElem($<listRule>$,(void*) $<data>1);};
rec_defining_identifier_list :  ',' defining_identifier rec_defining_identifier_list {fprintf(yyout,"line %d.%d\tRULE:\trec_defining_identifier_list <- , defining_identifier rec_defining_identifier_list\n",num_line, num_column); $<listRule>$=$<listRule>3; addElem($<listRule>$,(void*) $<data>2);}
	|									{fprintf(yyout, "line %d.%d\tRULE:\trec_defining_identifier_list with nothing \n",num_line, num_column);$<listRule>$=list_alloc();init($<listRule>$);addElem(actual,$<listRule>$);};

range_constraint : RANGE_TOKEN range						{fprintf(yyout,"line %d.%d\tRULE:\trange range\n",num_line, num_column);};

range : simple_expression DOS_PUNTOS simple_expression 		{fprintf(yyout,"line %d.%d\tRULE:\tsimple_expression .. simple_expression \n",num_line, num_column);
	var=newElem();
	var->params=list_alloc();
	int* type=(int*) malloc(sizeof(int));
	*type=0; /* unset */
	addElem(var->params, type);
	long* range=(long*) malloc(sizeof(long*)*2);
	range[0]=(long) $<data>1->real;
	range[1]=(long) $<data>3->real;
	addElem(var->params,range);
	$<data>$=var;
	
};

enumeration_type_definition : '(' enumeration_literal_specification rec_enumeration_type_definition ')'		
	{
		fprintf(yyout,"line %d.%d\tRULE:\tenumeration_type_definition <- (enumeration_literal_specification { , enumeration_literal_specification })\n",num_line, num_column);
		var=newElem();
		$<data>$=var;
		var->params=$<listRule>3; 
		addFirstElem(var->params,$<data>2);
		int* type=(int*) malloc(sizeof(int)*2);
		type[0]=1; /* tipus enumerat */
		type[1]=var->params->num; /* tenim aquests elements */
		addFirstElem(var->params, type);
		
	};
rec_enumeration_type_definition: ',' enumeration_literal_specification rec_enumeration_type_definition		
	{
	fprintf(yyout,"line %d.%d\tRULE:\trec_enumeration_type_definition <- , enumaration_literal_specification(%s) rec_enumeration_type_definition\n",num_line, num_column, $<data>2->valor);
		$<listRule>$=$<listRule>3;
		addFirstElem((list*)$<listRule>$,$<data>2);
	}
			|										{fprintf(yyout,"line %d.%d\tRULE:\trec_enumeration_type_definition with nothing\n",num_line, num_column);
				$<listRule>$=list_alloc();
				init($<listRule>$);
			};

enumeration_literal_specification : defining_identifier		{fprintf(yyout,"line %d.%d\tRULE:\tenumeration_literal_specification <- defining_identifier\n",num_line, num_column);}
			| defining_character_literal			{fprintf(yyout,"line %d.%d\tRULE:\tenumeration_literal_specification <- defining_character_literal\n",num_line, num_column);};

defining_character_literal : CHARACTER_LITERAL		{fprintf(yyout,"line %d.%d\tRULE:\tcharacter_literal(%s)\n",num_line, num_column, $<data>1->valor);};

/*integer_type_definition : signed_integer_type_definition		{fprintf(yyout,"line %d.%d\tRULE:\tsigned_integer_type_definition\n",num_line, num_column);};*/

integer_type_definition : RANGE_TOKEN static_simple_expression DOS_PUNTOS static_simple_expression		
	{
		fprintf(yyout,"line %d.%d\tRULE:\tsigned_integer_type_definition <- range static_simple_expression .. static_simple_expression\n",num_line, num_column);
		var=newElem();
		var->params=list_alloc();
		int* type=(int*) malloc(sizeof(int));
		*type=2;
		addElem(var->params, type);
		long* range=(long*) malloc(sizeof(long*)*2);
		range[0]=(long) $<data>2->real;
		range[1]=(long) $<data>4->real;
		addElem(var->params,range);
		$<data>$=var;
	};
static_simple_expression: NUMERIC_LITERAL				{fprintf(yyout, "line %d.%d\tRULE:\tstatic_simple_expression <- numeric_literal(%s)\n",num_line, num_column, $<data>1->valor);};

/* array_type_definition : constrained_array_definition		{fprintf(yyout,"line %d.%d\tRULE:\tconstrained_array_definition\n",num_line, num_column);}; */

array_type_definition : ARRAY_TOKEN '(' discrete_subtype_definition')' OF_TOKEN component_definition		{fprintf(yyout,"line %d.%d\tRULE:\tarray (discrete_subtype_definition) of component_definition\n",num_line, num_column);
	var=newElem();
	var->valor="Anonymous array";
	var->params=list_alloc();
	var->semantic_type=$<data>6;
	init(var->params);
	int* type=(int*) malloc(sizeof(int));
	*type=7;
	addElem(var->params,type);
	aux=getFirst($<data>3->params);
/*	var2=$<data>3; */
	aux=getNext(aux);/* Descartem el primer ja que es el identificador de tipus */
	addElem(var->params, getContents(aux));
	$<data>$=var;
	
};

discrete_subtype_definition : range		{fprintf(yyout,"line %d.%d\tRULE:\trange\n",num_line, num_column);}
			| discrete_subtype_indication		{fprintf(yyout,"line %d.%d\tRULE:\tdiscrete_subtype_indication\n",num_line, num_column);};

discrete_subtype_indication:	ID_SUBTYPE					{fprintf(yyout,"line %d.%d\tRULE:\tdiscrete_subtype_definition <- numeric subtype(%s)\n",num_line, num_column, $<data>1->valor);};

component_definition : subtype_indication			{fprintf(yyout,"line %d.%d\tRULE:\tcomponent_definition <- subtype_indication\n",num_line, num_column);};

/* record_type_definition : record_definition			{fprintf(yyout,"line %d.%d\tRULE:\trecord_type_definition <- record_definition\n",num_line, num_column);}; */

record_type_definition : RECORD_TOKEN 
	{
		var=newElem();
		var->params=list_alloc();
		init(var->params);
		int* type=(int*) malloc(sizeof(int)*2);
		type[0]=10;
		type[1]=name_space_push(-1);
		addElem(var->params,type);
		$<data>1=var;
		
	}
		component_list 
	{
		name_space_pop();
	}
	END_TOKEN RECORD_TOKEN		{fprintf(yyout,"line %d.%d\tRULE:\trecord_definition <- record component_list end record\n",num_line, num_column);$<data>$=$<data>1;};

component_list : component_item rec_component_list		{fprintf(yyout,"line %d.%d\tRULE:\tcomponent_list <- component_item rec_component_list\n",num_line, num_column);};
rec_component_list: component_item rec_component_list	{fprintf(yyout,"line %d.%d\tRULE:\trec_component_list <- component_item rec_component_list\n",num_line, num_column);}
			|											{fprintf(yyout,"line %d.%d\tRULE:\trec_component_list <- nothing\n",num_line, num_column);};

component_item : component_declaration			{fprintf(yyout,"line %d.%d\tRULE:\tcomponent_declaration\n",num_line, num_column);};

component_declaration : defining_identifier_list ':'{name_space_push(0)} component_definition {name_space_pop()}';'		
			{fprintf(yyout,"line %d.%d\tRULE:\tcomponent_declaration <- defining_identifier_list : component_definition;\n",num_line, num_column);
				aux=getFirst($<listRule>1);
				while(aux!=NULL){
					var=(struct sym_node*)getContents((node*)aux);
					var->type=ID_VAR;
					var->semantic_type=$<data>4;
					fprintf(yyout,"line %d.%d\tTS\t: changing record_symbol(%s) to ID_VAR and semantic type to:(%s)\n",num_line,num_column,var->valor, $<data>4->valor);
					aux=getNext(aux);
				}
				dealloc($<listRule>1);
			}
			| error								{fprintf(yyout, "line %d.%d\tRULE:\tcomponent_declaration with error \n",num_line, num_column);};

declarative_part :								{fprintf(yyout,"line %d.%d\tRULE:\tdeclarative_part with nothing\n",num_line, num_column);}
			| declarative_item declarative_part	{fprintf(yyout,"line %d.%d\tRULE:\tdeclarative_part <- declarative_item \n",num_line, num_column);};

declarative_item : basic_declarative_item		{fprintf(yyout,"line %d.%d\tRULE:\tdeclarative_item <- basic_declarative_item\n",num_line, num_column);}
			| subprogram_body								{fprintf(yyout,"line %d.%d\tRULE:\tdeclarative_item <- subprogram_body\n",num_line, num_column);};

basic_declarative_item : basic_declaration		{fprintf(yyout,"line %d.%d\tRULE:\tbasic_declarative_item <- basic_declaration\n",num_line, num_column);};

basic_declaration : object_declaration				{fprintf(yyout,"line %d.%d\tRULE:\tbasic_declaration<- object_declaration\n",num_line, num_column);}
			| type_declaration					{fprintf(yyout,"line %d.%d\tRULE:\tbasic_declaration<- type_declaration\n",num_line, num_column);}    
			| subprogram_declaration			{fprintf(yyout,"line %d.%d\tRULE:\tbasic_declaration<- subprogram_declaration\n",num_line, num_column);};

name : direct_name								{fprintf(yyout,"line %d.%d\tRULE:\tname <- direct_name\n",num_line, num_column);}
			| indexed_component					{fprintf(yyout,"line %d.%d\tRULE:\tname <- indexed_component\n",num_line, num_column);}
			| selected_component				{fprintf(yyout,"line %d.%d\tRULE:\tname <- selected_component\n",num_line, num_column);}
			| type_conversion					{fprintf(yyout,"line %d.%d\tRULE:\tname <- type_conversion\n",num_line, num_column);}
			| function_call						{fprintf(yyout,"line %d.%d\tRULE:\tname <- function_call\n",num_line, num_column);}
			| CHARACTER_LITERAL					{fprintf(yyout,"line %d.%d\tRULE:\tname <- character_literal(%s)\n",num_line, num_column,$<data>1->valor);};
			| defining_identifier				{str=malloc(sizeof(char)*1024);sprintf(str, "variable \"%s\" is undeclared", $<data>1->valor);yyerror(str); free(str);YYERROR;}

direct_name : ID_VAR						{fprintf(yyout,"line %d.%d\tRULE:\tdirect_name <- ID_VAR(%s)\n",num_line, num_column, $<data>1->valor);}
			| ID_ENUM						{fprintf(yyout,"line %d.%d\tRULE:\tdirect_name <- ID_ENUM(%s)\n",num_line, num_column, $<data>1->valor);};


indexed_component : ID_VAR {
	var2=$<data>1;
	 var=$<data>1->semantic_type; 
	aux=getFirst(var->params);
	int* type=getContents(aux);
	if (type[0]!=7 && type[0]!=5){
		str=malloc(sizeof(char)*1024);sprintf(str, "variable \"%s\" isn't a array or string", $<data>1->valor);yyerror(str); free(str);
		YYERROR;
	}
	
	}
			'('expression')'		{fprintf(yyout,"line %d.%d\tRULE:\tindexed_component <- direct_name (expression)\n",num_line, num_column);
				var=$<data>1->semantic_type;
				aux=getFirst(var->params);
				int* type=getContents(aux);
				if (type[0]==7) {
					aux=getNext(aux);
					long* range=getContents(aux);
					if ($<data>4->real<range[0] || $<data>4->real>range[1]){
						str=malloc(sizeof(char)*1024);sprintf(str, "the acces to variable \"%s\" is out of range", $<data>1->valor);yyerror(str); free(str);
						YYERROR;
					}
				} else if (type[0]==5){
					str=malloc(sizeof(char)*1024);sprintf(str, "variable \"%s\" isn't a array or string", $<data>1->valor);yyerror(str); free(str);
					YYERROR;
					if ($<data>4->real<1 || $<data>4->real>256){
						str=malloc(sizeof(char)*1024);sprintf(str, "the acces to variable \"%s\" is out of range", $<data>1->valor);yyerror(str); free(str);
						YYERROR;
					}
				}
			};

selected_component : ID_VAR '.'{
	var=$<data>1->semantic_type;
	aux=getFirst(var->params);
	int* type=getContents(aux);
	/* printf("Debug: %s, %d\n", var->valor, type[0]); */
		if (type[0]!=10){
			str=malloc(sizeof(char)*1024);sprintf(str, "variable \"%s\" isn't a record", $<data>1->valor);yyerror(str); free(str);
			YYERROR;
		} else {
			name_space_push(type[1]);
		}
	} name		{fprintf(yyout,"line %d.%d\tRULE:\tprefix . selector_name\n",num_line, num_column); $<data>$=$<data>4; name_space_pop()};

expression : relation rec_expression			{fprintf(yyout,"line %d.%d\tRULE:\texpression <- relation rec_and_relation\n",num_line, num_column);
	if ($<data>2!=NULL){
		var=$<data>1->semantic_type;aux=getFirst(var->params);int* type=getContents(aux); if (type[0]==1 && type[1]==2){
			str=malloc(sizeof(char)*1024);sprintf(str, "It is not a Boolean");yyerror(str); free(str);
		}
	}
};

rec_expression : AND_TOKEN option_then relation rec_expression	{fprintf(yyout, "RULE:\trec_expression <-  and then relation rec_expresion");
			var=$<data>3->semantic_type;aux=getFirst(var->params);int *type=getContents(aux); 
	if (type[0]==1 && type[1]==2){
				str=malloc(sizeof(char)*1024);sprintf(str, "It is not a Boolean");yyerror(str); free(str);
			}}
			| OR_TOKEN option_else relation rec_expression	{fprintf(yyout, "RULE:\t rec_expression <- or else relation rec_expresion");
				var=$<data>3->semantic_type;aux=getFirst(var->params);int *type=getContents(aux); 
				if (type[0]==1 && type[1]==2){
					str=malloc(sizeof(char)*1024);sprintf(str, "It is not a Boolean");yyerror(str); free(str);
				}}
			|									{fprintf(yyout, "line %d.%d\tRULE:\trec_expresion with nothing \n",num_line, num_column); $<data>$=NULL};

option_then : THEN_TOKEN						{fprintf(yyout,"line %d.%d\tRULE:\toption_then <- then\n",num_line, num_column);}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_then with nothing\n",num_line, num_column);};

option_else	: ELSE_TOKEN						{fprintf(yyout,"line %d.%d\tRULE:\toption_else <- else\n",num_line, num_column);}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_else with nothing\n",num_line, num_column);};

relation : simple_expression option_relation	{fprintf(yyout,"line %d.%d\tRULE:\trelation <- simple_expression option_relation\n",num_line, num_column); 
	if ($<data>2!=NULL){
		
	}
}
			|	simple_expression option_not IN_TOKEN range				{fprintf(yyout, "line %d.%d\tRULE:\trelation <- simple_expresion [not] in range\n",num_line, num_column); $<data>$=newElem();sym_value_type* elem;sym_lookup("BOOLEAN", &elem, espai_actual);$<data>$->semantic_type=elem;};

option_relation : relational_operator simple_expression					{fprintf(yyout, "line %d.%d\tRULE:\toption_relation <- relational_operator simple_expresion\n",num_line, num_column);}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_relation with nothing\n",num_line, num_column);$<data>$=NULL};

option_not: NOT_TOKEN							{fprintf(yyout,"line %d.%d\tRULE:\toption_not <- not\n",num_line, num_column);}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_not with nothing\n",num_line, num_column);};

simple_expression : option_unary_adding_operator term rec_simple_expression		{fprintf(yyout,"line %d.%d\tRULE:\tsimple_expression <- [unary_adding_operator] term rec_simple_expression\n",num_line, num_column);$<data>$=$<data>2};
option_unary_adding_operator: unary_adding_operator			{fprintf(yyout,"line %d.%d\tRULE:\toption_unary_adding_operator <- unary_adding_operator\n",num_line, num_column);}
			|									{fprintf(yyout, "line %d.%d\tRULE:\toption_unary_adding_operator with nothing \n",num_line, num_column);};

rec_simple_expression :  binary_adding_operator term rec_simple_expression {fprintf(yyout, "line %d.%d\tRULE:\trec_simple_expresion <- binary_adding_operator term rec_simple_expresion\n",num_line, num_column);}
			|									{fprintf(yyout, "line %d.%d\tRULE:\trec_simple_expresion <- nothing\n",num_line,num_column);};

term : factor rec_term							{fprintf(yyout,"line %d.%d\tRULE:\tterm <- factor rec_term\n",num_line, num_column);};
rec_term :										{fprintf(yyout,"line %d.%d\tRULE:\trec_term with nothing\n",num_line, num_column);$<data>$=NULL};
			| multiplying_operator factor rec_term		{fprintf(yyout, "line %d.%d\tRULE:\trec_term <- multiplying_operator factor rec_term\n",num_line, num_column);};

factor : primary option_pot_primary				{fprintf(yyout,"line %d.%d\tRULE:\tfactor <- primary [** primary]\n",num_line, num_column);
	if ($<data>2!=NULL){
		if (!(comprovaVar($<data>1,"integer") ||comprovaVar($<data>1,"float") ||comprovaVar($<data>1,"long") ||comprovaVar($<data>1,"double"))){
			str=malloc(sizeof(char)*1024);sprintf(str, "%s is not a numeric value", $<data>2->valor);yyerror(str); free(str);
			YYERROR;
		}
		$<data>$=$<data>1;
		str=malloc(sizeof(char)*(strlen($<data>1->valor)+strlen($<data>2->valor)+4));sprintf(str, "%s ** %s",$<data>1->valor, $<data>2->valor);$<data>$->valor=str;
	}
}
			| ABS_TOKEN primary					{fprintf(yyout,"line %d.%d\tRULE:\tfactor <- abs primary\n",num_line, num_column);
				if (!(comprovaVar($<data>2,"integer") ||comprovaVar($<data>2,"float") ||comprovaVar($<data>2,"long") ||comprovaVar($<data>2,"double"))){
					str=malloc(sizeof(char)*1024);sprintf(str, "%s is not a numeric value", $<data>2->valor);yyerror(str); free(str);
					YYERROR;
				}
				$<data>$=$<data>2;
				str=malloc(sizeof(char)*(strlen($<data>1->valor)+strlen($<data>2->valor)+2));sprintf(str, "%s %s",$<data>1->valor, $<data>2->valor);$<data>$->valor=str;

			}
			| NOT_TOKEN primary					{fprintf(yyout,"line %d.%d\tRULE:\tfactor <- not primary\n",num_line, num_column);
				if (!comprovaVar($<data>2,"boolean")){
					str=malloc(sizeof(char)*1024);sprintf(str, "%s is not a boolean value", $<data>2->valor);yyerror(str); free(str);
					YYERROR;
				}
				$<data>$=$<data>2;
				str=malloc(sizeof(char)*(strlen($<data>1->valor)+strlen($<data>2->valor)+2));sprintf(str, "%s %s",$<data>1->valor, $<data>2->valor);$<data>$->valor=str;
			};
option_pot_primary: POT_OP primary				{fprintf(yyout,"line %d.%d\tRULE:\toption_pot_primary <- **primary\n",num_line, num_column);
	if (!(comprovaVar($<data>2,"integer") ||comprovaVar($<data>2,"float") ||comprovaVar($<data>2,"long") ||comprovaVar($<data>2,"double"))){
		str=malloc(sizeof(char)*1024);sprintf(str, "%s is not a numeric value", $<data>2->valor);yyerror(str); free(str);
		YYERROR;
	}
		$<data>$=$<data>1;}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_pot_primary with nothing\n",num_line, num_column);$<data>$=NULL}

primary : NUMERIC_LITERAL						{fprintf(yyout,"line %d.%d\tRULE:\tprimary <- numeric_literal(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1;}
			| STRING_LITERAL					{fprintf(yyout,"line %d.%d\tRULE:\tprimary <- string_literal(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1;}
	| name								{fprintf(yyout,"line %d.%d\tRULE:\tprimary <- name\n",num_line, num_column); $<data>$=newElem(); $<data>$->valor=$<data>1->valor;$<data>$->semantic_type=$<data>1->semantic_type;var=$<data>1->semantic_type;}
			| '(' expression ')'				{fprintf(yyout,"line %d.%d\tRULE:\tprimary <-  ( expression )\n",num_line, num_column); $<data>$=$<data>2;
						str=malloc(sizeof(char)*(5+strlen($<data>2->valor)));sprintf(str, "( %s )", $<data>2->valor);$<data>2->valor=str};

relational_operator : '='						{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- '='\n",num_line, num_column);}
			| DIF_OP							{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- /=\n",num_line, num_column);}
			| '<'								{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- '<'\n",num_line, num_column);}
			| LE_OP								{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- <=\n",num_line, num_column);}
			| '>'								{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- '>'\n",num_line, num_column);}
			| GE_OP								{fprintf(yyout,"line %d.%d\tRULE:\trelation_operator <- >=\n",num_line, num_column);};

binary_adding_operator : '+'					{fprintf(yyout,"line %d.%d\tRULE:\tbinary_adding_operator <- +\n",num_line, num_column);}
			| '-'								{fprintf(yyout,"line %d.%d\tRULE:\tbinary_adding_operator <- –\n",num_line, num_column);}
			| '&'								{fprintf(yyout,"line %d.%d\tRULE:\tbinary_adding_operator <- &\n",num_line, num_column);};

unary_adding_operator : '+'	%prec UMENYS		{fprintf(yyout,"line %d.%d\tRULE:\tunary_adding_operator <- +\n",num_line, num_column);}
			| '-'			%prec UMENYS		{fprintf(yyout,"line %d.%d\tRULE:\tunary_adding_operator <- –\n",num_line, num_column);};

multiplying_operator : '*'						{fprintf(yyout,"line %d.%d\tRULE:\tmultiplying_operator <- *\n",num_line, num_column);}
			| '/'								{fprintf(yyout,"line %d.%d\tRULE:\tmultiplying_operator <- /\n",num_line, num_column);}
			| MOD_TOKEN							{fprintf(yyout,"line %d.%d\tRULE:\tmultiplying_operator <- mod\n",num_line, num_column);};

type_conversion : subtype_mark'('name')'		{fprintf(yyout,"line %d.%d\tRULE:\ttype_conversion <- subtype_mark(name)\n",num_line, num_column);
	if (comprovaCast($<data>1,$<data>3)){
		fprintf(yyout, "line %d%d\tTS:\t Casting %s to %s\n",$<data>1->valor,$<data>3->valor);
		$<data>$=newElem();
		str=malloc(sizeof(char)*(strlen($<data>1->valor)+strlen($<data>2->valor)+4));sprintf(str, "%s (%s) ",$<data>1->valor, $<data>3->valor);$<data>$->valor=str;
		$<data>$->semantic_type=$<data>1;
	} else {
		var=$<data>3->semantic_type;
		str=malloc(sizeof(char)*1024);sprintf(str, "the conversion cast(%s) is invalid for type(%s)", $<data>1->valor, var->valor);yyerror(str); free(str);
		YYERROR;
	}
	};

sequence_of_statements : statement	rec_sequence_of_statements		{fprintf(yyout,"line %d.%d\tRULE:\tsequence_of_statements <- statement { statement }\n",num_line, num_column);};
rec_sequence_of_statements:						{fprintf(yyout, "line %d.%d\tRULE:\trec_squence_of_statements with nothing \n",num_line, num_column);}
			|	statement rec_sequence_of_statements	{fprintf(yyout, "line %d.%d\tRULE:\trec_sequence_of_statements <- statement\n",num_line, num_column);};

statement : simple_statement					{fprintf(yyout,"line %d.%d\tRULE:\tstatement <- simple_statement\n",num_line, num_column);}
			| compound_statement				{fprintf(yyout,"line %d.%d\tRULE:\tstatement <- compound_statement\n",num_line, num_column);};

simple_statement : null_statement				{fprintf(yyout,"line %d.%d\tRULE:\tsimple_statement <- null_statement\n",num_line, num_column);}
			| assignment_statement				{fprintf(yyout,"line %d.%d\tRULE:\tsimple_statement <- assignment_statement\n",num_line, num_column);}
			| procedure_call_statement			{fprintf(yyout,"line %d.%d\tRULE:\tsimple_statement <- procedure_call_statement\n",num_line, num_column);}
			| return_statement					{fprintf(yyout,"line %d.%d\tRULE:\tsimple_statement <- return_statement\n",num_line, num_column);};

compound_statement : if_statement				{fprintf(yyout,"line %d.%d\tRULE:\tcompound_statement <- if_statement\n",num_line, num_column);}
			| loop_statement					{fprintf(yyout,"line %d.%d\tRULE:\tcompound_statement <- loop_statement\n",num_line, num_column);};

null_statement : NULL_TOKEN';' 		{fprintf(yyout,"line %d.%d\tRULE:\tnull_statement <- null; \n",num_line, num_column);};

assignment_statement : variable_name ASSIG expression';'		{fprintf(yyout,"line %d.%d\tRULE:\tvariable_name(%s) := expression;\n",num_line, num_column, $<data>1->valor);}
			| error ';'							{fprintf(yyout,"line %d.%d\tRULE:\tassignment_statement with error\n",num_line, num_column);};

variable_name : indexed_component						{fprintf(yyout,"line %d.%d\tRULE:\tvariable_name<- IDENTIFIER(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1}
				| selected_component						{fprintf(yyout,"line %d.%d\tRULE:\tvariable_name<- IDENTIFIER(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1}
				|  ID_VAR						{fprintf(yyout,"line %d.%d\tRULE:\tvariable_name<- IDENTIFIER(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1};

if_statement : IF_TOKEN condition THEN_TOKEN sequence_of_statements option_else_sequence_of_statements END_TOKEN IF_TOKEN';'		{fprintf(yyout,"line %d.%d\tRULE:\tif condition then [else sequence_of_statements sequence_of_statements] end if;\n",num_line, num_column);}
option_else_sequence_of_statements : ELSE_TOKEN sequence_of_statements	{fprintf(yyout, "RULE:\t option_else_sequence_of_statements <- else sequence of statments");}
			|									{fprintf(yyout,"line %d.%d\tRULE:\toption_else_sequence_of_statements with nothing\n",num_line, num_column);};

condition : boolean_expression					{fprintf(yyout,"line %d.%d\tRULE:\tcondition <- boolean_expression\n",num_line, num_column);}
			| error								{fprintf(yyout,"line %d.%d\tRULE:\tcondition with error\n",num_line, num_column);};

boolean_expression: expression					{fprintf(yyout,"line %d.%d\tRULE:\tboolean_expression<- expression\n",num_line, num_column);};


loop_statement : iteration_scheme LOOP_TOKEN		{fprintf(yyout,"line %d.%d\tRULE:\tloop_statement <- iteration_scheme loop\n",num_line, num_column);}
sequence_of_statements END_TOKEN LOOP_TOKEN';'		{fprintf(yyout,"line %d.%d\tRULE:\tloop_statement <- sequence_of_statements end loop;\n",num_line, num_column);};

iteration_scheme : WHILE_TOKEN condition		{fprintf(yyout,"line %d.%d\tRULE:\titeration_scheme <- while condition\n",num_line, num_column);}
			| FOR_TOKEN ID_VAR IN_TOKEN discrete_subtype_definition		{fprintf(yyout,"line %d.%d\tRULE:\tloop_parameter_specification <- defining_identifier in discrete_subtype_definition\n",num_line, num_column);};

subprogram_declaration : subprogram_specification';' 		{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_declaration <- subprogram_specification; \n",num_line, num_column);};

subprogram_specification : PROCEDURE_TOKEN defining_program_unit_name {actual=list_alloc();init(actual);addElem(&pila, actual);sym_push_scope();} formal_part		
			{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_specification <- procedure defining_program_unit_name(%s) parameter_profile\n",num_line, num_column, $<data>2->valor);$<data>2->type=ID_FUNCTION;$<data>2->params=$<listRule>4;
			fprintf(yyout,"line %d.%d\tTS:\tAssign parameters list to (%s)\n",num_line,num_column,$<data>2->valor);}
			|	FUNCTION_TOKEN defining_program_unit_name {actual=list_alloc();init(actual);addElem(&pila, actual);sym_push_scope();} formal_part	RETURN_TOKEN subtype_mark			
			{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_specification <- function defining_designator(%s) parameter_and_result_profile	\n",num_line, num_column, $<data>2->valor);$<data>2->type=ID_FUNCTION;$<data>2->params=$<listRule>4;$<data>2->semantic_type=$<data>6;
			fprintf(yyout,"line %d.%d\tTS:\tAssign parameters list and return type(%s) to (%s)\n",num_line,num_column,$<data>5->valor,$<data>2->valor);};

designator : IDENTIFIER		{fprintf(yyout,"line %d.%d\tRULE:\tdesignator <- identifier(%s)\n",num_line, num_column, $<data>1->valor);};


defining_program_unit_name : defining_identifier		{fprintf(yyout,"line %d.%d\tRULE:\tdefining_program_unit_name <- defining_identifier\n",num_line, num_column);};

formal_part : '(' parameter_specification rec_formal_part')'		
	{fprintf(yyout,"line %d.%d\tRULE:\tformal_part <- (parameter_specification rec_formal_part )\n",num_line, num_column);
		$<listRule>$=$<listRule>3;
		aux=getLast((list*)$<listRule>2);
		while(aux!=NULL){
			addFirstElem((list*)$<listRule>$,getContents(aux));
			aux=getPrev(aux);
		}
		 dealloc((list*)$<listRule>2); 
	}
			|				{fprintf(yyout,"line %d.%d\tRULE:\tformal_part <- (parameter_specification rec_formal_part )\n",num_line, num_column);$<listRule>$=list_alloc();init((list*)$<listRule>$);};
	
rec_formal_part :  ';' parameter_specification	rec_formal_part	
			{fprintf(yyout,"line %d.%d\tRULE:\trec_formal_part <- ; parameter_specification rec_formal_part\n",num_line, num_column);
				$<listRule>$=$<listRule>3;
				aux=getLast((list*)$<listRule>2);
				while(aux!=NULL){
					addFirstElem((list*)$<listRule>$,getContents(aux));
					aux=getPrev(aux);
				}
			dealloc((list*)$<listRule>2);};
			|				{fprintf(yyout, "line %d.%d\tRULE:\trec_formal_part with nothing \n",num_line, num_column);$<listRule>$=list_alloc();init($<listRule>$);};

parameter_specification : defining_identifier_list ':' subtype_mark 
		{fprintf(yyout,"line %d.%d\tRULE:\t parameter_specification <- defining_identifier_list : subtype_mark \n",num_line, num_column);
			$<listRule>$=list_alloc();
			init($<listRule>$);
			aux=getFirst($<listRule>1);
			while(aux!=NULL){
				var=(struct sym_node*)getContents((node*)aux);
				fprintf(yyout,"line %d.%d\tTS\t: changing type symbol(%s) to ID_VAR and semantic type to:(%s)\n",num_line,num_column,var->valor, $<data>3->valor);
				var->semantic_type=$<data>3;
				var->type=ID_VAR;
				aux=getNext(aux);
				addFirstElem($<listRule>$,$<data>3);
			}
		}
		|	error {$<listRule>$=list_alloc();init($<listRule>$);};

subprogram_body : 
	subprogram_specification IS_TOKEN		{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_body<-subprogram_specification is\n",num_line, num_column);}
	declarative_part								{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_body<- declarative_part\n",num_line, num_column);}
	BEGIN_TOKEN										{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_body<- begin\n",num_line, num_column);}
	sequence_of_statements							{fprintf(yyout,"line %d.%d\tRULE:\tsubprogram_body<- end [designator];\n",num_line, num_column);}
	END_TOKEN option_designator';'					{fprintf(yyout,"line %d.%d\tRULE:\tend [designator];\n",num_line, num_column); sym_pop_scope()}
		{
			list* llista_vars;
			node* nod_var;
			node* nod_llista_vars=getFirst(actual);  
			list* llista_symtab;
			sym_value_type* nod_llista_symtab;
			while (nod_llista_vars!=NULL) {
				llista_vars=(list*) getContents(nod_llista_vars);
				nod_var=getFirst(llista_vars);
				while(nod_var!=NULL){
					nod_llista_symtab=getContents(nod_var);
					if (nod_llista_symtab->params!=NULL){
						
						dealloc(nod_llista_symtab);
					}
					free(nod_llista_symtab);
					nod_var=getNext(nod_var);
				}
				dealloc(llista_vars);
				nod_llista_vars=getNext(nod_llista_vars);
			}
			dealloc(actual); aux=pop(&pila);free(aux);
			aux=getLast(&pila);actual=getContents(aux);};
		
option_designator: designator						{fprintf(yyout, "line %d.%d\tRULE:\toption_designator <- deisgnator\n",num_line, num_column);}
			|										{fprintf(yyout, "line %d.%d\tRULE:\toption_designator with nothing\n",num_line, num_column);};

procedure_call_statement : procedure_name actual_parameter_part ';'				
			{fprintf(yyout,"line %d.%d\tRULE:\tprocedure_call_statement <- procedure_name(%s) actual_parameter_part;\n",num_line, num_column, $<data>1->valor);
				aux2=getFirst((list*)$<listRule>2);
				aux=getFirst($<data>1->params);
				int count=1;
				while (aux!=NULL && aux2!=NULL){
					var2=(sym_name_type*)getContents(aux2);
					if (getContents(aux)!=var2->semantic_type){
						sym_value_type* tst=(sym_name_type*)getContents(aux);
						sym_value_type* tst2=var2->semantic_type;
						str=malloc(sizeof(char)*1024);sprintf(str, "the parameter %d of %s is %s but you pass variable '%s' of type %s",count, $<data>1->valor,tst->valor, var2->valor,tst2->valor);yyerror(str); free(str);
						dealloc($<listRule>2);
						YYERROR;
					}
					count++;
					aux=getNext(aux);
					aux2=getNext(aux2);
				}
				if (aux!=NULL || aux2!=NULL){
					str=malloc(sizeof(char)*1024);sprintf(str, "the number of parameters in procedure(%s) is incorrect", $<data>1->valor);yyerror(str); free(str);
					dealloc($<listRule>2);
					YYERROR;
				}
			}
	| error ;


procedure_name: ID_FUNCTION							{fprintf(yyout,"line %d.%d\tRULE:\tprocedure_name<- ID_FUNCTION(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1;};

function_call : function_name actual_parameter_part		{fprintf(yyout,"line %d.%d\tRULE:\tfunction_call <- function_name(%s) option_parameter\n",num_line, num_column,$<data>1->valor);
	aux2=getFirst((list*)$<listRule>2);
	aux=getFirst($<data>1->params);
	int count=1;
	while (aux!=NULL && aux2!=NULL){
		var2=(sym_name_type*)getContents(aux2);
		if (getContents(aux)!=var2->semantic_type){
			sym_value_type* tst=(sym_name_type*)getContents(aux);
			sym_value_type* tst2=var->semantic_type;
			str=malloc(sizeof(char)*1024);sprintf(str, "the parameter %d of %s is %s but you pass %s type",count, $<data>1->valor,tst->valor, var->valor,tst2->valor);yyerror(str); free(str);
			dealloc($<listRule>2);
			YYERROR;
		}
		count++;
		aux=getNext(aux);
		aux2=getNext(aux2);
	}
	if (aux!=NULL || aux2!=NULL){
		str=malloc(sizeof(char)*1024);sprintf(str, "the number of parameters in procedure(%s) is incorrect", $<data>1->valor);yyerror(str); free(str);
		dealloc($<listRule>2);
		YYERROR;
	}
			};
		//	| function_prefix actual_parameter_part		{fprintf(yyout,"line %d.%d\tRULE:\tfunction_prefixactual_parameter_part\n",num_line, num_column);};
//option_parameter: actual_parameter_part				{fprintf(yyout,"line %d.%d\tRULE:\toption_parameter <- actual_parameter (%s)\n",num_line, num_column,$<data>1->valor);}
		

function_name : ID_FUNCTION							{fprintf(yyout,"line %d.%d\tRULE:\tfunction_name<- ID_FUNCTION(%s)\n",num_line, num_column, $<data>1->valor);$<data>$=$<data>1};

actual_parameter_part : '('explicit_actual_parameter rec_actual_parameter_part ')'		{fprintf(yyout,"line %d.%d\tRULE:\tactual_parameter_part <- (explicit_actual_parameter rec_actual_parameter_part)\n",num_line, num_column);$<listRule>$=$<listRule>3;addFirstElem($<listRule>$, $<data>2);};
		|										{fprintf(yyout,"line %d.%d\tRULE:\toption_parameter with nothing\n",num_line, num_column); $<listRule>$=(struct list*)malloc(sizeof(list));}
	
	
rec_actual_parameter_part:  ',' explicit_actual_parameter rec_actual_parameter_part		
	{fprintf(yyout,"line %d.%d\tRULE:\trec_actual_parameter_part <- , explicit_actual_parameter rec_actual_parameter_part\n",num_line, num_column);$<listRule>$=$<listRule>3;addFirstElem($<listRule>$, $<data>2);}
		|											{fprintf(yyout,"line %d.%d\tRULE:\trec_actual_parameter_part with nothing\n",num_line, num_column);$<listRule>$=list_alloc(); init((list*)$<listRule>$);};

/* parameter_association : explicit_actual_parameter		{fprintf(yyout,"line %d.%d\tRULE:\texplicit_actual_parameter\n",num_line, num_column);}; */

explicit_actual_parameter : expression		{fprintf(yyout,"line %d.%d\tRULE:\texpression\n",num_line, num_column);$<data>$=$<data>1;$<data>$->valor="expression"}
		| variable_name		{fprintf(yyout,"line %d.%d\tRULE:\tvariable_name\n",num_line, num_column);$<data>$=$<data>1;};

return_statement : RETURN_TOKEN option_expression';'		{fprintf(yyout,"line %d.%d\tRULE:\treturn [expression];\n",num_line, num_column);};
option_expression: expression				{fprintf(yyout, "line %d.%d\tRULE:\toption_expression <- expression\n", num_line, num_column);}
			|								{fprintf(yyout,"line %d.%d\tRULE:\toption_expression with nothing\n",num_line, num_column);};

program : 
		{
			init(&pila);actual=list_alloc();init(actual);addElem(&pila, actual);
		}
	PROCEDURE_TOKEN defining_program_unit_name IS_TOKEN		{fprintf(yyout,"line %d.%d\tRULE:\tprogram <- procedure defining_program_unit_name is\n",num_line, num_column);}
	declarative_part						{fprintf(yyout,"line %d.%d\tRULE:\tprogram <- declarative_part\n",num_line, num_column);}
	BEGIN_TOKEN								{fprintf(yyout,"line %d.%d\tRULE:\tprogram <- begin\n",num_line, num_column);}
	sequence_of_statements					{fprintf(yyout,"line %d.%d\tRULE:\tprogram <- sequence of statements\n",num_line, num_column);}
	END_TOKEN option_designator ';'				{fprintf(yyout,"line %d.%d\tRULE:\tprogram <- end [designator];\n",num_line, num_column);};


%%



