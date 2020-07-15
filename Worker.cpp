#include "Worker.hpp"
#include <thread>

namespace  {
static std::unique_ptr<std::vector<std::function<void()>>> jobs = std::make_unique<std::vector<std::function<void()>>>();
static std::unique_ptr<std::vector<std::thread>> threads = std::make_unique<std::vector<std::thread>>();
}

void Worker::addJob(std::function<void()> job)
{
	jobs->push_back(job);
}

void Worker::runJob()
{
	for (auto job : *jobs)
	{
		threads->push_back(std::thread(job));
	}

	jobs->clear();

	for (auto& th : *threads)
	{
		th.join();
	}

	threads->clear();
}

void Worker::init(const size_t& length,std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	Worker::addJob([&](){objMap = OwnMap::getObjMap(length);});
	Worker::addJob([&](){objVec =  OwnVector::getObjVector(length);});
	Worker::runJob();
}

void Worker::initVector(const size_t &length, std::unique_ptr<OwnVector> &objVec)
{
	Worker::addJob([&](){objVec =  OwnVector::getObjVector(length);});
	Worker::runJob();
}

void Worker::initMap(const size_t &length, std::unique_ptr<OwnMap> &objMap)
{
	Worker::addJob([&](){objMap = OwnMap::getObjMap(length);});
	Worker::runJob();
}

void Worker::clearVectorAndMap(std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	addJob([&](){objVec->clearVector();});
	addJob([&](){objMap->clearMap();});
	runJob();
}


bool isFindInVectorandMap(const unsigned short& digit, std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	return objMap->findDigitInMap(digit) && objVec->findDigitInVector(digit);
}

bool deleteDigitInVectorAndMap(const unsigned short& digit, std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	objMap->deleteDigitInMap(digit);
	objVec->deleteDigitInVector(digit);
	std::cout << digit << " is remove "<< std::endl;
}

void Worker::synchVectorAndMap(std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	for (auto i = 1; i < 10 ; i++)
	{
		if (!isFindInVectorandMap(i, objVec, objMap))
		{
			deleteDigitInVectorAndMap(i, objVec, objMap);
		}
	}
}

void Worker::printVectorAndMap(std::unique_ptr<OwnVector> &objVec, std::unique_ptr<OwnMap> &objMap)
{
	objMap->printMap();
	objVec->printVector();
}


