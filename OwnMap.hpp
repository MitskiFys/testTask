#pragma once
#include <iostream>
#include <map>
#include <memory>
class OwnMap
{
public:
	///
	///The constructor creates a map with the specified size
	///
	OwnMap(size_t);
	///
	/// \brief getObjMap
	/// \return
	///This static method allows us to map the desired number of elements.
	static std::unique_ptr<OwnMap> getObjMap(size_t);

	///
	/// \brief findDigitInMap
	/// \param digit
	/// \return
	///This method checks for the existence of a number
	bool findDigitInMap(const unsigned short& digit);

	///
	/// \brief clearMap
	///This method removes a random number of items.
	void clearMap();

	///
	/// \brief deleteDigitInMap
	/// \param digit
	///This method removes all elements whose values ​​are equal to this number.
	void deleteDigitInMap(const unsigned short& digit);

	///
	/// \brief printMap
	///This method prints map
	void printMap();
private:
	std::unique_ptr<std::map<unsigned long,unsigned short>> map = nullptr;
	size_t length;

};

