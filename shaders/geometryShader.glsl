#version 330 core

layout (points) in;
layout (triangle_strip, max_vertices = 24) out;

in mat4 PVM[1];
in vec4 vertexPosition[1];
in vec3 fragmentColor[1];
in float fragmentAo[1];

out vec3 _fragmentColor;
out float _fragmentAo;

void main()
{
    float size = 0.125;
    
    int i;
    
    _fragmentColor = fragmentColor[0];
    _fragmentAo = fragmentAo[0];
    
    mat4 bottom_model = mat4( vec4(0.0,0.0,0.0,1.0), vec4(1.0,0.0,0.0,1.0), vec4(0.0,0.0,1.0,1.0), vec4(1.0,0.0,1.0,1.0) ) + mat4(vertexPosition[0], vertexPosition[0], vertexPosition[0], vertexPosition[0]);
    mat4 top_model    = mat4( vec4(0.0,1.0,0.0,1.0), vec4(1.0,1.0,0.0,1.0), vec4(0.0,1.0,1.0,1.0), vec4(1.0,1.0,1.0,1.0) ) + mat4(vertexPosition[0], vertexPosition[0], vertexPosition[0], vertexPosition[0]);
    
    mat4 bottom = PVM[0]*bottom_model;
    mat4    top = PVM[0]*top_model;
    
    for (i = 0; i < gl_in.length(); i++)
    {
        //vec4 position = vertexPosition[0];
        _fragmentAo = 0.0;
        gl_Position = bottom[0];//PVM[0]*(position+vec4(0.0,0.0,0.0,1.0));
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[1];//PVM[0]*(position+vec4(1.0,0.0,0.0,1.0));
        EmitVertex();

        //position = vertexPosition[0];
        //position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[2];//PVM[0]*(position+vec4(0.0,0.0,1.0,1.0));
        EmitVertex();
        //EndPrimitive();
        
        //---
        
        //position = vertexPosition[0];
        //position.x+=size;
        
        //_fragmentAo = 1.0;
        _fragmentAo = 0.0;
        gl_Position = bottom[3];//PVM[0]*(position+vec4(1.0,0.0,0.0,1.0));
        EmitVertex();
        EndPrimitive();
        
        
        
        //position = vertexPosition[0];
        //position.z+=size;
        
        //_fragmentAo = 1.0;
        _fragmentAo = 0.0;
        gl_Position = bottom[0];//PVM[0]*(position+vec4(0.0,0.0,1.0,1.0));
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.z+=size;
        
        //_fragmentAo = 1.0;
        _fragmentAo = 0.0;
        gl_Position = bottom[1];//PVM[0]*(position+vec4(1.0,0.0,1.0,1.0));
        EmitVertex();
        
        
        //===
        
        //position = vertexPosition[0];
        _fragmentAo = 1.0;
        gl_Position = top[0];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 1.0;
        gl_Position = top[1];//PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        
        
        
        
        
        
        //position = vertexPosition[0];
        //position.y+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[1];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        
        //---
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[3];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = top[1];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.y+=size;
        _fragmentAo = 1.0;
        gl_Position = top[3];//PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        //===
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[2];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[3];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.y+=size;
        //position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = top[2];//PVM[0]*vec4(position,1);
        EmitVertex();
        //EndPrimitive();
        
        //---
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 1.0;
        gl_Position = top[3];//PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        
        
    
        //position = vertexPosition[0];
        //position.x+=size;
        //position.y+=size;
        //position.z+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[0];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.y+=size;
        _fragmentAo = 0.0;
        gl_Position = bottom[2];//PVM[0]*vec4(position,1);
        EmitVertex();
        //EndPrimitive();
        
        //position = vertexPosition[0];
        //position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = top[0];//PVM[0]*vec4(position,1);
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        //position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = top[2];//PVM[0]*vec4(position,1);
        EmitVertex();
        EndPrimitive();
        
        
         
        //vec4 position = vertexPosition[0];
        _fragmentAo = 1.0;
        gl_Position = top[0];//PVM[0]*(position+vec4(0.0,0.0,0.0,1.0));
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.x+=size;
        _fragmentAo = 1.0;
        gl_Position = top[1];//PVM[0]*(position+vec4(1.0,0.0,0.0,1.0));
        EmitVertex();
        
        //position = vertexPosition[0];
        //position.z+=size;
        _fragmentAo = 1.0;
        gl_Position = top[2];//PVM[0]*(position+vec4(0.0,0.0,1.0,1.0));
        EmitVertex();
        //EndPrimitive();
        
        //---
        
        //position = vertexPosition[0];
        //position.x+=size;
        
        _fragmentAo = 1.0;
        gl_Position = top[3];//PVM[0]*(position+vec4(1.0,0.0,0.0,1.0));
        EmitVertex();
        EndPrimitive();
    }
}