#ifndef OBJECT_STACK_H
#define OBJECT_STACK_H

#include <object.h>
#include <moocow_alloc.h>
#include <stdbool.h>

typedef struct {
    object **stack;
    size_t max;
    size_t curr;
} object_stack_t;

void object_stack_new(object_stack_t *new_stack, size_t initial_size);
void object_stack_delete(object_stack_t *stack);

object* object_stack_pop(object_stack_t *stack);
void object_stack_push(object_stack_t *stack, object **obj);

#endif
