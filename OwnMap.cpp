#include "OwnMap.hpp"


OwnMap::OwnMap(size_t length):length(length)
{
	map = std::make_unique<std::map<unsigned long, unsigned short>>();

	for (auto i = 0; i < length; i++)
	{
		(*map)[i] = rand() % 9 + 1;
	}
}

std::unique_ptr<OwnMap> OwnMap::getObjMap(size_t size)
{
	std::unique_ptr<OwnMap> obj = std::make_unique<OwnMap>(size);
	return std::move(obj);
}

bool OwnMap::findDigitInMap(const unsigned short &digit)
{
	for (auto const& item : *map)
	{
		if (item.second == digit)
		{
			return true;
		}
	}
	return false;
}

void OwnMap::deleteDigitInMap(const unsigned short &digit)
{
	for (auto iter = map->begin(); iter!= map->end();)
	{
		if ((*iter).second == digit)
		{
			iter = map->erase(iter);
		}else
		{
			++iter;
		}
	}
}

void OwnMap::printMap()
{
	std::cout << std::endl;

	for (const auto &[key, value] : *map)
	{
		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << key << " " ;
	}

	std::cout << std::endl;

	for (const auto &[key, value] : *map)
	{
		std::cout.setf(std::ios::left);
		std::cout.width(2);
		std::cout << value << " " ;
	}
}

void OwnMap::clearMap()
{
	for (auto iter = map->begin(); iter!= map->end();)
	{
		static unsigned short delCount = 0;
		if (delCount < 15 && (*iter).second == rand()%9+1)
		{
			delCount++;
			iter = map->erase(iter);
		}else
		{
			++iter;
		}
	}
}
