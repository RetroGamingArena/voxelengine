#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexColor;
layout(location = 2) in float ambiant;

out vec3 fragmentColor;
out vec4 fragmentPosition;
out float fragmentAo;

uniform mat4 MVP;

void main()
{
    gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
    fragmentAo = 0.3 + (1.0 - ambiant ) * 0.7;

    fragmentColor = vertexColor;
    fragmentPosition = gl_Position;
}