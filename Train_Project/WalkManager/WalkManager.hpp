#pragma once
#include<string>
#include <vector>
#include <map>
class WalkManager
{
private:
	
	// returns uniques edges in path
	int getUniqueCount(std::vector<int> const& vec);
	void initializeGraph(std::vector<std::vector<int>>& graph, int size);

	/// <summary>
	/// Return encoding value of given edge
	/// </summary>
	int getElemntEncoding(std::string& edge, int& indexEncoder, std::map<std::string, int>& dict);
	void printGraph(std::vector<std::vector<int>> const& graph);
	
	/// <summary>
	/// Finds maximal path in graph with a weight under "timeLimit"
	/// the path is returned in param - "maxPath"
	/// </summary>
	void getMaximalPath(std::vector<std::vector<int>> const& graph, std::vector<int>& maxPath,
	int currentPoint, std::vector<int>& path, int endPoint, int timeLimit);

	std::string findKey(int elem, std::map<std::string, int>& encoding);
public:
	std::vector<std::string> findLongestLandmarksWay(std::ifstream& is); // conditional B
};