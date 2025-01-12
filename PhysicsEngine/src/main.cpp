#include <chrono>
#include <iostream>

#include "Matrix4.hpp"

#include "Window.hpp"

#include "Camera.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

#include "Component/Shader/ShaderManager.hpp"
#include "Entity/Cube.hpp"

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600


int main(){

    // Create window
    Window window(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (window.failed()) {
        return -1;
    }

    // There is a block because all gl buffer should be destroyed before terminate
    // TODO : Make a thing to delete every mesh before calling window terminate
    { 

        Matrix4 proj = Matrix4::projection(45.0f, 4.0f/3.0f, 0.1f, 10000.0f);

        Camera camera;
        camera.translate(0.0f, 0.0f, 5.0f);

        Mouse mouse(window, camera);
        Keyboard keyboard(window, camera);

        Cube cube(0.0f, 0.0f, 0.0f, "../res/shaders/base_cube.shader");
        Cube light(2.0f, 1.5f, 0.0f, "../res/shaders/base_light.shader");
        light.transform *= 0.2f;


        float total_time = 0.0f;
        auto time_last_frame = std::chrono::high_resolution_clock::now();
        /* Loop until the user closes the window */
        while (!window.closed())
        {
            ///// Compute frame timing //////
            auto current_time = std::chrono::high_resolution_clock::now();
            float delta = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - time_last_frame).count() / 1000.0f;
            time_last_frame = current_time;
            if (delta > 1.0f) {
                delta = 1.0f / 60.0f; // Avoid simulation explosion when dragging the window
            };

            total_time += delta;

            
            ///// Update /////
            camera.update_position();

            light.transform.translation.x = 2.0f * cosf(total_time);
            light.transform.translation.z = 2.0f * sinf(total_time);


            ///// Render /////
            Matrix4 view_matrix = camera.get_view();
            Matrix4 vp = proj * view_matrix;

            cube.mesh.get_shader().Bind();
            cube.mesh.get_shader().SetUniformMat4f("u_VP", vp);
            Vector3 view_pos = camera.get_world_position();
            cube.mesh.get_shader().SetUniform3f("u_viewPos", view_pos.x, view_pos.y, view_pos.z);
            Vector3 light_pos = light.transform.translation;
            cube.mesh.get_shader().SetUniform3f("u_lightPos", light_pos.x, light_pos.y, light_pos.z);
            cube.mesh.draw();

            light.mesh.get_shader().Bind();
            light.mesh.get_shader().SetUniformMat4f("u_VP", vp);
            light.mesh.draw();

            window.update();
        }

        ShaderManager::clear();
    }
    window.terminate();

    return 0;

}
