#include <object_type.h>

MC_Type *MC_Type_Type;

//typedef object* (*new)(const char* name);

object* MC_type_create(const char* type_name) {
    object *type = moocow_alloc(sizeof(MC_Type));
    object_new((object*)type, type_name);

    type->type = MC_Type_Type;
}

void MC_type_type_init(void) {
    MC_Type_Type = MC_type_create("TypeType");
    MC_Type_Type->type = MC_Type_Type;
    MC_Type_Type->type->new = MC_type_create;
}

