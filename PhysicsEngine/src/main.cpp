#include <iostream>

#include "Matrix4.hpp"

#include "Window.hpp"

#include "Camera.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"

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

        Cube cube(2.0f, 0.0f, 0.0f);

        /* Loop until the user closes the window */
        while (!window.closed())
        {
            /* Render here */

            camera.update_position();

            Matrix4 view_matrix = camera.get_view();
            Matrix4 vp = proj * view_matrix;

            cube.mesh.get_shader().Bind();
            cube.mesh.get_shader().SetUniformMat4f("u_VP", vp);
            cube.mesh.get_shader().SetUniform3f("u_viewPos", 0.0f, 0.0f, 0.0f);
            cube.mesh.draw();

            window.update();
        }
    }
    window.terminate();

    return 0;

}
