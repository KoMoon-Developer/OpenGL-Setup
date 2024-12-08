#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>

using std::cout;

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void render() {
  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_POLYGON);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.2f, 0.0f, 0.0f);
  glVertex3f(0.2f, 0.2f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glEnd();

  glFlush();
}

int main() {
  cout << "Hello OpenGL" << '\n';
  if (!glfwInit()) {
    cout << "Failed to initialize GLFW.\n";
    return -1;
  }

  // glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

  GLFWwindow *window;
  window = glfwCreateWindow(800, 600, "C++ OpenGL on Windows", NULL, NULL);
  if (window == NULL) {
    cout << "Failed to open GLFW window.\n";
    return 1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    cout << "Failed to initialize GLAD.\n";
    return 1;
  }

  glViewport(0, 0, 800, 600);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  while (!glfwWindowShouldClose(window)) {

    // Clear Screen
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    render();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
