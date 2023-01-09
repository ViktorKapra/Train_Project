#pragma once
#include<vector>
#include <string>

class Box
{
private:
	std::vector<Box*> boxes;
	std::vector<std::string> souvenirs;
	std::string label;
public:
	friend class BoxManagement;
	size_t getInnerBoxesCount()const { return boxes.size(); }
	size_t getSouvenirsCount()const { return souvenirs.size(); }
	Box(std::string _label = "unlabeled") :label(_label){ }
	std::string const& getLabel()const { return label; }
	void addSouvenir(std::string const& souvenir);
	Box* findBox(std::string const& _label);
	void printBox();
	void optimize();
	void addBox(Box* box);
	void setLabel(std::string const& _label);
	bool operator==(Box const& other)const;
	~Box();
};