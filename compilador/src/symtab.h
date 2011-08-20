/* Copyright 1988 by GeoMaker Software                                      */
/* Written by Mark Grand                                                    */

/* This is the header file for use with the symbol table functions          */

/****************************************************************************/
/*                                                                          */
/*             #defines and typedefs to configure symtab                    */
/*                                                                          */
/****************************************************************************/
#ifndef symtabh
#define symtabh
//#include "../src/classes/clist.h";
#include "../src/classes/syntacticElement.h";
/*
typedef struct variable {
	char* valor;
	class_elem semantic_type;
};

typedef struct method {
	char* valor;
	//clist
}
 */
/* The type of the value field of symbol table entries                      */
typedef struct sym_node{
	SyntacticElement* element;
//	int def_line;
//	int type;
//	struct sym_node* semantic_type;
/*	int clase;  Aqui ha d'indicar el codi de clase*/
//	float real;
//	char* valor;
//	clist* params;	/*lista parametros en caso de funcion*/
} sym_value_type;          /* you will need to replace this    */

                                        /* with a declaration appropriate   */
                                        /* for your application.            */
					/*Ho subtituim per un unio o struct */
					/*Segons ens convingui.		    */
/* Uncomment the following define if bindings should point to rather than   */
/* contain values.                                                          */
// #define SYM_POINTS_TO_VALUE  
				/*Cada entrada sigui lexema i copia camp en */
				/*cada ranura.*/
				/*si traiem el comentari tinc un punter a la */
				/*ranura. En cas contrari tinc valor.*/


/* The type of the name field of symbol table entries                       */
typedef const char * sym_name_type;     /* If you are using something other */
                                        /* than a simple character array to */
                                        /* represent names you must         */
                                        /* redefine this.                   */

/* If sym_name_type is defined as something more complicated than a char *  */
/* then define sym_extract_name so that it derives a char * that points to  */
/* a name.                                                                  */
#define sym_extract_name(x) (x)

/* Name of comparison function.  Must take two parameters of type           */
/* sym_name_type and return zero if they are equal non-zero if not.         */
#define SYM_COMPARE_NAME_FUNCTION(a,b) strcmp(sym_extract_name(a),sym_extract_name(b))



/* The following macros are hooks for bookkeeping.                          */
/* SYM_ADD_SYMBOL_BOOKKEEPING is passed a sym_value_type * after it is added*/
#define SYM_ADD_VALUE_BOOKKEEPING(sym) 
			/*no fa res cal reimplementar.*/

/* SYM_REMOVE_VALUE_BOOKKEEPING is passed a sym_value_type * before it is   */
/* removed.                                                                 */
#define SYM_REMOVE_VALUE_BOOKKEEPING(sym) 
			/*No fa res cal reimplementar.*/

/* SYM_ADD_SYMBOL_BOOKKEEPING is passed a sym_name_type after it is added   */
#define SYM_ADD_NAME_BOOKKEEPING(name) 
		/*sym es funcio buida.*/
				/*sempre que actualitzis una ranura fara o*/
				/*cridara a aquesta funcio sym.*/
			/*a aquesta funcio li arriba el sym_value_type.*/

/* SYM_REMOVE_NAME_BOOKKEEPING is passed a sym_name_type before it is       */
/* removed.                                                                 */
#define SYM_REMOVE_NAME_BOOKKEEPING(name) 
		/*Cada cop que borres una ranura crida aquesta funcio*/
			/*per defecte no fa res.*/


/****************************************************************************/
/* SYM_BUCKET_MAX, defined below, is the number of buckets in the hash      */
/* table.  For best results, SYM_BUCKET_MAX should be a prime number.  For  */
/* your convenience, a selection of arbitrarily selected prime numbers      */
/* appears below.                                                           */
/* 97   157  223  269  307  359  409  461  509  563  613  661  727  797     */
/* 853  907  967  1019 1069 1097 1297 1381 1433 1483 1543 1597 1657 1709    */
/* 1723 1777 1847 1901 1951 2003 2053 2113 2179 2239 2293 2411 2503 2633    */
/****************************************************************************/

#define SYM_BUCKET_MAX 263
		/*nombre max d'entrades de la taula de dispersio que contindra*/
		/*les variables globals. Canviar si se'n volen mes.*/

/* Uncomment SYM_MULTIPLE_NAME_SPACES to support multiple name spaces.      */
#define SYM_MULTIPLE_NAME_SPACES 
		/*Per permetre duplicacio de noms. */
		/* int a;*/
		/* struct a;*/
		/* a=7;*/
		/*Per soportar duplicacio de noms al maateix ambit.*/
		/*En c utilitza un contador de registres!.*/
		/*has de definir corretament el llenguatge!*/
		/*Si es treu la clau es lexema + codi*/
		/*El codi ens indica quin struct es tracta.*/

/* Uncomment the following #define to enable nested name scoping.           */
 #define SYM_DEEP_BINDING    
	/*treure els comentaris si es vol treballar amb diferents ambits.*/
	/*per defecte comentat i vol dir un unic ambit.*/		

/* comment out SYM_SCOPE_STACK_DEPTH to store scope stack as linked         */
/* list instead of array */
#define SYM_SCOPE_STACK_DEPTH 100
	/*Implementa els ambits com una pila d'ambits. Nombre max de*/
	/*fondaria de la pila.*/
	/*per un interpet es millor tenir un arbre. El que haig de fer es */
	/*comentar el tamany de la pila.*/

/* Uncomment the following to make hash buckets and scopes self organizing  */
/* #define SYM_SELF_ORGANIZING_LISTS */


/* return values returned by symtab functions                               */
#define SYMTAB_NO_MEMORY (-1)    /* Unable to allocate memory for binding.  */
#define SYMTAB_OK 0              /* Normal return.                          */
#define SYMTAB_DUPLICATE 1       /* Name is already in symbol table.        */
#define SYMTAB_NOT_FOUND 2       /* Name was not found.                     */
#define SYMTAB_STACK_OVERFLOW 3  /* Attempt to exceed capacity of stack.    */
#define SYMTAB_STACK_UNDERFLOW 4 /* Attempt to pop back to a more global    */
                                 /* scope than the global scope.            */
#define SYMTAB_NOT_TOP 5         /* Attempt to pop scope that is not top of */
                                 /* stack.                                  */

/* Uncomment the following define if you want sym_pop_scope to be compiled  */
/* without a test for the current scope being top of stack                  */
/* #define SYM_NO_CHECK_POP                                                 */

/* Uncomment the following define if you want to use the sym_set_scope      */
/* function.  Commenting out SYM_SCOPE_STACK_DEPTH has the same effect.     */
/* #define SYM_REQUIRE_SET_SCOPE                                            */


/* Uncomment out the following define if you want to use sym_global_add(),    */
/* sym_global_enter(), sym_global_lookup() or sym_global_remove() functions */
/* If SYM_DEEP_BINDING is not defined, then these functions will be         */
/* not be available even if SYM_REQUIRE_GLOBAL is defined.                  */
#define SYM_REQUIRE_GLOBAL                                              


/* Uncomment the following to include sym_histogram in the compile          */
/* #define SYM_HISTOGRAM */


/****************************************************************************/
/*                                                                          */
/*                   end of #defines to configure symtab                    */
/*    Most configuration can be accomplished by editing lines above this.   */
/*                                                                          */
/****************************************************************************/


#if !defined(SYM_REQUIRE_SET_SCOPE) && !defined(SYM_SCOPE_STACK_DEPTH) && defined(SYM_DEEP_BINDING)
#define SYM_REQUIRE_SET_SCOPE
#endif

#if defined(SYM_DEEP_BINDING)
#ifdef SYM_SCOPE_STACK_DEPTH
/* configuration for scopes that obey stack discipline  */
typedef int sym_scope_id;
int sym_push_scope(void);
int sym_pop_scope(void);
#define sym_prev_scope(x) ((x)-1)
#define SYM_ROOT_SCOPE (-1)
#else
/* configuration for scopes that can be organized into trees    */
struct sym_scope_header
    {
    struct sym_scope_header * previous_scope;
    struct sym_binding * linked_list;
#ifdef SYM_NO_CHECK_POP
    short sym_check_pop;
#endif
    };
typedef struct sym_scope_header *sym_scope_id;
int sym_push_scope(sym_scope_id);
int sym_pop_scope(void);
#define SYM_ROOT_SCOPE ((sym_scope_id)0)
#define sym_prev_scope(x) ((x)->previous_scope)
#endif

extern const sym_scope_id *const current_scope;
#define sym_get_scope() (*current_scope);
#endif


#ifdef SYM_MULTIPLE_NAME_SPACES
int sym_add(sym_name_type  name,
            sym_value_type *value,
            unsigned name_space);
#else
int sym_add(sym_name_type  name,
            sym_value_type *value);
#endif


#ifdef SYM_MULTIPLE_NAME_SPACES
int sym_enter(sym_name_type  name,
              sym_value_type *value,
              unsigned name_space);
#else
int sym_enter(sym_name_type  name,
              sym_value_type *value);
#endif


int sym_lookup(sym_name_type  name,
#ifdef SYM_POINTS_TO_VALUE
               sym_value_type **value
#else
               sym_value_type *value
#endif
#ifdef SYM_MULTIPLE_NAME_SPACES
              ,unsigned name_space
#endif
                                  );


#ifdef SYM_MULTIPLE_NAME_SPACES
int sym_remove(sym_name_type  name, unsigned name_space);
#else
int sym_remove(sym_name_type  name);
#endif

#ifdef SYM_HISTOGRAM
void sym_histogram();
#endif

#if defined(SYM_REQUIRE_SET_SCOPE)
void sym_set_scope(sym_scope_id);
#endif

#if defined(SYM_DEEP_BINDING) && defined(SYM_REQUIRE_GLOBAL)
#ifdef SYM_MULTIPLE_NAME_SPACES
int sym_global_add(sym_name_type name,
                   sym_value_type *value,
                   unsigned name_space);

int sym_global_enter(sym_name_type name,
                     sym_value_type *value,
                     unsigned name_space);

int sym_global_lookup(sym_name_type name,
#ifdef SYM_POINTS_TO_VALUE
                      sym_value_type **value,
#else
                      sym_value_type *value,
#endif
                      unsigned name_space);

int sym_global_remove(sym_name_type  name, unsigned name_space);
#else
int sym_global_add(sym_name_type name, sym_value_type *value);
int sym_global_enter(sym_name_type name, sym_value_type *value);
#ifdef SYM_POINTS_TO_VALUE
int sym_global_lookup(sym_name_type name, sym_value_type **value);
#else
int sym_global_lookup(sym_name_type name, sym_value_type *value);
#endif
int sym_global_remove(sym_name_type name);
#endif
#endif
#endif
