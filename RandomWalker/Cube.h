#ifndef RANDOMWALKER_CUBE_H
#define RANDOMWALKER_CUBE_H

#include <GL/glew.h>

class Cube
{
public:
	Cube();
	~Cube();
	int draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, int index);

private:
	static const GLfloat cubeVertex[];
	static const GLfloat cubeColor[];
};

#endif /* !RANDOMWALKER_CUBE_H */