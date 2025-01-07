#shader vertex
#version 330 core 
        
layout(location = 0) in vec4 position; // auto convert to vec4 x,y,z,t | t = 1.0f
layout(location = 1) in vec2 texCoords;

out vec2 v_TexCoords; // go out of vertex shader | v_ for variing
uniform mat4 u_VP;

void main(){
    gl_Position = u_VP * position;
    v_TexCoords = texCoords;
};


#shader fragment
#version 330 core 

uniform sampler2D u_Texture;

in vec2 v_TexCoords; // go in from vertex shader

layout(location = 0) out vec4 color;

void main(){
    vec4 texColor = texture(u_Texture, v_TexCoords);
    color = texColor;
};

