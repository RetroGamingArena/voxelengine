#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 36) out;
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


in mat4 PVM[1];
in vec3 vertexPosition[1];
in vec3 fragmentColor[1];
in float fragmentAo[1];

out vec3 _fragmentColor;
out float _fragmentAo;

void main()
{
    float size = 0.25;
    
    int i;
    
    _fragmentColor = fragmentColor[0];
    _fragmentAo = fragmentAo[0];
    
    for (i = 0; i < gl_in.length(); i++)
    {
        vec3 position = vertexPosition[0];
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();

        position = vertexPosition[0];
        position.z+=size;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        position.x+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //===
        
        position = vertexPosition[0];
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //===
        
        position = vertexPosition[0];
        position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        position = vertexPosition[0];
        position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        position.x+=size;
        position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //===
        
        position = vertexPosition[0];
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        _fragmentAo = 0.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //===
        
        position = vertexPosition[0];
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //---
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        
        position = vertexPosition[0];
        position.x+=size;
        position.y+=size;
        position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
    }
}