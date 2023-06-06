#include "ziemia.h"
#include "objloader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#pragma once








void Ziemia::init()
{
	bool mapa = loadOBJ("obiekty/Ziemia.obj", vertices, uvs, normals);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	
	
}

void Ziemia::rysuj(GLuint programID, GLuint MatrixID)
{
	Textura = loadBMP_custom("textury/ziemiav3.bmp");
	TexturaID = glGetUniformLocation(programID, "myTextureSampler");

	MVP= getProjectionMatrix() * getViewMatrix() * ModelMatrix;

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

void Ziemia::niszcz()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteTextures(1, &Textura);

}
