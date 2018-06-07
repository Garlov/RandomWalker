#include "Cube.h"
#include <iostream>

const GLfloat Cube::cubeVertex[] = {
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f, 0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f,-0.5f,
	0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f, 0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f,-0.5f,
	0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f, 0.5f,
	-0.5f,-0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	-0.5f,-0.5f, 0.5f,
	0.5f,-0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f, 0.5f,-0.5f,
	0.5f,-0.5f,-0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f,-0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	0.5f, 0.5f,-0.5f,
	-0.5f, 0.5f,-0.5f,
	0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f,-0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f, 0.5f, 0.5f,
	-0.5f, 0.5f, 0.5f,
	0.5f,-0.5f, 0.5f
};

Cube::Cube()
{
	// generate random color
	r = (GLfloat)rand() / RAND_MAX;
	g = (GLfloat)rand() / RAND_MAX;
	b = (GLfloat)rand() / RAND_MAX;
}

Cube::~Cube()
{
}

int Cube::draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, GLfloat* g_position_buffer_data, int index) {
	int vertexLength = (sizeof(cubeVertex) / sizeof(*cubeVertex));
	for (int i = 0; i < vertexLength; i++) {
		g_vertex_buffer_data[index + i] = cubeVertex[i];
	}

	g_color_buffer_data[index / (vertexLength / 3)] = r;
	g_color_buffer_data[index / (vertexLength / 3) + 1] = g;
	g_color_buffer_data[index / (vertexLength / 3) + 2] = b;

	g_position_buffer_data[index / (vertexLength / 3)] = position.x;
	g_position_buffer_data[index / (vertexLength / 3) + 1] = position.y;
	g_position_buffer_data[index / (vertexLength / 3) + 2] = position.z;

	return index + vertexLength;
}

void Cube::setPosition(glm::vec3 pos)
{
	position = pos;
}

glm::vec3 Cube::getPosition()
{
	return position;
}
