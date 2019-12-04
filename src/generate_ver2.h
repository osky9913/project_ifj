#ifndef GENERATE_2_H
#define GENERATE_2_H


#include <string.h>
#include "dynamic_string.h"
#include "scanner.h"


// structure for implementing generator for output
typedef struct generate_strings_output{
    string_t *main;
    string_t *function_definitions;
    string_t *errors;
    string_t * stash;
} generate_strings_output_t;


// structure for iterating/generating uniq variables/labels id 
typedef struct uniq_id{
    size_t general ;
    size_t param_call ;
    size_t param_def ;
    size_t expression ;
    size_t general_label ;
    size_t while_label ;
    size_t if_label ;
    size_t concat_label ;
    size_t while_label_cnt ;
    size_t while_label_pos ;
    size_t label;
} uniq_id_t;

// for every string in generate strings output call string_init
int generate_strings_input_init();

/* call this function for a start of generating assembly,
   return SUCCESS if allocation was successfull
   return ALLOCATION_ERROR if wasn't
*/
int start_program();


// function for  ending generating program ,it will print assembly code 
void end_program();

// free all strings in assembly code 
void free_assembly_code();
// add token variable to frame
void append_token_variable_to_assembly(string_t * frame , token_t * variable);
// add string variable to frame
void append_string_variable_to_assembly(string_t *frame, const char *variable) ;


// call this function in expression for operation like ADD DIV , params are tokens as a operands , result is string
void append_token_operands_to_assembly(string_t *frame, string_t *result, token_t *operand1, token_t *operand2);


// call this function in expression for operation like ADD DIV , params are strings as a operands  , result is string
void append_string_operands_to_assembly(string_t *frame, string_t *result, string_t *operand1, string_t *operand2);

// is returning string from assembly_code
string_t * switch_frame();

// @todo ask simon or Marek for this magic function
string_t * switch_definitions_frame();


//  it generates the expression for every operation
char *generate_expression(token_t *operand1, token_t *operator, token_t *operand2);


// is adding CREATEFRAME to the code
void generate_create_frame();

// is adding popframe and return to function
void generate_function_end() ;


// generating the label , pushframe and the returnvalue variable
void generate_function(token_t *id);

// ???
void generate_print(const char * label );


// adding CALL ! to assembly code
void generate_call_function(const char *id);

// generating DEFVAR to new paramter and calling move
void generate_def_param(token_t *id);






#endif //GENERATE_2_H


