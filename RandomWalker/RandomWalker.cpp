#include "RandomWalker.h"
#include <iostream>

RandomWalker::RandomWalker()
{
}


RandomWalker::~RandomWalker()
{
}

void RandomWalker::update(double deltaTime) {
	timeSinceLastCube += deltaTime;
	if (timeSinceLastCube > timeBetweenCubes) {
		timeSinceLastCube -= timeBetweenCubes;
		spawnCube();
	}
}

void RandomWalker::draw()
{
	for (int i = 0; i < cubes.size(); i++) {
		Cube * cube = cubes.at(i);
		cube->draw();
	}
}

void RandomWalker::spawnCube() {
	std::cout << "spawn cube" << std::endl;
	Cube * newCube = new Cube();
	cubes.push_back(newCube);
}