#ifndef MODULE_SYSTEM_H
#define MODULE_SYSTEM_H

#include <stdint.h>
#include <stddef.h>

typedef char* ms_identifier;
typedef uint32_t ms_int;
typedef ms_int ms_index;

/* String tuple */
typedef struct ms_string {
    ms_identifier identifier;
    char* string;
}ms_string;

/* Script tuples */

/* TODO: figure out how this is to be decompiled */
typedef size_t ms_comp_argument;

/* Compiled statement within a script tuple STATEMENT = "<OPCODE> <N> <argument1> <argument2> ... <argumentN>" */
typedef struct ms_comp_statement {
    ms_index opcode;
    ms_int narg;
    ms_comp_argument* args;
}ms_statement;

/* Compiled script tuple "<identifier> -1\n <length> <STATEMENT>*"*/
typedef struct ms_comp_script {
    ms_identifier identifier;
    ms_index length;
    ms_statement* statements;
}ms_script;

#endif