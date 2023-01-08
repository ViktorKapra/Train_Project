#include "Logic.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <algorithm>
#define SkipListIterator SkipNode<std::string>*
void Logic::insertRoute()
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

void Logic::printRoute()
{
	route.print();
}

std::vector<std::string>  Logic::insertDesiredDestinations()
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

bool Logic::contain(std::vector<std::string> const& v, std::string const& s)
{
	for (std::string const& elem : v)
	{
		if (elem == s)
			return true;
	}
	return false;
}

void Logic::findOptimalWay()
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

std::vector<std::string> Logic::findPathToDestination(std::string const& destination, SkipNode<std::string>* iter)
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ConditionB 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Logic::getUniqueCount(std::vector<int>const& vec)
{
	int count = 0;
	for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++)
	{
		std::vector<int>::const_iterator cheker = vec.begin();
		while (cheker != i && *cheker != *i)
		{
			cheker++;
		}
		if (cheker == i) 
		{
			count++;
		}
	}
	return count;
}

void Logic::initializeGraph(std::vector<std::vector<int>>& graph, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::vector<int> row;
		for (int y = 0; y < size; y++)
		{
			row.push_back(0);
		}
		graph.push_back(row);
	}
}

int Logic::getElemntEncoding(std::string& edge, int& indexEncoder, std::map<std::string, int>& dict)
{
	std::map<std::string, int>::iterator e1 = dict.find(edge);
	if (e1 == dict.end())
	{
		dict.insert(std::pair<std::string, int>(edge, indexEncoder));
		return indexEncoder++;
	}
	else
	{
		return e1->second;
	}

}

void Logic::printGraph(std::vector<std::vector<int>>const& graph)
{
	for (int i = 0; i < graph.size(); i++)
	{
		for (int y = 0; y < graph.size(); y++)
		{
			std::cout << graph[i][y] << " ";
		}
		std::cout << std::endl;
	}
}

void Logic::getMaximalPath(std::vector<std::vector<int>>const& graph, std::vector<int>& maxPath,
	int currentPoint, std::vector<int>& path, int endPoint, int timeLimit)
{
	if (timeLimit < 0)
	{
		return;
	}
	if (currentPoint == endPoint)
	{
		path.push_back(currentPoint);
		if (getUniqueCount(maxPath) < getUniqueCount(path))
		{
			
			maxPath = path;
		}
		path.pop_back();
		return;
	}
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[currentPoint][i] > 0)
		{
			path.push_back(currentPoint);
			getMaximalPath(graph, maxPath, i, path, endPoint, timeLimit - graph[currentPoint][i]);
			path.pop_back();
		}
	}
	
}

std::string Logic::findKey(int elem, std::map<std::string, int>& encoding)
{
	for (std::map < std::string,int>::iterator it = encoding.begin(); it != encoding.end(); ++it)
		if (it->second == elem)
			return it->first;
}

void Logic::findLongestLandmarksWay(std::ifstream& is)
{
	int landmarksCount;
	is >> landmarksCount;
	std::map<std::string, int> encoding;
	int indexEncoder = 0;
	std::vector<std::vector<int>> graph;
	initializeGraph(graph, landmarksCount);
	int connectionsCount;
	is >> connectionsCount;
	for (int i = 0; i < connectionsCount; i++)
	{
		std::string edge1, edge2;
		int weight;
		is >> edge1 >> edge2 >> weight;
		int e1 = getElemntEncoding(edge1, indexEncoder, encoding);
		int e2 = getElemntEncoding(edge2, indexEncoder, encoding);
		graph[e1][e2] = weight;
		graph[e2][e1] = weight;
	}
	int timeLimit;
	is >> timeLimit;

	std::vector<int> maximalPath;
	int railStationCode = encoding.find("Railstation")->second;
	for (int i = 0; i < landmarksCount; i++)
	{
		if (graph[railStationCode][i] > 0)
		{
			std::vector<int> path;
			path.push_back(railStationCode);
			getMaximalPath(graph, maximalPath,i,path, railStationCode,timeLimit - graph[railStationCode][i]);
		}
	}
		
	if (maximalPath.size() > 0)
	{
		for (int i = 0; i < maximalPath.size(); i++)
		{
			std::cout << findKey(maximalPath[i], encoding) << " ";
		}
	}

}