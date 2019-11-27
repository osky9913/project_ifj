#ifndef GENERATE_H
#define GENERATE_H

#include <string.h>
#include "dynamic_string.h"
#include "scanner.h"

void start_program();

void printing_frame_to_variable(string_t *frame);

void printing_token_to_frame(string_t *frame, token_t *operand);
void adding_operands(string_t *frame, string_t *result, token_t *operand1, token_t *operand2);

void adding_operands_string(string_t *frame, string_t *result, string_t *operand1, string_t *operand2);

void define_uniq_variable(string_t *variable, string_t *output_string, int *uniq, char *name);

void get_type_variable(string_t *id_type, string_t *output_string, token_t *operand);

char *generate_expression(token_t *operand1, token_t *operator, token_t *operand2);

void generate_create_frame();

void generate_function(token_t *id);

void generate_call_function(token_t *id);

void generate_def_param(token_t *id);

void generate_call_param(token_t *id);

void generate_function_end(token_t *id);

void generate_function_end_no_return(token_t *id);

void generate_while_lable();

void generate_while(token_t *expression);

void generate_while_end();

void generate_if(token_t *expression);

void generate_else();

void generate_assign(token_t *destination, token_t *content);

void declaration_variable(token_t *variable);


void end_program();
#endif //GENERATE_H