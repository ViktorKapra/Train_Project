#pragma once
#include "WalkManager.hpp"
#include "../doctest.hpp"
#include <algorithm>    
#include <utility>


TEST_CASE("Finding maximal walk (example from the descriptions of the task)")
{
	WalkManager wm;
	std::ifstream s("D:\\Stuff\\uni\\SDP\\Train_Project\\Train_Project\\Train_Project\\Burgas.txt");
	REQUIRE(s.is_open());
	std::vector<std::string> result = wm.findLongestLandmarksWay(s);
	std::string expectation[] = { "Railstation", "RomanStadium", "DzhumayaSquare", "ArtGallery", "AntiqueTheatre", "ArtGallery", "Railstation" };
	int expecteLength = 7;
	REQUIRE(result.size() == expecteLength);
	CHECK(result[0] == expectation[0]);
	CHECK(result[expecteLength - 1] == expectation[expecteLength  - 1]);
	for (int i = 0; i < expecteLength; i++)
	{
		CHECK( (std::find(result.begin(), result.end(), expectation[i]) != result.end()) );
	}

}

TEST_CASE("No time for a walk test")
{
	WalkManager wm;
	std::ifstream s("D:\\Stuff\\uni\\SDP\\Train_Project\\Train_Project\\Train_Project\\NoTime.txt");
	REQUIRE(s.is_open());
	std::vector<std::string> result = wm.findLongestLandmarksWay(s);
	std::string expectation[] = { "Railstation"};
	int expecteLength = 1;
	REQUIRE(result.size() == expecteLength);
	CHECK(result[0] == expectation[0]);

}