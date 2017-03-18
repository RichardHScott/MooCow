#include <object_integer.h>

static object* binary_add(object *obj1, object *obj2) {
    MC_Integer *u = (MC_Integer*)(obj1);
    MC_Integer *v = (MC_Integer*)(obj2);

    MC_Integer *result = (MC_Integer*) (MC_Type_Integer)->new("");
    
    result->value = u->value + v->value;
}

static object* binary_mul(object *obj1, object *obj2) {
    MC_Integer *u = (MC_Integer*)(obj1);
    MC_Integer *v = (MC_Integer*)(obj2);
    MC_Integer *result = (MC_Integer*) (MC_Type_Integer)->new("");
    
    result->value = u->value * v->value; 
    return result;
}

static object* negate(object *obj) {
    MC_Integer *u = (MC_Integer*)obj;

    MC_Integer *result = (MC_Integer*) (MC_Type_Integer)->new("");

    result->value = -u->value;
    return result;
}

static object* MC_Integer_new(const char* name) {
    MC_Integer *obj = moocow_alloc(sizeof(MC_Integer));

    object_new((object*)obj, name);

    obj->type = MC_Type_Integer;
    obj->value = 0;

    if(obj == NULL) {
    }

    return obj;
}

void MC_integer_type_init(void) {
    MC_Type_Integer = (MC_Type_Type->new)("IntegerType");

    MC_Type_Integer->new = MC_Integer_new;

    MC_Type_Integer->binary_add = binary_add;
    MC_Type_Integer->binary_mul = binary_mul;
    MC_Type_Integer->unary_negate = negate;
}

