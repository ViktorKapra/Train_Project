// Train_Project.cpp : Defines the entry point for the application.
//

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.hpp"
//#include "SkipList/SkipList_test.hpp"
#include "Logic.hpp"
#include<iostream>
#include<fstream>

int main()
{
	Logic g;
//	g.insertRoute();
//	g.findOptimalWay();
	std::ifstream s("D:\\Stuff\\uni\\SDP\\Train_Project\\Train_Project\\Train_Project\\Burgas.txt");
	if(s.is_open())
	g.findLongestLandmarksWay(s);
	//g.printRoute();
}
/*
9
Sofia Pazardzhik Plovdiv Dimitrovgrad StaraZagora NovaZagora Yambol Karnobat Burgas
Sofia Plovdiv
Plovdiv NovaZagora
Dimitrovgrad NovaZagora
StaraZagora Yambol
NovaZagora Burgas
End
3
Plovdiv StaraZagora Yambol
*/

