#shader vertex
#version 330 core 
        
layout(location = 0) in vec4 position; // auto convert to vec4 x,y,z,t | t = 1.0f
layout(location = 1) in vec3 normal;

out vec3 v_Color; // go out of vertex shader | v_ for variing
out vec3 v_Normal;
out vec3 v_FragPos;
uniform mat4 u_VP;
uniform mat4 u_Model;

void main(){
    vec4 world_position = u_Model * position;
    gl_Position = u_VP * world_position;
    v_Color = position.xyz;
    v_FragPos = world_position.xyz;
    v_Normal = normal;
    v_Color = (v_Color + vec3(1.0f, 1.0f, 1.0f)) / 2.0f;
};


#shader fragment
#version 330 core 

layout(location = 0) out vec4 color;

in vec3 v_Color; // go in from vertex shader
in vec3 v_Normal;
in vec3 v_FragPos;

uniform vec3 u_viewPos;
uniform vec3 u_lightPos;

void main(){
    // TODO : move to uniform
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

    // Ambiant
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // Diffuse
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(u_lightPos - v_FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // Specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(u_viewPos - v_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    color = vec4((ambient + diffuse + specular) * v_Color, 1.0f);
};

