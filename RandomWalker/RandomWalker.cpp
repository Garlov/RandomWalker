#include "RandomWalker.h"
#include <iostream>

const int RandomWalker::MAX_CUBES = 1000;
const double RandomWalker::TIME_BETWEEN_CUBES = 50;

RandomWalker::RandomWalker() {
	timeSinceLastCube = 0;
	position = glm::vec3(0, 0, 0);
}


RandomWalker::~RandomWalker() {
}

void RandomWalker::update(double deltaTime) {
	timeSinceLastCube += deltaTime;
	if (timeSinceLastCube > TIME_BETWEEN_CUBES && cubes.size() < MAX_CUBES) {
		timeSinceLastCube -= TIME_BETWEEN_CUBES;
		move();
		if (!hasCubeOnPosition(position)) { // only spawn cubes on new positions
			spawnCube();
		}
	}
}

int RandomWalker::getCubeCount()
{
	return cubes.size();
}

int RandomWalker::draw(GLfloat* g_vertex_buffer_data, GLfloat* g_color_buffer_data, GLfloat* g_position_buffer_data, int index) {
	for (unsigned int i = 0; i < cubes.size(); i++) {
		Cube * cube = cubes.at(i);
		index = cube->draw(g_vertex_buffer_data, g_color_buffer_data, g_position_buffer_data, index);
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
}

Axis RandomWalker::getAxis() {
	return static_cast<Axis>(rand() % 3);
}

Direction RandomWalker::getDirection() {
	return static_cast<Direction>(rand() % 2);
}

void RandomWalker::spawnCube() {
	Cube * newCube = new Cube();
	newCube->setPosition(position);
	cubes.push_back(newCube);
}

bool RandomWalker::hasCubeOnPosition(glm::vec3 pos)
{
	for (unsigned int i = 0; i < cubes.size(); i++) {
		Cube * cube = cubes.at(i);
		if (cube->getPosition() == pos) {
			return true;
		}
	}
	return false;
}
