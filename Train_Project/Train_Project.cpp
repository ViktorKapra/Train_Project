// Train_Project.cpp : Defines the entry point for the application.
//

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.hpp"
//#include "RouteManager/RouteManager_test.hpp"
//#include "SkipList/SkipList_test.hpp"
//#include "WalkManager/WalkManager_test.hpp"

#include<iostream>
#include<fstream>

#include "Box/BoxManagement.hpp"
int main()
{
	BoxManagement bm;
	bm.insertBoxes();
	bm.optimizeBoxes();
	bm.printBoxes();

}

/*
10
PlovdivBox 2 Magnet Book 2 ArtBox TheatreBox
ArtBox 0 1 Drawings
Drawings 1 OldPlovdiv 0
TheatreBox 0 1 TheatreSouvenirs
TheatreSouvenirs 0 2 Plates Bags
Plates 1 DecorativePlate 0
Bags 0 0
StaraZagoraBox 1 Postcard 2 Figurines Cups
Figurines 1 AncientFigurine 0
Cups 1 TraditionalCup 0


*/

