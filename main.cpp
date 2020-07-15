#include <iostream>
#include <Worker.hpp>

namespace  {
constexpr size_t length = 10;
}

int main()
{
	srand(time(0));
	std::unique_ptr<OwnMap> map = nullptr;
	std::unique_ptr<OwnVector> vec = nullptr;
	Worker::init(length, vec,map);
	Worker::printVectorAndMap(vec, map);
	Worker::clearVectorAndMap(vec,map);
	Worker::printVectorAndMap(vec, map);
	Worker::synchVectorAndMap(vec, map);
	Worker::printVectorAndMap(vec, map);
}
