#include "woda.h"

#include "objloader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#pragma once

GLuint MatrixIDWoda;
std::vector<glm::vec2> uvsWoda;
std::vector<glm::vec3> verticesWoda;
std::vector<glm::vec3> normalsWoda;
glm::mat4 ModelMatrixWoda;


GLuint programIDWoda;
GLuint vertexbufferWoda;
GLuint uvbufferWoda;

GLuint TexturaWoda;




void inicjujWoda()
{




	bool mapa = loadOBJ("obiekty/Rzeka.obj", verticesWoda, uvsWoda, normalsWoda);

	glGenBuffers(1, &vertexbufferWoda);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferWoda);
	glBufferData(GL_ARRAY_BUFFER, verticesWoda.size() * sizeof(glm::vec3), &verticesWoda[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbufferWoda);
	glBindBuffer(GL_ARRAY_BUFFER, uvbufferWoda);
	glBufferData(GL_ARRAY_BUFFER, uvsWoda.size() * sizeof(glm::vec2), &uvsWoda[0], GL_STATIC_DRAW);

}

void rysujWoda()
{
	//printf("Render Wody file ...\n");
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();

	TexturaWoda = loadBMP_custom("textury/water2.bmp");
	GLuint TexturaID = glGetUniformLocation(programIDWoda, "myTextureSampler");

	glm::mat4 ModelMatrixWoda = glm::mat4(1.0);
	//ModelMatrixWoda = glm::scale(ModelMatrixWoda, glm::vec3(260.0f)); // Skalowanie o 260%
	//glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));//po³o¿enia
	//ModelMatrixWoda = TranslationMatrix * ModelMatrixWoda;

	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrixWoda;

	glUniform1i(TexturaID, 0);

	glUniformMatrix4fv(MatrixIDWoda, 1, GL_FALSE, &MVP[0][0]); // Dla obiektu 1



	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbufferWoda);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	//2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbufferWoda);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
	glColor3f(1.0f, 0.2f, 0.4f);
	glDrawArrays(GL_TRIANGLES, 0, verticesWoda.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void niszczWoda()
{
	glDeleteBuffers(1, &vertexbufferWoda);
	glDeleteBuffers(1, &uvbufferWoda);
	glDeleteProgram(programIDWoda);
	glDeleteTextures(1, &TexturaWoda);

}
