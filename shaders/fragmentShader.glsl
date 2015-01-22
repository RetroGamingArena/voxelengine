#version 330 core
//in vec3 fragmentColor;
//in vec4 fragmentPosition;
//in float fragmentAo;

out vec4 color;

void main()
{
    //float ao = fragmentAo;
    //ao = min(1.0, ao);
    
    color = vec4(0.0,0.0,0.0,1.0);//clamp(vec4(fragmentColor * fragmentAo, 1), vec4(0.0), vec4(1.0));//vec4(fragmentColor.rgb,1);//vec4(0, 1, 0, 1);
}