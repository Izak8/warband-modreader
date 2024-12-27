#ifndef MODULE_SYSTEM_TYPES_H
#define MODULE_SYSTEM_TYPES_H

#include <stdint.h>

/* Basic Types */

/* Integers can be 64-bit, however when networked values must be 32-bit */
typedef uint32_t ms_int;
typedef char* ms_string;
typedef float ms_float;


#endif