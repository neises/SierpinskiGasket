#include <stdio.h>

#include <glew.h>
#include <glfw3.h>
#include "Utility.h"

// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;


const int NumPoints = 20000
;
int main()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return 1;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile = No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// Please not now!
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create the window
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Sierpinski Gasket", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	// Get Buffer Size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);


	Vec::Vec2 points[NumPoints];

	// Specifiy the vertices for a triangle
	Vec::Vec2 vertices[3] = {
		//Vec::Vec2(-1.0, 1.0), Vec::Vec2(0.0, -1.0), Vec::Vec2(1.0, 1.0)
		Vec::Vec2(-1.0, -1.0), Vec::Vec2(0.0, 1.0), Vec::Vec2(1.0, -1.0)
	};

	// Select an arbitrary initial point inside of the triangle
	points[0] = Vec::Vec2(0.25, 0.50);

	// compute and store N-1 new points
	for (int i = 1; i < NumPoints; ++i) 
	{
		// pick a vertex at random
		int j = std::rand() % 3;   

		// Compute the point halfway between the selected vertex
		//   and the previous point
		points[i] = (points[i - 1] + vertices[j]) / 2.0;
	}

	// Create a vertex array object
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// Create and initialize a buffer object
	GLuint buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	// Load shaders and use the resulting shader program
	GLuint program = Utility::InitShader("VertexShader.glsl", "FragmentShader.glsl");
	glUseProgram(program);

	// Initialize the vertex position attribute from the vertex shader
	GLuint loc = glGetAttribLocation(program, "vPosition");
	glEnableVertexAttribArray(loc);
	glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(0));

	// Loop until window closed
	while (!glfwWindowShouldClose(mainWindow))
	{
		// Get + Handle user input events
		glfwPollEvents();

		// Clear window
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_POINTS, 0, NumPoints);

		glfwSwapBuffers(mainWindow);
	}

	glfwTerminate();
	return 0;
}