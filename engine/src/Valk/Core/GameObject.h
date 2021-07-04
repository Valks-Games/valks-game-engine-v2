#pragma once

#include "Component.h"
#include <typeinfo>

class GameObject 
{
private:
	std::vector<Component*> components;

public:
	GameObject();

public:
	void AddComponent(Component* component);

	template <typename T>
	T* GetComponent()
	{
		const std::type_info& type = typeid(T);

		for (auto comp : components) 
		{
			if (comp->type == type)
				return reinterpret_cast<T*>(comp);
		}
			

		return nullptr;
	}
};