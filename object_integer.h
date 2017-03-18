#ifndef MOOCOW_OBJECT_INTEGER_H
#define MOOCOW_OBJECT_INTEGER_H

#include <object.h>
#include <moocow_malloc.h>

typedef struct moocow_integer_object {
    OBJECTBASE
    long long value;
} MC_Integer;

MC_Integer* MC_Integer_new(void);

#endif
