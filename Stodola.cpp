#include "Stodola.h"


#include "objloader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#pragma once

GLuint MatrixID;
std::vector<glm::vec2> uvs;
std::vector<glm::vec3> vertices;
std::vector<glm::vec3> normals;
glm::mat4 ModelMatrix;


GLuint programID;
GLuint vertexbuffer;
GLuint uvbuffer;

GLuint Textura;




void inicjujStodola()
{




	bool mapa = loadOBJ("obiekty/Stodola.obj", vertices, uvs, normals);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

}

void rysujStodola()
{
	//printf("Render Wody file ...\n");
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();

	Textura = loadBMP_custom("textury/003_diffuse.bmp");
	GLuint TexturaID = glGetUniformLocation(programID, "myTextureSampler");

	glm::mat4 ModelMatrixWoda = glm::mat4(1.0);
	//ModelMatrixWoda = glm::scale(ModelMatrixWoda, glm::vec3(260.0f)); // Skalowanie o 260%
	//glm::mat4 TranslationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));//po³o¿enia
	//ModelMatrixWoda = TranslationMatrix * ModelMatrixWoda;

	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrixWoda;

	glUniform1i(TexturaID, 0);

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]); // Dla obiektu 1



	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
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
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
	glColor3f(1.0f, 0.2f, 0.4f);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void niszczStodola()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Textura);

}
