#pragma once
#include <vector>
#include "Cube.h"

class RandomWalker
{
public:
	RandomWalker();
	~RandomWalker();

private:
	std::vector<Cube*> boxes;
};

