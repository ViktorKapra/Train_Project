#pragma once
#include "../SkipList/SkipList.hpp"
#include <string>
#include <vector>
#include<map>


class RouteManager
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

};