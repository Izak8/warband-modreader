#ifndef MODULE_SYSTEM_TYPES_H
#define MODULE_SYSTEM_TYPES_H

#include <stdint.h>

/* Basic Types */

/* Integers can be 64-bit, however network message values must be 32-bit */
typedef uint32_t ms_int;
typedef char* ms_string;
typedef float ms_float;

/* module_strings.py */
typedef struct ms_strings_tuple {
    ms_string id;
    ms_string text;
}ms_strings_tuple;


#endif