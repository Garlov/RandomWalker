// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>

#include "RandomWalker.h"

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		std::cout << stderr << "Failed to initialize GLFW" << std::endl;
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Random Walker", NULL, NULL);
	if (window == NULL) {
		std::cout <<  stderr << "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials." << std::endl;
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		std::cout << stderr << "Failed to initialize GLEW" << std::endl;
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("shaders/TransformVertexShader.vertexshader", "shaders/ColorFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, -3), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around

	RandomWalker randomWalker = RandomWalker();

	const double FRAMES_PER_SECOND = 60; // this should be able to run the update loop at 60 fps easily
	const double MS_PER_FRAME = 1000 / FRAMES_PER_SECOND;
	const double MAX_FRAMESKIP = 5;

	double next_game_tick = glfwGetTime() * 1000;
	int loops;

	int currentDrawsPerSecond = 0;
	int currentUpdatesPerSecond = 0;
	double lastPrintTime = glfwGetTime();
	//float interpolation;

	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
		double newTime= glfwGetTime() * 1000;
		loops = 0;
		while (newTime > next_game_tick && loops < MAX_FRAMESKIP) {

			randomWalker.update(MS_PER_FRAME);
			currentUpdatesPerSecond += 1;

			next_game_tick += MS_PER_FRAME;
			loops++;
		}
		// No moving objects in this, so no need to use the interpolation
		//interpolation = float(newTime + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(programID);

		randomWalker.draw();
		currentDrawsPerSecond += 1;

		glfwSwapBuffers(window);
		glfwPollEvents();

		// print fps info
		if (glfwGetTime() - lastPrintTime > 1) {
			lastPrintTime += 1;
			std::cout << currentDrawsPerSecond << " / " << currentUpdatesPerSecond << std::endl;
			currentDrawsPerSecond = 0;
			currentUpdatesPerSecond = 0;
		}
	}

	// Cleanup VBO and shader
	//glDeleteBuffers(1, &vertexbuffer);
	//glDeleteBuffers(1, &colorbuffer);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);


	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}

