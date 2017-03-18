#ifndef MOOCOW_TYPE_CHECK_H
#define MOOCOW_TYPE_CHECK_H

#include <stdbool.h>
#include <stdlib.h>

struct obj_struct;

bool type_check(struct obj_struct *obj, int);
void type_error_abort();

#endif
