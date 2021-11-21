#include "shader.h"

const char *vsSource =
    "#version 330 core\n"
    "layout (location = 0) in vec3 in_pos;"
    "layout (location = 1) in vec3 in_color;"
    "layout (location = 2) in vec2 in_texCoords;"
    "out vec3 vs_color;"
    "out vec2 vs_texCoords;"
    "uniform mat4 un_mvp;"
    "void main()"
    "{"
    "  gl_Position = un_mvp * vec4(in_pos, 1.0);"
    "  vs_color = in_color;"
    "  vs_texCoords = in_texCoords;"
    "}";

const char *fsSource =
    "#version 330 core\n"
    "out vec4 fragColor;"
    "in vec3 vs_color;"
    "in vec2 vs_texCoords;"
    "uniform sampler2D un_tex;"
    "void main()"
    "{"
    "  fragColor = texture(un_tex, vs_texCoords);"
    "}";

unsigned int genShader()
{
  unsigned int vs = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vs, 1, &vsSource, NULL);
  glCompileShader(vs);

  int success;
  char infoLog[512];
  glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vs, 512, NULL, infoLog);
    printf("Error: Vertex shader compilation failed!\n");
  }

  unsigned int fs = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fs, 1, &fsSource, NULL);
  glCompileShader(fs);

  glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fs, 512, NULL, infoLog);
    printf("Error: Fragment shader compilation failed!\n");
  }

  unsigned int program = glCreateProgram();
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glUseProgram(program);

  glDeleteShader(vs);
  glDeleteShader(fs);

  return program;
}

void uniformMatrix4f(unsigned int shader, char *name, mat4 mat)
{
  glUniformMatrix4fv(getUniformLocation(shader, name), 1, GL_FALSE, (float *)mat);
}

int getUniformLocation(unsigned int shader, char *name)
{
  int loc = glGetUniformLocation(shader, name);
  if (loc == -1)
  {
    printf("Warning: Uniform %s not in use!", name);
  }
  return loc;
}