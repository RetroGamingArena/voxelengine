#version 330 core

layout (points) in;
layout (points, max_vertices = 1) out;
//layout (max_vertices = 4) out;

//layout(fragmentPosition) in;

/*layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inCoord;
layout (location = 2) in vec3 inNormal;

out vec2 vTexCoordPass;
out vec3 vNormalPass;*/

//in vec3 fragmentColor;//
//in float fragmentAo;

//in vec3 fragmentPosition[3];
//in vec3 fragmentColor[3];
//in float fragmentAo[3];

//out vec3 _fragmentColor;
//out float _fragmentAo;

void main()
{
    int i;
    
    for (i = 0; i < gl_in.length(); i++)
    {
        gl_Position = gl_in[i].gl_Position;
        EmitVertex();
        EndPrimitive();
        
        gl_Position.y = gl_Position.y+20;
        EmitVertex();
        EndPrimitive();
        
    }
    //EndPrimitive();
}