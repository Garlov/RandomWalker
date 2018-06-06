#pragma once
#include <vector>
#include "Cube.h"
#include <glm/glm.hpp>

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
	glm::vec2 position = glm::vec2(0, 0);
	std::vector<Cube*> cubes;

	void spawnCube();
};

