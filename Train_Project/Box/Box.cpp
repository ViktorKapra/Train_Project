#include "Box.hpp"
#include <iostream>

void Box::addSouvenir(std::string const& souvenir)
{
	souvenirs.push_back(souvenir);
}
Box* Box::findBox(std::string const& _label)
{
	if (_label == this->label)
	{
		return this;
	}
	else
	{
		for (std::vector<Box*>::iterator it = boxes.begin();
			it != boxes.end(); it++)
		{
			Box* result = (*it)->findBox(_label);
			if (nullptr != result)
			{
				return result;
			}
		}
		return nullptr;
	}
}
void Box::printBox()
{
	std::cout << this->label <<" ";
	std::cout << "Inner Boxes : ( ";
	for (int i = 0; i < boxes.size(); i++)
	{
		boxes[i]->printBox();
	}
	std::cout << ")";
	std::cout << "< Souvenirs: ";
	for (int i = 0; i < souvenirs.size(); i++)
	{
		std::cout << souvenirs[i] << " ";
	}
	std::cout << " >";
	return;
}
void Box::addBox(Box* box)
{
	boxes.push_back(box);
}
void Box::setLabel(std::string const& _label)
{
	this->label = _label;
}

bool Box::operator==(Box const& other)const
{
	return this->getLabel() == other.getLabel();
}

void Box::optimize()
{
	if (boxes.empty())
	{
		return;
	}
	std::vector<Box*> forRemoving;
	std::vector<Box*> forAdding;
	std::vector<Box*>::iterator it = boxes.begin();
	while (it != boxes.end())
	{
		(*it)->optimize();
		if ((*it)->getSouvenirsCount() == 0)
		{
			if ((*it)->getInnerBoxesCount() == 1)
			{
				forAdding.push_back((*it)->boxes.front());
				forRemoving.push_back(*it);
			}
			else if ((*it)->getInnerBoxesCount() == 0)
			{
				forRemoving.push_back(*it);
			}
				it++;
			
		}
		else
		{
			it++;
		}
	}
	for (int i = 0; i < forRemoving.size(); i++)
	{
		boxes.erase(std::find(boxes.begin(), boxes.end(), forRemoving[i]));
	}

	for (int i = 0; i < forAdding.size(); i++)
	{
		boxes.push_back(forAdding[i]);
	}

}
Box::~Box()
{
	for (Box* b : boxes)
	{
		delete b;
	}
}
