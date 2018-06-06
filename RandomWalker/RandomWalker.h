#pragma once
#include <vector>
#include "Cube.h"
#include <glm/glm.hpp>

class RandomWalker
{
public:
	RandomWalker();
	~RandomWalker();

private:
	std::vector<unsigned short> cubeIndices;
	std::vector<glm::vec3> indexed_cubeVertices;
	std::vector<glm::vec2> indexed_cubeUvs;
	std::vector<glm::vec3> indexed_cubeNormals;
	std::vector<Cube*> boxes;
};

