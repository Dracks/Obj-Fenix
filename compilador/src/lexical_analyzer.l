DIGIT [0-9]
LETTER [a-zA-Z]
NUMERAL {DIGIT}(("_")?{DIGIT}+)*
EXPONENT E[+-]?{NUMERAL}
STRING_LITERAL \"([^\"\0-\37]?(\"\")?)*\"

%{
/*"*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "../build/syntactic_parser.h"
#include "../src/main.h"
#include "../src/tools.h"
#include "../src/debug.h"
#include "../src/classes/clist.h"
#include "../src/debug.h"
#include "../src/symtab.h"

sym_value_type* var;
extern char* parsing_file;
/* extern int espai_actual;*/

/*num_column += yyleng;  tratamiento de numeros de linea y de caracter. */
/*"<="			{ num_column += yyleng; yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng); return LE_OP;}
 ">="			{ num_column += yyleng; yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng); return GE_OP;}
 "/="			{ num_column += yyleng; yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng); return DIF_OP;}
 "**"			{ num_column += yyleng; yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng); return POT_OP;}
 ".."			{ num_column += yyleng; yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng); return DOS_PUNTOS;}
 */

%}

%x comments
%%
" "*				{num_column+=yyleng;}
"	"*				{num_column+=yyleng;}
"//"[^\n]*			{num_column += yyleng;}



"/*"			{ num_column+=2; BEGIN(comments); }
<comments>[^*\n]*	{num_column += yyleng; /* menja tot el que no sigui '*' */}
<comments>"*"+[^*/\n]*	{num_column += yyleng; /* menja '*' no seguits per '/' */}
<comments>\n		{num_line++; num_column = 1;}
<comments>"*"+"/"	{num_column+=2; BEGIN(INITIAL);}


\n					{num_column=1; num_line+=1;}


{NUMERAL}								{
/*yylval.data=(sym_node*)newElem();	yylval.data->valor=copyTag(yytext,yyleng);	yylval.data->real=toNumber(yytext);	yylval.data->type=NUMERIC_LITERAL;/*sym_lookup("INTEGER", &var, 0); yylval.data->semantic_type=var; 	num_column += yyleng; /*return NUMERIC_LITERAL*/; 
	yylval.data=new SyntacticElement(yytext,CONSTANT_VALUE, num_line, parsing_file);
	//printf("integer\n");
	yylval.data->setSemantic(insertToken("Integer", IDENTIFIER, 0));	
	num_column += yyleng;
	return CONSTANT_VALUE;
}
{NUMERAL}("."{NUMERAL})?{EXPONENT}?		{
/*yylval.data=(sym_node*)newElem();	yylval.data->valor=copyTag(yytext,yyleng);	yylval.data->real=toNumber(yytext);	yylval.data->type=NUMERIC_LITERAL;/*sym_lookup("FLOAT", &var, 0); yylval.data->semantic_type=var; 	num_column += yyleng; /*return NUMERIC_LITERAL*/;
	yylval.data=new SyntacticElement(yytext,CONSTANT_VALUE, num_line, parsing_file);
	yylval.data->setSemantic(insertToken("Float", IDENTIFIER, 0));
	num_column += yyleng;
	return CONSTANT_VALUE;
}

{LETTER}(("_")?([a-zA-Z0-9])+)*			{num_column +=yyleng; return addElement(strCopy(yytext), IDENTIFIER);}
"="										{num_column ++; yylval.data=insertToken("equal", IDENTIFIER);  return IDENTIFIER; }
"!="									{num_column ++; yylval.data=insertToken("dif", IDENTIFIER);  return IDENTIFIER; }
"+"										{num_column ++; yylval.data=insertToken("add", IDENTIFIER);  return IDENTIFIER; }
"-"										{num_column ++; yylval.data=insertToken("sub", IDENTIFIER);  return IDENTIFIER; }
"*"										{num_column ++; yylval.data=insertToken("mul", IDENTIFIER);  return IDENTIFIER; }
"/"										{num_column ++; yylval.data=insertToken("div", IDENTIFIER);  return IDENTIFIER; }
"<"										{num_column ++; yylval.data=insertToken("lower", IDENTIFIER);  return IDENTIFIER; }
">"										{num_column ++; yylval.data=insertToken("greater", IDENTIFIER);  return IDENTIFIER; }

'[\40-\177]'							{
/*yylval.data=(sym_node*)newElem();yylval.data->valor=copyTag(yytext,yyleng);yylval.data->type=CHARACTER_LITERAL;/*sym_lookup("CHARACTER", &var, 0); yylval.data->semantic_type=var;*/
	yylval.data=new SyntacticElement(yytext,CONSTANT_VALUE, num_line, parsing_file);
		yylval.data->setSemantic(insertToken("string", IDENTIFIER, 0));
	num_column += yyleng; /*return CHARACTER_LITERAL;*/
	return CONSTANT_VALUE;
}

{STRING_LITERAL}						{

	yylval.data=new SyntacticElement(parseStringInput(yytext),CONSTANT_VALUE, num_line, parsing_file);
	yylval.data->setSemantic(insertToken("string", IDENTIFIER, 0));
	num_column += yyleng; /*return STRING_LITERAL;*/
	return CONSTANT_VALUE;
}

[\(-\/]|[\:-\>]|&						{num_column ++; /*printf("Debug %s\n", yytext);*/return yytext[0];}
":="									{num_column += yyleng; /*yylval.data=newElem();yylval.data->valor=copyTag(yytext,yyleng);*/ return ASSIG;}
.							{num_column +=yyleng; return LEXICAL_ERROR;}

%%

