#version 330 core
in vec3 fragmentColor;
in vec4 fragmentPosition;

out vec3 color;

void main()
{
    color = fragmentColor;
}