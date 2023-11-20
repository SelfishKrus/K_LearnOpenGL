#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // glewInit has to be done in the context 
    if (glewInit() != GLEW_OK)
		std::cout << "Error!" << std::endl; 

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] = {
		-0.5f, -0.5f, // 0
		 0.0f,  0.5f, // 1
		 0.5f, -0.5f  // 2
	};

    unsigned int buffer;
    glGenBuffers(1, &buffer); // Generate 1 buffer, store it in buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer); // Select buffer
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW); // Fill buffer with data

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        // Test
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}