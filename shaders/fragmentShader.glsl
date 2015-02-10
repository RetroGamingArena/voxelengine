#version 330 core
in vec3 fragmentColor;
//in vec4 fragmentPosition;
in float fragmentAo;

out vec4 color;

uniform sampler2D myTextureSampler;

void main()
{
    float ao = fragmentAo;
    ao = min(1.0, ao);
    //ao = texture( myTextureSampler, vec2(1.0,1.0) )
    color = clamp(vec4(fragmentColor * ao, 1), vec4(0.0), vec4(1.0));//vec4(fragmentColor.rgb,1);//vec4(0, 1, 0, 1);
}