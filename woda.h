#pragma once
// Include GLEW
#include <GL/glew.h>
#include <GL/glut.h>  // nag³ówek biblioteki OpenGL
#include <cstdlib>    // nag³ówek biblioteki standardowej C++
#include <cmath>      // nag³ówek biblioteki matematycznej C++
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <GLFW/glfw3.h>
//GLFWwindow* window;
// Include GLM
#include <glm.hpp>
using namespace glm;
#include <gtc/matrix_transform.hpp>


void inicjujWoda();
void rysujWoda();
void niszczWoda();
