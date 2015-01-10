#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in float vertexColorIndex;
layout(location = 2) in float ambiant;

out vec3 fragmentColor;
out vec4 fragmentPosition;
out float fragmentAo;

uniform mat4 MVP;

void main()
{
    gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
    fragmentAo = 0.3 + (1.0 - ambiant ) * 0.7;

    fragmentColor = vec3(1.0,1.0,1.0);
    if(vertexColorIndex == 1)
        fragmentColor = vec3(0.0,1.0,0.0);
    else if(vertexColorIndex == 2)
        fragmentColor = vec3(0.0,0.0,1.0);
    else if(vertexColorIndex == 3)
        fragmentColor = vec3(1.0,1.0,0.0);
    else if(vertexColorIndex == 4)
        fragmentColor = vec3(0.3,0.3,0.0);
    else if(vertexColorIndex == 5)
        fragmentColor = vec3(0.5,0.5,0.5);

    fragmentPosition = gl_Position;
}