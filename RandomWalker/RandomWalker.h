#pragma once
#include <vector>
#include "Box.h"

class RandomWalker
{
public:
	RandomWalker();
	~RandomWalker();

private:
	std::vector<Box*> boxes;
};

