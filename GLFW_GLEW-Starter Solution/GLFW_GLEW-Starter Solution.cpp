// OpenglCourseApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;

void cleanup(GLFWwindow *window) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main()
{
    //initialize glfw
    if (!glfwInit()) {
        std::cout << "failed to initialize glfw" << std::endl;
        glfwTerminate();
        return 1;
    }

    //3.3, not backwards compatible
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "test", nullptr, nullptr);

    if (!window) {
        std::cout << "failed window" << std::endl;
        glfwTerminate();
        return 1;
    }

    //get the window buffer size info
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

    //set GLEW context
    glfwMakeContextCurrent(window);

    //allow experimental extensions
    glewExperimental = GL_TRUE;

    //initialize GLEW
    if (glewInit() != GLEW_OK) {
        std::cout << "failed to initialize glew" << std::endl;
        cleanup(window);
        return 1;
    }

    //setup view port size
    glViewport(0, 0, bufferWidth, bufferHeight);

    float red = 0.0f;
    float blue = 0.0f;
    float green = 0.0f;
    //loop until window closed
    while (!glfwWindowShouldClose(window)) {
        //poll user events
        glfwPollEvents();

        
        //clear the buffer
        if (red < 1.0f && (blue == 0.0f && green==0.0f )) {
            red += 0.001f;
            std::cout << "red: " << red << std::endl;
        }
        else if (red >= 1.0f && (blue <1.0f && green == 0.0f)) {
            blue += 0.001f;
            std::cout << "blue: " << blue << std::endl;
        }
        else if (red >= 1.0f && (blue >= 1.0f && green < 1.0f)) {
            green += 0.001f;
            std::cout << "green: " << green << std::endl;
        }
        else {
            std::cout << "Demo complete, ending now..." << std::endl; 
            cleanup(window);
            return 0;
        }

        glClearColor(red, green, blue, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //swap the buffer
        glfwSwapBuffers(window);

    }

    std::cout << "Hello World!\Sn";
}

