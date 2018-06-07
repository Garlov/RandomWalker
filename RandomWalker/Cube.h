#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Cube
{
public:
	Cube();
	~Cube();
	void setPosition(glm::vec3 pos);
	glm::vec3 getPosition();
	int draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, GLfloat* g_position_buffer_data, int index);

private:
	static const GLfloat cubeVertex[];
	glm::vec3 position;
	GLfloat r;
	GLfloat g;
	GLfloat b;
};
