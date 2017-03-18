#include <type_check.h>

bool type_check(struct obj_struct *obj, int type) {
    return true;
}

void type_error_abort(void) {
    abort();
}
