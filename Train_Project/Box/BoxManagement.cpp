#include "BoxManagement.hpp"
#include <iostream>
#include <vector>
#include <algorithm>



std::vector<Box>::iterator BoxManagement::findBoxPosition(Box const& box)
{
	for (std::vector<Box>::iterator pos = boxes.begin();
		pos != boxes.end(); pos++)
	{
		if(box == *pos)
		{
			return pos;
		}
	}
	return boxes.end();
}

void BoxManagement::insertSouvenirsInBox(Box* box_ptr)
{
	int souvenirsCount;
	std::cin >> souvenirsCount;
	for (int souvenirIndex = 0; souvenirIndex < souvenirsCount; souvenirIndex++)
	{
		std::string souvenir;
		std::cin >> souvenir;
		box_ptr->addSouvenir(souvenir);
	}
}

void BoxManagement::insertInnerBox(Box* box_ptr)
{
	int innerBoxesCount;
	std::cin >> innerBoxesCount;
	for (int inBoxIndex = 0; inBoxIndex < innerBoxesCount; inBoxIndex++)
	{
		std::string innerBoxLabel;
		std::cin >> innerBoxLabel;
		Box* innerBox_ptr = findBox(innerBoxLabel);
		Box newInnerBox;
		if (nullptr == innerBox_ptr)
		{
			newInnerBox.setLabel(innerBoxLabel);
			innerBox_ptr = &newInnerBox;
		}
		else
		{
			std::vector<Box>::iterator temp = findBoxPosition(*innerBox_ptr);
			newInnerBox = *temp;
			boxes.erase(temp);
			innerBox_ptr = &newInnerBox;
		}
		
	}
}


void BoxManagement::insertBoxes()
{
	int boxesCount;
	std::cout << "Enter Number of boxes: ";
	std::cin >> boxesCount;
	std::cout << "Enter information about boxes: ";
	for (int boxIndex = 0; boxIndex < boxesCount; boxIndex++)
	{
		std::string label;
		std::cin >> label;
		Box* currentBox_ptr = findBox(label);
		if (currentBox_ptr == nullptr)
		{
			Box newBox(label);
			boxes.push_back(newBox);
			currentBox_ptr = &boxes.back();
		}

		insertSouvenirsInBox(currentBox_ptr);
		insertInnerBox(currentBox_ptr);
	}

}
Box* BoxManagement::findBox(std::string const& label)
{
	for (std::vector<Box>::iterator it = boxes.begin();
		it != boxes.end(); it++)
	{
		Box* result = it->findBox(label);
		if (nullptr != result)
		{
			return result;
		}
	}
		return nullptr;
}
void BoxManagement::printBoxes()
{


}
