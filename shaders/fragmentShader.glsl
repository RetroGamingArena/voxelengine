#version 330 core
in vec3 fragmentColor;
//in vec4 fragmentPosition;
in float fragmentAo;

in mat4 _M;
in mat4 _V;
in mat4 _P;
in vec3 _cameraPosition;

out vec4 color;

void main()
{
    float ao = fragmentAo;
    ao = min(1.0, ao);
    
    mat4 inverse = inverse(_P*(_M*_V));
    vec4 tmp = vec4(gl_FragCoord.xy, 0.0, 1.0);
    vec4 viewport = vec4(0.0, 0.0, 1024.0, 768.0);
    
    tmp.x = (tmp.x - viewport.x) / viewport.z;
    tmp.y = (tmp.y - viewport.y) / viewport.w;
    tmp = tmp * 2 - 1;
    
    vec4 obj = inverse * tmp;
    obj /= obj.w;
    
    vec3 d = (obj.xyz - _cameraPosition) * 1000;
    
    color = clamp(vec4(fragmentColor * fragmentAo, 1), vec4(0.0), vec4(1.0));//vec4(fragmentColor.rgb,1);//vec4(0, 1, 0, 1);
    
    /*for(int i = 0; i < 100; i++)
    {
        vec3 dd = d * i + obj.xyz;
    
        if(dd.x > 0.0 && dd.x < 32.0 && dd.y > 0.0 && dd.y < 32.0 && dd.z > 0.0 && dd.z < 32.0)
        {
            color = vec4(mod(dd.x,2), 0, 0, 1);
            return;
        }
    }*/
    //discard;
}