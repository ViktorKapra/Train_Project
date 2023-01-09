#pragma once
#include "../SkipList/SkipList.hpp"
#include <string>
#include <vector>
#include<map>
#include <iostream>

class RouteManager
{
private:
	SkipList<std::string> route;
	size_t lenght; // represents length of the route


	std::vector<std::string> findPathToDestination(std::string const& destination, SkipNode<std::string>* iter);

	void printRoute();
	std::vector<std::string> insertDesiredDestinations(std::istream& is);
	bool contain(std::vector<std::string> const& v, std::string const& s); 
public:
	
	void insertRoute(std::istream& is); // see the implementation to understand/test to understand format of the data
	std::vector<std::string> findOptimalWay(std::istream& is); // conditional A from the description
	

};