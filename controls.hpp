#ifndef CONTROLS_HPP
#define CONTROLS_HPP


void cameramovment(glm::vec3 objectPosition);
bool Key_W(GLFWwindow* window);
bool Key_S(GLFWwindow* window);
bool Key_A(GLFWwindow* window);
bool Key_D(GLFWwindow* window);
bool Key_Q(GLFWwindow* window);
float radianToDegree(float angleRad);



//void robotmovement(GLFWwindow* window, int key, int scancode, int action, int mods);
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();



#endif