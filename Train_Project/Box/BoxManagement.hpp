#pragma once
#include "Box.hpp"
#include <vector>
class BoxManagement
{
private:
 
	std::vector<Box*> boxes; // contains pointers to dynamically created boxes
	std::vector<Box*>::iterator findBoxPosition(Box const& box);
	void insertSouvenirsInBox(Box* box_ptr);
	void insertInnerBox(Box* box_ptr);
public:
	// finctions for the task:
	void optimizeBoxes();
	void insertBoxes();
	//##################################

	Box* findBox(std::string const& label); // returns pointer to box with given label
											// or nulpptr if this box does not exist

	void printBoxes();
	~BoxManagement();
	std::vector<Box*> const& getBoxes()const { return boxes; }


};
