#pragma once
#include <vector>
#include "Cube.h"
#include <glm/glm.hpp>

enum class Axis {
	x,
	y,
	z
};

enum class Direction {
	up,
	down
};

class RandomWalker
{
public:
	RandomWalker();
	~RandomWalker();

	static const int MAX_CUBES;

	int draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, int index);
	void update(double deltaTime);

private:
	static const double TIME_BETWEEN_CUBES;

	double timeSinceLastCube = 0;
	glm::vec3 position = glm::vec3(0, 0, 0);
	std::vector<Cube*> cubes;

	void move();
	Axis getAxis();
	Direction getDirection();
	void spawnCube();
};

