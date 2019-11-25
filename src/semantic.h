/**
 *	@file   semantic.h
 *	@author Simon Sedlacek, xsedla1h
 *	@date
 *	@brief Header file for semantic actions module
 */

#ifndef __SEMANTIC_H__
#define __SEMANTIC_H__

#include "parser.h"
#include "symtable.h"

#define SYMBOL_NOT_FOUND 66 
#define VARIABLE_FOUND 67
#define FUNCTION_FOUND 68
#define UNDEF_FUNCTION_FOUND 69
#define NEW_VARIABLE 70

int add_undefined_function(const char *id);

/**
 * @brief Checks if all functions called within this function are actually
 * defined.
 */
int check_function_dependencies(symbol_t *function);

/**
 */
int check_and_add_parameter_def(const char *id);

/**
 */
int define_function(const char *id);

/**
 */
int add_symbol_var(const char *id);

/**
 * @brief Checks if a symbol with the identifier id has already been defined. If
 * the current scope is inside a function, the function first searches the local
 * symtable and if unsuccesful, it needs to search the global table. If succesful there,
 * the function then creates an undefined local variable used to check for a unauthorised
 * definition of a local variable of the same name.
 *
 * @return Returns VARIABLE_FOUND on success and FUNCTION_FOUND when it finds a function.
 * Otherwise, returns SYMBOL_NOT_FOUND.
 */
int check_if_defined_var(const char *id);

/**
 */
int check_if_defined_func(const char *id);

/**
 * @brief This functions checks if the token passed to it is an identifier
 * and if so, it searches the relevant symbol table in order to check if it
 * is a variable and if it has been defined.
 *
 * @return Returns SUCCESS if the parameter is a valid variable, otherwise returns
 * ERROR_SEM_DEFINITION.
 */
int check_parameter_valid(token_t token);

/**
 * @brief Adds all the built in functions to the global symtable.
 */
int add_built_in_functions();

#endif
