#include "Box.hpp"


void Box::addSouvenir(std::string const& souvenir)
{
	souvenirs.push_back(souvenir);
}
Box* Box::findBox(std::string _label)
{
	if (_label == this->label)
	{
		return this;
	}
	else
	{
		for (std::vector<Box>::iterator it = boxes.begin();
			it != boxes.end(); it++)
		{
			Box* result = it->findBox(_label);
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
	return;
}
void Box::addBox(Box& box)
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
