#include "WalkManager.hpp"
#include<iostream>
#include<fstream>

int WalkManager::getUniqueCount(std::vector<int>const& vec)
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

void WalkManager::initializeGraph(std::vector<std::vector<int>>& graph, int size)
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

int WalkManager::getElemntEncoding(std::string& edge, int& indexEncoder, std::map<std::string, int>& dict)
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

void WalkManager::printGraph(std::vector<std::vector<int>>const& graph)
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

void WalkManager::getMaximalPath(std::vector<std::vector<int>>const& graph, std::vector<int>& maxPath,
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

std::string WalkManager::findKey(int elem, std::map<std::string, int>& encoding)
{
	for (std::map < std::string, int>::iterator it = encoding.begin(); it != encoding.end(); ++it)
		if (it->second == elem)
			return it->first;
}

std::vector<std::string> WalkManager::findLongestLandmarksWay(std::ifstream& is)
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
			getMaximalPath(graph, maximalPath, i, path, railStationCode, timeLimit - graph[railStationCode][i]);
		}
	}

	std::vector<std::string> result;
	if (maximalPath.size() > 0)
	{
		for (int i = 0; i < maximalPath.size(); i++)
		{
			result.push_back(findKey(maximalPath[i], encoding));
		}
	}
	else
	{
		result.push_back("Railstation");
	}
	return result;
}