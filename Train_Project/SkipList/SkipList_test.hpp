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

TEST_CASE("SkipList with no elements is empty")
{
	SkipList<int> l;
	CHECK(l.empty());
}

