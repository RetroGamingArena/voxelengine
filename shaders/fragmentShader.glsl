#version 330 core
in vec3 fragmentColor;
//in vec4 fragmentPosition;
in float fragmentAo;

in mat4 _M;
in mat4 _V;
in mat4 _P;
in mat4x3 _cameraUnprojection;
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
    
    vec3 vx1 = (_cameraUnprojection[0]-_cameraUnprojection[1]);
    vx1 *= gl_FragCoord.x;
    vx1 /= 1024.0;
    vx1 = vx1 + _cameraUnprojection[1];
    
    /*glm::vec3 vx2 = (v3-v4);
    vx2 *= x;
    vx2 /= 1024.0;
    vx2 = vx2 + v4;
    
    glm::vec3 vxy = (vx2-vx1);
    vxy *= y;
    vxy /= 768.0;*/
    
    /*vec3 vx2 = (_cameraUnprojection[2]-_cameraUnprojection[3]);
    vx2 *= gl_FragCoord.x;
    vx2 /= 1024.0;
    vx2 = vx1 + _cameraUnprojection[3];
    
    vec3 vxy = (vx2-vx1);
    vxy *= gl_FragCoord.y;
    vxy /= 768.0;
    
    for(int i = 0; i < 200; i++)
    {
        vec3 dd = d * i + obj.xyz;
    
        if( dd.x - 1 > gl_FragCoord.x && dd.x + 1 < gl_FragCoord.x )
        {
            color = vec4(mod(dd.x,2), 0, 0, 1);
            return;
        }
    }*/
    //discard;
}