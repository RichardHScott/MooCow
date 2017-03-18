#include <object_integer.h>

static void delete(object** obj) {
}

static object* binary_add(object *obj1, object *obj2) {
    if(!type_check(obj1, NUMBER_TYPE)) {
    }

    if(!type_check(obj2, NUMBER_TYPE)) {
    }

    MC_integer *u = (MC_Integer*)(obj1);
    MC_integer *v = (MC_Integer*)(obj2);
    MC_Integer *result = MC_Integer_new(void);
    
    result->value = u->value + v->value;
}

static object* binary_mul(object *obj1, object *obj2) {
    if(!type_check(obj1, NUMBER_TYPE)) {
    }

    if(!type_check(obj2, NUMBER_TYPE)) {
    }

    MC_integer *u = (MC_Integer*)(obj1);
    MC_integer *v = (MC_Integer*)(obj2);
    MC_Integer *result = MC_Integer_new(void);
    
    result->value = u->value * v->value; 
    return result;
}

static object* negate(object *obj) {
    if(!type_check(obj1, NUMBER_TYPE)) {
    }

    MC_Integer *u = (MC_Integer*)obj;

    MC_Integer *result = MC_Integer_new(void);

    result->value = -u->value;
    return result;
}

MC_Integer* MC_Integer_new(void) {
    MC_Integer *obj = moocow_alloc(sizeof(MC_Integer));
    object_new((object*)obj, name);

    obj->type = NUMBER_TYPE;
    obj->value = 0;

    obj->binary_add = binary_add;
    obj->binary_mul = binary_mul;
    obj->unary_negate = negate;

    if(obj == NULL) {
    }

}
