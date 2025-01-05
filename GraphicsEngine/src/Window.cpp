#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "Renderer.hpp"
#include "UtilsGL.hpp"
#include "Window.hpp"

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height); // TODO : Create a Viewport class
}

Window::Window(int width, int height) {
    status = 0;

    /* Initialize the library */
    if (!glfwInit())
        status = -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        status = -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error in GLEW initialization" << std::endl;
    }
    std::cout << glGetString(GL_VERSION) << std::endl;

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);
    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

bool Window::failed()
{
    return status == -1;
}

bool Window::closed()
{
    return glfwWindowShouldClose(window);
}

void Window::terminate()
{
    glfwTerminate();
}

void Window::update()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

    Renderer::Clear();
}
