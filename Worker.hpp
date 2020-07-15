#pragma once
#include <iostream>
#include <functional>
#include <memory>
#include <vector>
#include <OwnMap.hpp>
#include <OwnVector.hpp>

class Worker
{
public:
	///
	/// \brief init
	/// \param length
	/// This method initializes the vector and map.
	static void init(const size_t& length, std::unique_ptr<OwnVector> &, std::unique_ptr<OwnMap> &);

	///
	/// \brief initVector
	/// \param length
	///This method initializes only vector.
	static void initVector(const size_t& length, std::unique_ptr<OwnVector> &);

	///
	/// \brief initMap
	/// \param length
	///This method initializes only map.
	static void initMap(const size_t& length, std::unique_ptr<OwnMap> &);

	///
	/// \brief clearVectorAndMap
	///This method will randomly remove several items (no more than 15)
	static void clearVectorAndMap(std::unique_ptr<OwnVector> &, std::unique_ptr<OwnMap> &);

	///
	/// \brief synchVectorAndMap
	///This method synchronizes the vector and map, leaving only elements available only in both containers.
	static void synchVectorAndMap(std::unique_ptr<OwnVector> &, std::unique_ptr<OwnMap> &);

	///
	/// \brief printVectorAndMap
	///This method prints map and vector
	static void printVectorAndMap(std::unique_ptr<OwnVector> &, std::unique_ptr<OwnMap> &);
private:
	///
	/// \brief addJob
	///This method adds to the queue the work that needs to be done and divides it into threads
	static void addJob(std::function<void()>);

	///
	/// \brief runJob
	///This method starts up.
	static void runJob();
};

