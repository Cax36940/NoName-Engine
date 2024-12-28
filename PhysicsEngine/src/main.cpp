// TODO change ofApp
//#include "ofMain.h"
//#include "ofApp.h"

#include <iostream>

#include "Matrix4.hpp"

#include "IndexBuffer.hpp"
#include "Renderer.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "VertexBufferLayout.hpp"
#include "Window.hpp"

#include "Mouse.hpp"

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

//========================================================================
int main( ){

	/*
	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();*/

    Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (window.failed()) {
        return -1;
    }

    Mouse mouse(window);

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

        Matrix4 proj(1.0f / 4.0f, 1.0f / 3.0f, -1.0f, 1.0f);
        Matrix4 view;
        view.t = Vector4(-1.0f, -1.0f, 0.0f, 1.0f); // translate to the left in x and y


        Shader shader("res/shaders/base.shader"); // Found in PhysicsEngine\bin
        shader.Bind();

        Texture texture("res/textures/pomme.png");
        texture.Bind(0);
        shader.SetUniform1i("u_Texture", 0); // Our texture is bound to slot 0


        Renderer renderer;

        float r = 0.0f;
        float increment = 0.05f;

        /* Loop until the user closes the window */
        while (!window.closed())
        {
            /* Render here */
            renderer.Clear();

            Matrix4 mvp = proj * view;
            shader.SetUniformMat4f("u_MVP", mvp);
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
