#pragma once
#include "RouteManager.hpp"
#include <sstream> 
#include <string>
#include"../doctest.hpp"

TEST_CASE("Finding right route (example from the descriptions of the task)")
{
	RouteManager rm;
	std::string sc;
	sc += " 9 \n";
	sc += "Sofia Pazardzhik Plovdiv Dimitrovgrad StaraZagora NovaZagora Yambol Karnobat Burgas \n";
	sc += "Sofia Plovdiv \n";
	sc += "Plovdiv NovaZagora \n";
	sc += "Dimitrovgrad NovaZagora \n";
	sc += "StaraZagora Yambol \n";
	sc += "NovaZagora Burgas \n";
	sc += "End \n";
	sc += "3 \n";
	sc += "Plovdiv StaraZagora Yambol \n";

	std::stringstream scenario;
	scenario << sc;
	rm.insertRoute(scenario);
	std::vector<std::string> result = rm.findOptimalWay(scenario);
	std::string expectation[] = { "Sofia", "Plovdiv", "Dimitrovgrad" , "StaraZagora", "Yambol", "Karnobat", "Burgas"};
	int expectedLenght = 7;
	REQUIRE(result.size() == expectedLenght);
	for (int i = 0; i < expectedLenght; i++)
	{
		CHECK(result[i] == expectation[i]);
	}
	
}

TEST_CASE("Finding shortest route from beginning and end")
{
	RouteManager rm;
	std::string sc;
	sc += " 9 \n";
	sc += "Sofia Pazardzhik Plovdiv Dimitrovgrad StaraZagora NovaZagora Yambol Karnobat Burgas \n";
	sc += "Sofia Plovdiv \n";
	sc += "Plovdiv NovaZagora \n";
	sc += "Dimitrovgrad NovaZagora \n";
	sc += "StaraZagora Yambol \n";
	sc += "NovaZagora Burgas \n";
	sc += "End \n";
	sc += "2 \n";
	sc += "Sofia Burgas \n";

	std::stringstream scenario;
	scenario << sc;
	rm.insertRoute(scenario);
	std::vector<std::string> result = rm.findOptimalWay(scenario);
	std::string expectation[] = { "Sofia", "Plovdiv", "NovaZagora", "Burgas" };
	int expectedLenght = 4;
	REQUIRE(result.size() == expectedLenght);
	for (int i = 0; i < expectedLenght; i++)
	{
		CHECK(result[i] == expectation[i]);
	}
}