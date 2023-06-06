#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm.hpp>

class Obiekty
{
	GLuint programID;
	GLFWwindow* window;
	GLuint MatrixID;

	void tworzObiekt();
	bool Cpredkosc();
public:
	Obiekty(GLuint programID, GLFWwindow* window, GLuint MatrixID);
	~Obiekty();
	void inicjalizauj();
	void rysujMape();
	
	void sterujObiektem();
	void niszcz();
};

