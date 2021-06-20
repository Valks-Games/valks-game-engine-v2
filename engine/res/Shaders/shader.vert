layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

//out vec3 color;
out vec3 pos;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(aPos, 1.0);
	//color = aColor;
	pos = aPos;
}