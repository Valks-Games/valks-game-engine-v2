out vec4 FragColor;
in vec3 color;
in vec3 pos;

void main()
{
	FragColor = vec4(color, 1.0);
}