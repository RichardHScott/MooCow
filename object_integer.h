#ifndef MOOCOW_OBJECT_INTEGER_H
#define MOOCOW_OBJECT_INTEGER_H

#include <object.h>
#include <moocow_alloc.h>
#include <type_check.h>
#include <object_type.h>

typedef struct moocow_integer_object {
    OBJECT_BASE
    long long value;
} MC_Integer;

MC_Type *MC_Type_Integer;

void MC_integer_type_init(void);

#endif
