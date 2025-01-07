#shader vertex
#version 330 core 
        
layout(location = 0) in vec4 position; // auto convert to vec4 x,y,z,t | t = 1.0f

out vec3 v_Color;

uniform mat4 u_VP;
uniform mat4 u_Model;

void main(){
    gl_Position = u_VP * u_Model * position;
    v_Color = position.xyz;
};


#shader fragment
#version 330 core 

layout(location = 0) out vec4 color;
in vec3 v_Color;

void main(){
    color = v_Color;
};

