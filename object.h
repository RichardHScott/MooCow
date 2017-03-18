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
typedef obj_struct* (*add_fn)(struct obj_struct*, struct obj_struct*);
typedef obj_struct* (*negate_fn)(struct obj_struct*);
typedef obj_struct* (*mul_fn)(struct obj_struct*, struct obj_struct*);

#define OBJECT_BASE \
    char *name; \
    enum object_type type; \
    size_t ref_count; \
    delete_fn del; \
    add_fn binary_add; \
    negate_fn unary_negate; \
    mul_fn binary_mul;  

typedef struct obj_struct {
    OBJECT_BASE
} object;


void object_new(object* obj, const char* name);
void object_delete(object* obj);

#define INC_REF(x) (++(x)->ref_count);

#define DEC_REF(obj) \
{ \
    (obj)->ref_count--; \
    if((obj)->ref_count == 0) { \
        object_delete(obj); \
        if(x->del != NULL) \
            (x->del)(obj); \
    } \
} 

object* object_add(object *obj1, object *obj2);
object* object_mul(object *obj1, object *obj2);
object* object_negate(object *obj);

#endif
