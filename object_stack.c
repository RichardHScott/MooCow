#include <object_stack.h>

void object_stack_new(object_stack_t *new_stack, size_t initial_size) {
   new_stack->stack = moocow_alloc(sizeof(object*) * initial_size);
   new_stack->curr = 0;
   new_stack->max = initial_size;
}

void object_stack_delete(object_stack_t *stack) {
    for(size_t i=0; i<stack->curr; ++i) {
        DEC_REF(&stack->stack[i]);
    }

    free(stack->stack);
    stack->curr=0;
    stack->max=0;
}

object* object_stack_pop(object_stack_t *stack) {
    return (stack->curr) ? stack->stack[--stack->curr] : NULL;
}

static bool resize(object_stack_t *stack) {
    object **new_internal_stack = moocow_alloc(sizeof(object) * stack->max * 2);

    for(size_t i=0; i < stack->curr; ++i) {
        new_internal_stack[i] = stack->stack[i];
    }

    free(stack->stack);
    stack->stack = new_internal_stack;

    return true;
}

void object_stack_push(object_stack_t *stack, object **obj) {
    if(stack->curr == stack->max) {
        bool b = resize(stack);

        if(!b) {
            //error!
        }
    }
    
    stack->stack[stack->curr++] = *obj;
    obj = NULL;
}
