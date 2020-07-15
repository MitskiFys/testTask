#include "OwnVector.hpp"
#include <algorithm>

OwnVector::OwnVector(size_t length):length(length)
{
	vec = std::make_unique<std::vector<unsigned short>>(length);
	std::generate(vec->begin(), vec->end(), []{return rand() % 9 + 1;});
}

std::unique_ptr<OwnVector> OwnVector::getObjVector(size_t size)
{
	return std::move(std::make_unique<OwnVector>(size));
}

bool OwnVector::findDigitInVector(const unsigned short &digit)
{
	return std::find(vec->begin(), vec->end(), digit) != vec->end();
}

void OwnVector::deleteDigitInVector(const unsigned short &digit)
{
	vec->erase(std::remove(vec->begin(), vec->end(),digit), vec->end());
}

void OwnVector::printVector()
{
	std::cout << std::endl;

	for (const auto& v : *vec)
	{
		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << v << " ";
	}

	std::cout << std::endl;
}

void OwnVector::clearVector()
{
	vec->erase(std::remove_if(vec->begin(), vec->end(),[](auto const &elem)->bool
	{
		static unsigned short delCount = 0;
		if (delCount < 15 && elem == rand()%9+1)
		{
			delCount++;
			return true;
		} else
		{
			return false;
		}

	}), vec->end());
}

