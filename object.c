#include <object.h>

void object_new(object *obj, const char* name) {
    obj->name = strdup(name);
    obj->ref_count = 0;

    obj->type = NULL;
}

void object_delete(object *obj) {
    if(obj->name != NULL) {
        free(obj->name);
        obj->name = NULL;
    }
}

object* object_add(object *obj1, object *obj2) {
    if(obj1->type->binary_add == NULL) {
        type_error_abort();
    }

    return (obj1->type->binary_add)(obj1, obj2);
}


object* object_mul(object *obj1, object *obj2) {
    if(obj1->type->binary_mul == NULL) {
        type_error_abort();
    }

    return (obj1->type->binary_mul)(obj1, obj2);
}

object* object_negate(object *obj) {
    if(obj->type->unary_negate == NULL) {
        type_error_abort();
    }

    return (obj->type->unary_negate)(obj);
}
