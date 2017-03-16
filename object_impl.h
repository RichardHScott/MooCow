#pragma once

#include <string>
#include <map>

namespace MooCow {

class Object;

class ObjectImpl {
public:
	std::string name;
	std::map<std::string, Object> elements;
};

}