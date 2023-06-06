// Include GLEW
#include <GL/glew.h>
#include <GL/glut.h>  // nag³ówek biblioteki OpenGL
#include <cstdlib>    // nag³ówek biblioteki standardowej C++
#include <cmath>      // nag³ówek biblioteki matematycznej C++
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;
// Include GLM
#include <glm.hpp>
using namespace glm;

#include "objloader.hpp"
#include "controls.hpp"
#include "texture.hpp"
#include "shader.hpp"
#include "Obiekty.h"



#include <gtc/matrix_transform.hpp>

  //pocz¹tkowe po³o¿enie obiektu


void ekran() {

	// Initialise GLFW
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 800, "Obrazek", NULL, NULL);

	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile

	glewInit();


	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 800 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);
}

int main(void)
{
	
	
	
	ekran();
	

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");



	// Get a handle for our "MVP" uniform
	
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	

	Obiekty obiekty(programID, window, MatrixID)  ;
	obiekty.inicjalizauj();
	
	

	do {

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		glUseProgram(programID);

		//ruch kamery
		
		
		
		obiekty.rysujMape( );
		
		obiekty.sterujObiektem();
		//playermoevement();
		

		
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Zamykanie
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glDeleteProgram(programID);
	obiekty.niszcz();
	
	
	glDeleteVertexArrays(1, &VertexArrayID);

	glfwTerminate();
	

	return 0;
}