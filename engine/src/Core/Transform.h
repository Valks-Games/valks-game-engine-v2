#pragma once

#include "Component.h"
#include "../Math/Math.h"

class Transform : public Component
{
public:
	glm::fvec3 localPosition = glm::fvec3(0, 0, 0);

public:
	Transform();
};