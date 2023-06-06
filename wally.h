#pragma once

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
//GLFWwindow* window;
// Include GLM
#include <glm.hpp>
using namespace glm;
#include <gtc/matrix_transform.hpp>

class Wally {
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;


	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint Textura;
public:
	void init();
	void rysuj(GLuint programID, GLFWwindow* window, glm::mat4 MVP, GLuint MatrixID);
	void niszcz();
};
