#include "object.h"
#include "opcodes.h"

#include <vector>
#include <stack>

namespace MooCow {

//Going to use primitive types or a composite object  
//INT, OBJECT (composite), FLOAT, STRING
//subclass the impl and overload a deref?

class ObjectFactory {
public:
	// static Object CreateCompositeObject() {}
	// static Object CreateStringObject() {}
	static Object* CreateIntegerObject(int i) {
		return new IntegerPrimitive(i);
	}
};

}

int curr_code = 0;
std::vector<int> ops = {
	0x10, 100,
	0x10, 200,
	0x1,
	0x20
};

int get_next_opcode() {
	return ops[curr_code++];
}

int get_arg() {
	return get_next_opcode();
}

int main(int argc, char *argv[]) {
	using namespace MooCow;

	std::stack<Object*> value_stack;

	Object heap;

	for(;;) {
		auto opcode = get_next_opcode();

		switch(opcode) {
			case NOP:
				break;

			case INTEGER_ADD:
			{
				auto x =  reinterpret_cast<IntegerPrimitive*>(value_stack.top());
				value_stack.pop();
				
				auto y = reinterpret_cast<IntegerPrimitive*>(value_stack.top());
				value_stack.pop();

				auto new_object = ObjectFactory::CreateIntegerObject(x->getvalue()+y->getvalue());
				value_stack.push(new_object);
				
				break;
			}
			case LOAD_CONST:
			{
				auto val = get_arg();
				value_stack.push(ObjectFactory::CreateIntegerObject(val));
				break;
			}
			case RETURN:
				return 0;
		}
	}

	return 0;
}
