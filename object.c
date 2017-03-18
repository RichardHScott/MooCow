#include <object.h>

#include <stdio.h>

void object_new(object **obj,
    const char* name) {
    *obj = moocow_alloc(sizeof(object));

    object *p = *obj;

    p->name = strdup(name);
    p->ref_count = 0;

    p->del = NULL;
}

void object_delete(object **obj) {
    object* p = *obj;

    if(p->name != NULL) {
        free(p->name);
    }

    p = NULL;
}
