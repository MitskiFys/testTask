#pragma once
#include <iostream>
#include <vector>
#include <memory>

class OwnVector
{
public:
	///
	///Constructor
	///
	OwnVector(size_t);
	///
	/// \brief getObjVector
	/// \return
	///This static method allows us to get an object.
	static std::unique_ptr<OwnVector>getObjVector(size_t);

	///
	/// \brief findDigitInVector
	/// \param digit
	/// \return
	///This method helps us verify the existence of an element.
	bool findDigitInVector(const unsigned short& digit);

	///
	/// \brief clearVector
	///This method removes a random number of items.
	void clearVector();

	///
	/// \brief deleteDigitInVector
	/// \param digit
	///This method removes elements whose values ​​are equal to a given number.
	void deleteDigitInVector(const unsigned short& digit);

	///
	/// \brief printVector
	///This method prints a vector.
	void printVector();

private:
	std::unique_ptr<std::vector<unsigned short>> vec = nullptr;
	size_t length;

};

