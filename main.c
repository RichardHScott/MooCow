#include <object.h>
#include <opcodes.h>
#include <object_stack.h>

#include <stdio.h>

int curr_code = 0;
int ops[] = {1,2,3};

int get_next_opcode() {
	return ops[curr_code++];
}

int get_arg() {
	return get_next_opcode();
}

int main(int argc, char *argv[]) {
    object_stack_t value_stack;
    object_stack_new(&value_stack, 8);

    printf("Curr size: %d\n", value_stack.curr);
    object *new_obj;
    object_new(&new_obj, "name1");
    INC_REF(new_obj);
    object_stack_push(&value_stack, &new_obj);

    printf("Curr size: %d\n", value_stack.curr);
    object_new(&new_obj, "name2");
    INC_REF(new_obj);
    object_stack_push(&value_stack, &new_obj);

    object *obj = object_stack_pop(&value_stack);
    printf("Object name: %s", obj->name);
    DEC_REF(&obj);

	for(;;) {
        break;
		int opcode = get_next_opcode();

		switch(opcode) {
			case NOP:
				break;

			case INTEGER_ADD:
				
				break;
			case LOAD_CONST:
				break;
			case RETURN:
				return 0;
		}
	}

    printf("Curr size: %d\n", value_stack.curr);

    obj = object_stack_pop(&value_stack);
    printf("Object name: %s", obj->name);
    DEC_REF(&obj);

    printf("Curr size: %d\n", value_stack.curr);

    object_stack_delete(&value_stack);

	return 0;
}
