#ifndef MOOCOW_OBJECT_H
#define MOOCOW_OBJECT_H

#include <moocow_alloc.h>
#include <string.h>

enum object_type {
    NUMBER_TYPE,
    STRING_TYPE,

};

struct obj_struct;

typedef void (*delete_fn)(struct obj_struct**);

#define OBJECT_BASE \
    char *name; \
    enum object_type type; \
    size_t ref_count; \
    delete_fn del;

typedef struct obj_struct {
    OBJECT_BASE
} object;


void object_new(object** obj, const char* name);
void object_delete(object** obj);

#define INC_REF(x) (++(x)->ref_count);

#define DEC_REF(obj) \
{ \
    object *x = *obj; \
    x->ref_count--; \
    if(x->ref_count == 0) { \
        if(x->del != NULL) \
            (x->del)(obj); \
        object_delete(obj); \
    } \
} 

#endif
