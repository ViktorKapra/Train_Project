#pragma once
#include "SkipList.hpp"
#include "../doctest.hpp"


TEST_CASE("Creating SkipList and adding some elements")
{
	SkipList<int> l;
	l.addLast(5);
	l.addLast(6);
	l.addLast(7);
	CHECK(l.getRoot()->data == 5);
}


TEST_CASE("Finding nodes in Skiplist")
{
	SkipList<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.addLast(i);

	}
	for (int i = 9; i >= 1; i--)
	{
		CHECK((l.findNode(i))->data == i);
	}

	CHECK_FALSE(l.findNode(12));
}

TEST_CASE("SkipList with no elements is empty")
{
	SkipList<int> l;
	CHECK(l.empty());
}

