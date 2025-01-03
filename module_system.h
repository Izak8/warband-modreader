#ifndef MODULE_SYSTEM_H
#define MODULE_SYSTEM_H

#include <stdint.h>
#include <stddef.h>

typedef char* ms_identifier;
typedef uint32_t ms_int;
typedef ms_int ms_index;
typedef float ms_ti_interval;

/* Strings */
typedef struct ms_comp_string {
    ms_identifier identifier;
    char* string;
}ms_string;

/* Scripts */

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
    ms_index blocklen;
    ms_statement* block;
}ms_script;

/* Simple Triggers */
typedef struct ms_comp_simple_trigger {
    ms_ti_interval interval;
    ms_index blocklen;
    ms_comp_statement* block;
}ms_comp_simple_trigger;

/* Regular Triggers */

/* rearm_interval can take a value 100000000.000000 which translates to constant ti_once */
#define TI_ONCE 100000000.000000

typedef struct ms_comp_trigger {
    ms_ti_interval check_interval;
    ms_ti_interval delay_interval;
    ms_ti_interval rearm_interval;

    ms_index blocklen_cond;
    ms_comp_statement* condblock;

    ms_index blocklen_cons;
    ms_comp_statement* consblock;

}ms_comp_trigger;

/* Factions */
typedef enum ms_fac_flags {
    FF_ALWAYS_HIDE_LABEL = 0x1
}ms_fac_flags;

/* Compiled relations list is a map which relates faction_id to a relation */
typedef struct ms_comp_relation_record {
    char* identifier;
    float relation;
}ms_comp_relation_record;

/* 32-bit Hex Colour Codes */
typedef uint32_t ms_colour;
/* Default faction colour is grey */
#define FAC_COL_DEFAULT 0xAAAAAA

/* Maximum factions constant */
#define MS_FACTION_MAX 128

typedef struct ms_comp_factions {
    char* identifier;
    char* name;
    ms_fac_flags flags;
    ms_colour colour;
    float coherence;
    ms_comp_relation_record* relations;
    /*Rank list? */
}ms_comp_factions;

#endif