#include "GraphicsEngine.hpp"

int main(void)
{

    Window window(800, 600);
    if (window.failed()) {
        return -1;
    }


    { // Check video #13 around 20min for info on why there is a block
    // A vertex can contain more than just position (UV coord, normal...)
    float tri_vertex[] = { // pos_x, pos_y, uv_x, uv_y
        -0.5f, -0.5f, 0.0f, 0.0f,        // First vertex 
         0.5f, -0.5f, 1.0f, 0.0f,        // Second vertex                 
         0.5f,  0.5f, 1.0f, 1.0f,        // Third vertex
        -0.5f,  0.5f, 0.0f, 1.0f,        // Fourth vertex
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
    };

    VertexArray vao;
    VertexBuffer vb(tri_vertex, 4 * 4 * sizeof(float)); // 4 vertex, 4 attribute per vertex
    VertexBufferLayout layout;
    layout.Push<float>(2); // pos_x, pos_y
    layout.Push<float>(2); // tex_x, tex_y
    vao.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6);

    glm::mat4 proj = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, -1.0f, 0.0f)); // translate everything to the left

    glm::mat4 mvp = proj * view;

    Shader shader("res/shaders/base.shader");
    shader.Bind();

    Texture texture("res/textures/pomme.png");
    texture.Bind(0);
    shader.SetUniform1i("u_Texture", 0); // Our texture is bound to slot 0
    shader.SetUniformMat4f("u_MVP", mvp);

    Renderer renderer;

    float r = 0.0f;
    float increment = 0.05f;

    /* Loop until the user closes the window */
    while (!window.closed())
    {
        /* Render here */
        renderer.Clear();

        //shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

        renderer.Draw(vao, ib, shader);


        if (r > 1) {
            increment = -0.05f;
        }
        else if (r < 0) {
            increment = 0.05f;
        }


        r += increment;

        window.update();
    }
}
    window.terminate();
    
    return 0;
}