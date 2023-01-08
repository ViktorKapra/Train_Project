#pragma once
#include <list>
#include <exception>
#define Iter SkipNode<T>*
template <typename T>
struct SkipNode
{
	T data;
	SkipNode* next;
	SkipNode* direct;
};


template <typename T>
class SkipList
{
private:
	SkipNode<T>* root;
	SkipNode<T>* end;

public:


	SkipList() :root(nullptr), end(nullptr) {}
	SkipList(SkipList<T> const& other);
	SkipList<T>& operator=(SkipList<T> const& other);
	~SkipList();
	void addLast(T const& data);
	void addConnection(SkipNode<T>* from, SkipNode<T>* to);
	void copy(SkipList<T> const& other);
	void erase();
	bool empty();
	SkipNode<T>* findNode(T const& data);
	SkipNode<T>* getRoot()const;
	SkipNode<T>* getEnd()const;
	void print();

};

template <typename T>
void SkipList<T>::addLast(T const& _data)
{
	SkipNode<T>* oldEnd = end;
	end = new SkipNode<T>{  _data, nullptr, nullptr };
	if (nullptr == root)
	{
		root = end;
	}
	else
	{
		oldEnd->next = end;
	}
}
template <typename T>
void SkipList<T>::addConnection(SkipNode<T>* from, SkipNode<T>* to)
{
	if (nullptr == from || nullptr == to)
	{
		throw std::invalid_argument("Invalid parameters");
	}
	from->direct = to;
}

template <typename T>
SkipList<T>::SkipList<T>(SkipList<T> const& other)
{
	copy(other);
}

template <typename T>
SkipList<T>& SkipList<T>::operator=(SkipList<T> const& other)
{
	if (*this != other)
	{
		this->erase();
		copy(other);
	}
	return this;
}

template <typename T>
void SkipList<T>::erase()
{
	if (root != nullptr)
	{
		SkipNode<T>* t = root;
		while (t != nullptr)
		{
			SkipNode<T>* old = t;
				t = t->next;
			delete old;
		}
	}
	root = end = nullptr;
}

template <typename T>
void SkipList<T>::copy(SkipList<T> const& other)
{
	// copying data
	SkipNode<T>* it = other.root;
	while (it != nullptr)
	{
		addLast(it->data);
	}
	// copying connections
	SkipNode<T>* otherIter = other.root;
	SkipNode<T>* currentIter = this->root;
	while (otherIter != nullptr)
	{
		if (otherIter->direct != nullptr)
		{
			addConnection(currentIter, findNode(otherIter->data));
		}
		otherIter = otherIter->next;
		currentIter = currentIter->next;
	}

}

template <typename T>
SkipNode<T>* SkipList<T>::findNode(T const& data) // returns pointer to node with given data or nullptr if node was not found
{
	if (empty())
	{
		throw std::invalid_argument("Container is empty");
	}
	Iter result = root;
	while (result != nullptr && result->data != data)
	{
		result = result->next;
	}
	return result;
}

template <typename T>
bool SkipList<T>::empty()
{
	return nullptr == root && nullptr == end;
}
template <typename T>
SkipList<T>::~SkipList()
{
	erase();
}
template<typename T>
SkipNode<T>* SkipList<T>::getRoot()const
{
	return root;
}
template<typename T>
SkipNode<T>* SkipList<T>::getEnd()const
{
	return end;
}
template <typename T>
void SkipList<T>::print()
{
	SkipNode<T>* it = getRoot();
	SkipNode<T>* end = getEnd();
	for (it; it != end; it = it->next)
	{
		std::cout << it->data << " ";
		if (nullptr != it->direct)
		{
			std::cout << it->direct->data;
		}
		else
		{
			std::cout << "Nothing";
		}
		std::cout << std::endl;
	}
}
