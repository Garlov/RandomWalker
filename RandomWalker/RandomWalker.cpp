#include "RandomWalker.h"

#include <common/objloader.hpp>
#include <common/vboindexer.hpp>

RandomWalker::RandomWalker()
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	bool res = loadOBJ("cube.obj", vertices, uvs, normals);

	indexVBO(vertices, uvs, normals, cubeIndices, indexed_cubeVertices, indexed_cubeUvs, indexed_cubeNormals);
}


RandomWalker::~RandomWalker()
{
}
