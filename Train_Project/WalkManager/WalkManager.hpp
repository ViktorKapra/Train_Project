#pragma once
#include<string>
#include <vector>
#include <map>
class WalkManager
{
private:
	// conditional B
	int getUniqueCount(std::vector<int> const& vec);
	void initializeGraph(std::vector<std::vector<int>>& graph, int size);
	int getElemntEncoding(std::string& edge, int& indexEncoder, std::map<std::string, int>& dict);
	void printGraph(std::vector<std::vector<int>> const& graph);
	void getMaximalPath(std::vector<std::vector<int>> const& graph, std::vector<int>& maxPath,
	int currentPoint, std::vector<int>& path, int endPoint, int timeLimit);
	std::string findKey(int elem, std::map<std::string, int>& encoding);
public:
	void findLongestLandmarksWay(std::ifstream& is);
};