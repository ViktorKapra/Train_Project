#pragma once
#include "Box.hpp"
#include <vector>
class BoxManagement
{
private:
	std::vector<Box> boxes;
	std::vector<Box>::iterator findBoxPosition(Box const& box);
	void insertSouvenirsInBox(Box* box_ptr);
	void insertInnerBox(Box* box_ptr);
public:
	void insertBoxes();
	Box* findBox(std::string const& label);
	void printBoxes();
	


};
