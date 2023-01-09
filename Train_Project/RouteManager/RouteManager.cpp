#include "RouteManager.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <algorithm>

#define SkipListIterator SkipNode<std::string>*
void RouteManager::insertRoute()
{
	std::cout << "Enter count of the stations: ";
	std::cin >> lenght;
	for (int i = 0; i < lenght; i++)
	{
		std::string station;
		std::cin >> station;
		route.addLast(station);
	}

	std::string start;
	std::string end;
	do
	{
		std::cin.ignore();

		std::cin >> start;
		//std::cin.ignore();
		if (start != "End")
		{
			std::cin >> end;
			route.addConnection(route.findNode(start), route.findNode(end));
		}
	} while (start != "End");
}

void RouteManager::printRoute()
{
	route.print();
}

std::vector<std::string>  RouteManager::insertDesiredDestinations()
{
	std::vector<std::string> result;
	std::string station;
	int count;
	std::cout << "Insert count of desired destinations: ";
	std::cin >> count;
	for (int i = 0; i < count; i++)
	{
		std::cin >> station;
		result.push_back(station);
	}
	return result;
}

bool RouteManager::contain(std::vector<std::string> const& v, std::string const& s)
{
	for (std::string const& elem : v)
	{
		if (elem == s)
			return true;
	}
	return false;
}

void RouteManager::findOptimalWay()
{
	std::vector<std::string> destinations = insertDesiredDestinations();
	if (!contain(destinations, route.getEnd()->data))
	{
		destinations.push_back(route.getEnd()->data);
	}
	SkipListIterator iter = route.getRoot();
	std::vector<std::string> result;
	for (std::string const& destination : destinations)
	{
		if (iter != nullptr)
		{
			std::vector<std::string> path = findPathToDestination(destination, iter);
			for (std::string const& station : path)
			{
				if (!contain(result, station))
				{
					result.push_back(station);
				}
			}
			while (iter->data != destination)
			{
				iter = iter->next;
			}

		}
		else
		{
			throw std::invalid_argument("Incorecrt data");
		}
	}
	std::cout << "The shortest path is: " << std::endl;
	for (std::string const& station : result)
	{
		std::cout << station << " ";
	}
}

std::vector<std::string> RouteManager::findPathToDestination(std::string const& destination, SkipNode<std::string>* iter)
{
	std::vector<std::string> result;
	if (nullptr == iter)
	{
		return result;
	}

	result.push_back(iter->data);
	if (iter->data == destination)
	{
		return result;
	}

	std::vector<std::string> fastWay = findPathToDestination(destination, iter->direct);
	std::vector<std::string> nextWay = findPathToDestination(destination, iter->next);
	if (!fastWay.empty() && fastWay.back() == destination &&
		fastWay.size() < nextWay.size())
	{
		result.insert(result.end(), fastWay.begin(), fastWay.end());
	}
	else
	{
		result.insert(result.end(), nextWay.begin(), nextWay.end());
	}
	return result;

}
