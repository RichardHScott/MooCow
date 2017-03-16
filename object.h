#pragma once

#include <memory>

#include "object_impl.h"

namespace MooCow {

class Object {
	std::shared_ptr<ObjectImpl> impl;

public:
	Object() {
		impl = std::make_shared<ObjectImpl>();
	}

	virtual ~Object() {
	}

	Object(Object const& other) :
		impl(other.impl) {}
};

class IntegerPrimitive
	: public Object {

private:
	int value;

public:
	IntegerPrimitive(int i) : value(i) {
	}

	virtual ~IntegerPrimitive() {
	}

	IntegerPrimitive(IntegerPrimitive& other) :
		value(other.value) {
	}

	int getvalue() const {
		return value;
	}

	void setvalue(int value) {
		this->value = value;
	}
};

class StringPrimitive
	: public Object {

	std::string str;

public:
	StringPrimitive() {
	}

	std::string getvalue() const {
		return str;
	}

	void setvalue(std::string const& str) {
		this->str = str;
	}
};

}
