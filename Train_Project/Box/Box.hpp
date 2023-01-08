#pragma once
#include<vector>
#include <string>

class Box
{
private:
	std::vector<Box> boxes;
	std::vector<std::string> souvenirs;
	std::string label;
public:
	Box(std::string _label = "unlabeled") :label(_label){ }
	std::string const& getLabel()const { return label; }
	void addSouvenir(std::string const& souvenir);
	Box* findBox(std::string _label);
	void printBox();
	void addBox(Box& box);
	void setLabel(std::string const& _label);
	bool operator==(Box const& other)const;
};