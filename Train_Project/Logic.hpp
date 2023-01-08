#pragma once
#include "SkipList/SkipList.hpp"
#include <string>
#include <vector>
#include<map>


class Logic
{
private:
	SkipList<std::string> route;
	size_t lenght;
public:
	// conditional A
	void insertRoute();
	void printRoute();
	std::vector<std::string> insertDesiredDestinations();
	bool contain(std::vector<std::string> const& v, std::string const& s);
	void findOptimalWay();
	std::vector<std::string> findPathToDestination(std::string const& destination, SkipNode<std::string>* iter);

	// conditional B
	int getUniqueCount(std::vector<int> const& vec);
	void initializeGraph(std::vector<std::vector<int>>& graph, int size);
	int getElemntEncoding(std::string& edge, int& indexEncoder, std::map<std::string, int>& dict);
	void printGraph(std::vector<std::vector<int>> const& graph);
	void getMaximalPath(std::vector<std::vector<int>> const& graph, std::vector<int>& maxPath,
	int currentPoint, std::vector<int>& path, int endPoint, int timeLimit);
	std::string findKey(int elem, std::map<std::string, int>& encoding);
	void findLongestLandmarksWay(std::ifstream& is);
};