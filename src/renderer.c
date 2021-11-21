#include "renderer.h"

void clearWindow(float f1, float f2, float f3, float f4)
{
  glClearColor(f1, f2, f3, f4);
  glClear(GL_COLOR_BUFFER_BIT);
}

void draw(struct Camera cam, unsigned int shader, unsigned int vao, unsigned int ebo, unsigned int tex /* optional */, int count, void *indices)
{
  calculateMVP(&cam);
  uniformMatrix4f(shader, "un_mvp", cam.mvp);
  bindVAO(vao);
  bindEBO(ebo);
  if (tex != 0)
  {
    bindTex(tex);
  }
  glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, indices);
}