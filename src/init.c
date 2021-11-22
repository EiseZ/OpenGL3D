#include "init.h"

GLFWwindow *init(int enableWireframe)
{
  // Init GLFW
  if (!glfwInit())
  {
    printf("Error: Failed to init GLFW!\n");
    return NULL;
  }

  // Error callback function
  glfwSetErrorCallback(errorCallback);

  // Set version
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Create & set window
  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Minecraft", NULL, NULL);
  if (!window)
  {
    printf("Error: Failed to create window!\n");
    glfwTerminate();
    return NULL;
  }
  glfwMakeContextCurrent(window);

  // Enable vsync
  glfwSwapInterval(1);

  // Keypress callback function
  glfwSetKeyCallback(window, keypressCallback);

  // Get mouse input & hide mouse
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // Set mouse movement callback
  glfwSetCursorPosCallback(window, mouseCallback);

  // Init glad
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    printf("Error: Failed to init glad!\n");
    glfwTerminate();
    return NULL;
  }

  // Set viewport dimensions
  glViewport(0, 0, WIDTH, HEIGHT);

  // Texture settings
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glEnable(GL_CULL_FACE);

  if (enableWireframe)
  {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  return window;
}