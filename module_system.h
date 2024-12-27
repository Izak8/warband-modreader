#ifndef MODULE_SYSTEM_H
#define MODULE_SYSTEM_H

#include <stdint.h>

typedef char* ms_identifier;
typedef uint32_t ms_int;
typedef ms_int ms_index;

typedef struct ms_string {
    ms_identifier identifier;
    char* string;
}ms_string;


#endif