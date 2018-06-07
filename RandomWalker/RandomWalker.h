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

	int draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, GLfloat* g_position_buffer_data, int index);
	void update(double deltaTime);
	int getCubeCount();

private:
	static const double TIME_BETWEEN_CUBES;

	double timeSinceLastCube;
	glm::vec3 position;
	std::vector<Cube*> cubes;

	void move();
	Axis getAxis();
	Direction getDirection();
	void spawnCube();
	bool hasCubeOnPosition(glm::vec3 pos);
};

