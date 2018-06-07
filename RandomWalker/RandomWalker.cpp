#include "RandomWalker.h"
#include <iostream>

RandomWalker::RandomWalker() {
}


RandomWalker::~RandomWalker() {
}

void RandomWalker::update(double deltaTime) {
	timeSinceLastCube += deltaTime;
	if (timeSinceLastCube > timeBetweenCubes) {
		timeSinceLastCube -= timeBetweenCubes;
		move();
		spawnCube();
	}
}

void RandomWalker::draw() {
	for (int i = 0; i < cubes.size(); i++) {
		Cube * cube = cubes.at(i);
		cube->draw();
	}
}

void RandomWalker::move() {
	Axis axis = getAxis();
	Direction direction = getDirection();
	int valueChange = 0;
	if (direction == Direction::up) {
		valueChange = 1;
	}
	else if (direction == Direction::down) {
		valueChange = -1;
	}

	switch (axis)
	{
	case Axis::x:
		position.x += valueChange;
		break;
	case Axis::y:
		position.y += valueChange;
		break;
	case Axis::z:
		position.z += valueChange;
		break;
	default:
		break;
	}

	std::cout << position.x << "," << position.y << "," << position.z << std::endl;
}

Axis RandomWalker::getAxis() {
	return static_cast<Axis>(rand() % 3);
}

Direction RandomWalker::getDirection() {
	return static_cast<Direction>(rand() % 2);
}

void RandomWalker::spawnCube() {
	std::cout << "spawn cube" << std::endl;
	Cube * newCube = new Cube();
	cubes.push_back(newCube);
}