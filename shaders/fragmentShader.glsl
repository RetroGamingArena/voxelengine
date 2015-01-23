#version 330 core
in vec3 _fragmentColor;
//in vec4 fragmentPosition;
in float _fragmentAo;

out vec4 color;

void main()
{
    float ao = _fragmentAo;
    ao = min(1.0, ao);
    
    color = clamp(vec4(_fragmentColor * ao, 1), vec4(0.0), vec4(1.0));//vec4(fragmentColor.rgb,1);//vec4(0, 1, 0, 1);
}