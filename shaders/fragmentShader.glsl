#version 330 core
in vec3 fragmentColor;
in vec3 cubeColor;
//in vec4 fragmentPosition;
in float fragmentAo;
in float _vertexWidth;

out vec4 color;

uniform sampler2D myTextureSampler;

void main()
{
    float ao = fragmentAo;
    //ao = min(1.0, ao);
    //ao = texture( myTextureSampler, vec2(1.0,1.0) )
    
    //color = vec4(fragmentColor, 1.0);//clamp(vec4(fragmentColor * ao, 1), vec4(0.0), vec4(1.0));//vec4(fragmentColor.rgb,1);//vec4(0, 1, 0, 1);
    
         if(mod(fragmentColor.r*2*_vertexWidth/16,1/16)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else if(mod(fragmentColor.g*2*_vertexWidth/16,1/16)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else if(mod(fragmentColor.b*2*_vertexWidth/16,1/16)<0.01)
        color  = vec4(0.0, 0.0, 0.0, 1.0);
    else
        color  = vec4(cubeColor, 1.0);
}