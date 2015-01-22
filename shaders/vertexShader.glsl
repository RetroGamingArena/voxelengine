#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in float vertexColorIndex;
layout(location = 2) in float ambiant;

//out vec3 fragmentPosition;
out vec3 fragmentColor;
out float fragmentAo;

uniform mat4 MVP;

uniform mat4 M;
uniform mat4 V;
uniform mat4 P;

uniform mat4x3 cameraUnprojection;

uniform vec3 cameraPosition;

void main()
{
    gl_Position = /*MVP*/ P * V * M * vec4(vertexPosition_modelspace,1);
    fragmentAo = 0.3 + (1.0 - ambiant ) * 0.7;

    fragmentColor = vec3(1.0,1.0,1.0);//noise1(1));
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
    
    //fragmentPosition = vertexPosition_modelspace;
    //fragmentColor = vec3(1.0,1.0,mod(vertexPosition_modelspace.x,16)/16);
    //_cameraPosition=cameraPosition;
    //_cameraUnprojection=cameraUnprojection;
    //fragmentPosition = gl_Position;
}