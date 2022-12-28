#pragma once
#include <list>
#define Iter SkipNode*
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
	SkipNode* root;
	SkipNode* end;
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
	SkipNode* findNode(T const& data);

};

template <typename T>
void SkipList<T>::addLast(T const& _data)
{
	SkipNode* oldEnd = end;
	end = new SkipNode<T>{ data = _data, next = nullptr, direct = nullptr };
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
		throw std::argument_exception();
	}
	from->direct == to;
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
		Itet t = root;
		while (t != nullptr)
		{
			Iter old = t
				t = t->next;
			delete old;
		}
	}
}

template <typename T>
void SkipList<T>::copy(SkipList<T> const& other)
{
	// copying data
	Iter it = other.root;
	while (it != nullptr)
	{
		addLast(it->data);
	}
	// copying connections
	Iter otherIter = other.root;
	Iter currentIter = this->root;
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
		throw std::invalid_argument();
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
