// Include GLFW
#include <GLFW/glfw3.h>
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.


// Include GLM
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
using namespace glm;

#include "controls.hpp"



glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}



// Initial position : on +Z
//Drugo osobowy widok
glm::vec3 position = glm::vec3(0, 6, 8);



// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 45.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;


bool Key_W(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
};
bool Key_S(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
};
bool Key_A(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
};
bool Key_D(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
};
bool Key_Q(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;
};
bool Key_Space(GLFWwindow* window) {
	return glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS;
};
float radianToDegree(float angleRad) {
	return glm::degrees(angleRad);
}



void cameramovment(glm::vec3 objectPosition){
//	printf("Camera movement ...\n");
	
	
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Mysz
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024/2, 768/2);

	horizontalAngle += mouseSpeed * float(1024/2 - xpos );
	verticalAngle   += mouseSpeed * float( 768/2 - ypos );

	
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);
	
	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f), 
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
	
	// Up vector
	glm::vec3 up = glm::cross( right, direction );


	// Move forward
	if (glfwGetKey( window, GLFW_KEY_UP) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_DOWN) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
	// Strafe pierwszoosobowy
	if (glfwGetKey(window, GLFW_KEY_F1) == GLFW_PRESS) {
		//position = glm::vec3(0, 5, -4);
	}
	// Strafe trzecioosobowy
	if (glfwGetKey(window, GLFW_KEY_F3) == GLFW_PRESS) {
		//position = glm::vec3(0, 6, 8);
	}

	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); 

	
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix       = glm::lookAt(
		position,				// Camera is here
		position +direction,	// and looks here : at the same position, plus "direction"
								up							// Head is up (set to 0,-1,0 to look upside-down)
						   );

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}







