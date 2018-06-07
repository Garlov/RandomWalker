#include "RandomWalker.h"
#include <iostream>

RandomWalker::RandomWalker() {
}


RandomWalker::~RandomWalker() {
}

void RandomWalker::update(double deltaTime) {
	timeSinceLastCube += deltaTime;
	if (timeSinceLastCube > TIME_BETWEEN_CUBES && cubes.size() < MAX_CUBES) {
		timeSinceLastCube -= TIME_BETWEEN_CUBES;
		move();
		spawnCube();
	}
}

int RandomWalker::draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, int index) {
	for (unsigned int i = 0; i < cubes.size(); i++) {
		Cube * cube = cubes.at(i);
		index = cube->draw(g_vertex_buffer_data, g_color_buffer_data, index);
	}

	return index;
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
	// TODO check if there is already a cube in this position and skip making a new one if that is true
	std::cout << "spawn cube" << std::endl;
	Cube * newCube = new Cube();
	cubes.push_back(newCube);
}

const int RandomWalker::MAX_CUBES = 1;
const double RandomWalker::TIME_BETWEEN_CUBES = 1000;