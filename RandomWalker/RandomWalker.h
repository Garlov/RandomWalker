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
	void draw();
	void update(double deltaTime);

private:
	double timeSinceLastCube = 0;
	const double timeBetweenCubes = 1000;
	glm::vec3 position = glm::vec3(0, 0, 0);
	std::vector<Cube*> cubes;

	void move();
	Axis getAxis();
	Direction getDirection();
	void spawnCube();
};

