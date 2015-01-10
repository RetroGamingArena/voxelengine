#version 330 core
in vec3 fragmentColor;
in vec4 fragmentPosition;
in float fragmentAo;

out vec3 color;

void main()
{
    float ao = fragmentAo;
    ao = min(1.0, ao);
    color = clamp(fragmentColor * fragmentAo, vec3(0.0), vec3(1.0));
}