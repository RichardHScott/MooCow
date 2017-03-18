#ifndef MOOCOW_OBJECT_H
#define MOOCOW_OBJECT_H

#include <moocow_alloc.h>
#include <string.h>
#include <type_check.h>


struct object_type_struct;

#define OBJECT_BASE \
    char *name; \
    struct object_type_struct *type; \
    size_t ref_count; \

typedef struct object_struct {
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
        if((obj)->type->del != NULL) \
            ((obj)->type->del)(obj); \
    } \
} 

object* object_add(object *obj1, object *obj2);
object* object_mul(object *obj1, object *obj2);
object* object_negate(object *obj);

typedef object* (*new_fn)(const char* name);
typedef void (*delete_fn)(struct object_struct*);
typedef struct object_struct* (*add_fn)(struct object_struct*, struct object_struct*);
typedef struct object_struct* (*negate_fn)(struct object_struct*);
typedef struct object_struct* (*mul_fn)(struct object_struct*, struct object_struct*);

typedef struct object_type_struct {
    OBJECT_BASE
    new_fn new;
    delete_fn del;
    add_fn binary_add;
    negate_fn unary_negate;
    mul_fn binary_mul;
} MC_Type;

#endif
