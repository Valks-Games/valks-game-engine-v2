#pragma once

#include <typeinfo>

class Component 
{
public:
	const std::type_info& type;
public:
	Component(const std::type_info& type);
};