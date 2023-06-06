#include "Obiekty.h"
#include "ziemia.h"
#include "wally.h"
#include "woda.h"
#include "Stodola.h"
#include "controls.hpp"

glm::vec3 objectPosition(0.0f, 10.0f, 0.0f);
glm::vec3 CamraPosition(0.0f, objectPosition.y + 2.5f, 0.0f);
float predkosc = 0.0f;
float rotationAngle = 0.0f;
Ziemia ziemia;
Wally wally;

Obiekty::~Obiekty()
{

}

Obiekty::Obiekty(GLuint programID, GLFWwindow* window, GLuint MatrixID)
{
	this->programID = programID;
	this->window = window;
	this->MatrixID = MatrixID;
}

void Obiekty::inicjalizauj()
{
	ziemia.init();
	inicjujWoda();
	wally.init();
	inicjujStodola();
}
void Obiekty::rysujMape()
{
	ziemia.rysuj(programID, MatrixID);
	rysujWoda();
	//rysujStodola();
}

void Obiekty::tworzObiekt()
{
	glm::mat4 ModelMatrix = glm::mat4(1.0f);
	ModelMatrix = glm::translate(ModelMatrix, objectPosition);
	ModelMatrix = glm::rotate(ModelMatrix, rotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 MVP = getProjectionMatrix() * getViewMatrix() * ModelMatrix;
	wally.rysuj(programID,window, MVP, MatrixID);
}
bool Obiekty::Cpredkosc()
{
	if (predkosc >= 0.0f)
		return true;
	else if (predkosc <= 0.0f)
		return true;
	else
		return false;
}
void Obiekty::sterujObiektem()
{
	//this->programID = programID;
	//this->window = window;
	//static double lastTime = glfwGetTime();
	//double currentTime = glfwGetTime();
	//float deltaTime = float(currentTime - lastTime);
	//if (objectPosition.z >= 32.0f and Cpredkosc()) {
	//	predkosc = predkosc * (-1);
	//	for (int i = 0; predkosc == 0.0f; i++) {
	//		predkosc += 0.05f;
	//		objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//		objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		tworzObiekt(MatrixID);
	//	}
	//}
	//if (objectPosition.z <= -35.0f and Cpredkosc()) {
	//	predkosc = predkosc * (-1);
	//	for (int i = 0; predkosc == 0.0f; i++) {
	//		predkosc -= 0.05f;
	//		objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//		objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		tworzObiekt(MatrixID);
	//	}
	//}
	//else {
	//	printf("predk %f\n", predkosc);
	//	printf("\tpozycja x-%f, z-%f\n", objectPosition.x, objectPosition.z);
	//	printf("\tpozycja kamera x-%f, z-%f\n", CamraPosition.x, CamraPosition.z);
	//	printf("\t kat %f\n", radianToDegree(rotationAngle));
	//	if (Key_W(window)) {
	//		if (Key_A(window)) {
	//			rotationAngle += 0.01f;
	//			//printf("ruch WA");
	//		}
	//		if (Key_D(window)) {
	//			rotationAngle -= 0.01f;
	//			//printf("ruch WD");
	//		}
	//		else {
	//			if (predkosc == 0) {
	//				predkosc = 0.4f;
	//			}
	//			if (predkosc <= 2.6f) {
	//				predkosc += 0.3f;
	//			}
	//			//printf("ruch W");
	//		}
	//		objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//		objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//	}
	//	else if (Key_S(window)) {
	//		if (Key_A(window)) {
	//			rotationAngle -= 0.01f;
	//			//printf("ruch SA");
	//		}
	//		if (Key_D(window)) {
	//			rotationAngle += 0.01f;
	//			//printf("ruch SD");
	//		}
	//		else
	//		{
	//			//printf("ruch S");
	//			if (predkosc == 0) {
	//				predkosc = -0.3f;
	//			}
	//			if (predkosc >= -1.6f) {
	//				predkosc -= 0.2f;
	//			}
	//		}
	//		objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//		objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//	}
	//	else if (Key_A(window)) {
	//		if (predkosc == 0.0f) {
	//			rotationAngle += 0.1f;
	//		}
	//		else {
	//			if (-0.2f <= predkosc and predkosc <= 0.3f) {
	//				predkosc = 0.0f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//			if (predkosc > 0.3f) {
	//				predkosc -= 0.05f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//			if (predkosc < -0.2f) {
	//				predkosc += 0.05f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//		}
	//	}
	//	else if (Key_D(window)) 
	//		if (predkosc == 0.0f) {
	//			rotationAngle -= 0.1f;
	//			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		}
	//		else {
	//			if (-0.02f <= predkosc and predkosc <= 0.03f) {
	//				predkosc = 0.0f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//			if (predkosc > 0.3f) {
	//				predkosc -= 0.05f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//			if (predkosc < -0.2f) {
	//				predkosc += 0.05f;
	//				objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//				objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//			}
	//		}
	//	}
	//	else if (Key_Q(window)) {
	//		objectPosition.x = 0.00f;
	//		objectPosition.z = 0.00f;
	//	}
	//	else {
	//		if (-0.2f <= predkosc and predkosc <= 0.3f) {
	//			predkosc = 0.0f;
	//			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		}
	//		if (predkosc > 0.3f) {
	//			predkosc -= 0.05f;
	//			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		}
	//		if (predkosc < -0.2f) {
	//			predkosc += 0.05f;
	//			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
	//			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
	//		}
	//	}
	//	CamraPosition.x = objectPosition.x - sin(rotationAngle) * 1.5f;
	//	CamraPosition.z = objectPosition.z - cos(rotationAngle) * 1.5f;
	//}
	//tworzObiekt(MatrixID);
	//cameramovment(CamraPosition);
	//lastTime = currentTime;


	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	if (objectPosition.z >= 32.0f && Cpredkosc()) {
		predkosc = predkosc * (-1);
		for (int i = 0; predkosc == 0.0f; i++) {
			predkosc += 0.05f;
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;

			tworzObiekt();
		}
	}
	if (objectPosition.z <= -35.0f && Cpredkosc()) {
		predkosc = predkosc * (-1);
		for (int i = 0; predkosc == 0.0f; i++) {
			predkosc -= 0.05f;
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;

			tworzObiekt();
		}
	}
	else {
		/*printf("predk %f\n", predkosc);
		printf("\tpozycja x-%f, z-%f\n", objectPosition.x, objectPosition.z);
		printf("\tpozycja kamera x-%f, z-%f\n", CamraPosition.x, CamraPosition.z);
		printf("\t kat %f\n", radianToDegree(rotationAngle));*/

		if (Key_W(window)) {
			if (Key_A(window)) {
				rotationAngle += 0.01f;
			}
			if (Key_D(window)) {
				rotationAngle -= 0.01f;
			}
			else {
				if (predkosc == 0) {
					predkosc = 0.4f;
				}
				if (predkosc <= 2.6f) {
					predkosc += 0.3f;
				}
			}
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
		}
		else if (Key_S(window)) {
			if (Key_A(window)) {
				rotationAngle -= 0.01f;
			}
			if (Key_D(window)) {
				rotationAngle += 0.01f;
			}
			else {
				if (predkosc == 0) {
					predkosc = -0.3f;
				}
				if (predkosc >= -1.6f) {
					predkosc -= 0.2f;
				}
			}
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
		}
		else if (Key_A(window)) {
			if (predkosc == 0.0f) {
				rotationAngle += 0.1f;
			}
			else {
				if (-0.2f <= predkosc && predkosc <= 0.3f) {
					predkosc = 0.0f;
				}
				if (predkosc > 0.3f) {
					predkosc -= 0.05f;
				}
				if (predkosc < -0.2f) {
					predkosc += 0.05f;
				}
			}
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
		}
		else if (Key_D(window)) {
			if (predkosc == 0.0f) {
				rotationAngle -= 0.1f;
			}
			else {
				if (-0.02f <= predkosc && predkosc <= 0.03f) {
					predkosc = 0.0f;
				}
				if (predkosc > 0.3f) {
					predkosc -= 0.05f;
				}
				if (predkosc < -0.2f) {
					predkosc += 0.05f;
				}
			}
			objectPosition.x += sin(rotationAngle) * predkosc * deltaTime;
			objectPosition.z += cos(rotationAngle) * predkosc * deltaTime;
		}
		else if (Key_Q(window)) {
			objectPosition.x = 0.00f;
			objectPosition.z = 0.00f;
		}
		else {
			if (-0.2f <= predkosc && predkosc <= 0.3f) {
				predkosc = 0.0f;
			}
			if (predkosc > 0.3f) {
				predkosc -= 0.05f;
			}
			if (predkosc < -0.2f) {
				predkosc += 0.05f;
			}
		}
		CamraPosition.x = objectPosition.x - sin(rotationAngle) * 1.5f;
		CamraPosition.z = objectPosition.z - cos(rotationAngle) * 1.5f;
	}

	tworzObiekt();
	cameramovment(CamraPosition);
	lastTime = currentTime;

}

void Obiekty::niszcz()
{
	wally.niszcz();
	ziemia.niszcz();
	niszczWoda();
	niszczStodola();
}
