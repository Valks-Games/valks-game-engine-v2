#include "GameObject.h"

GameObject::GameObject() 
{
	
}

void GameObject::AddComponent(Component* component) 
{
	components.push_back(component);
}

//Component GameObject::GetComponent() 
//{
//	return 0;
//}