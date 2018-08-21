#include <iostream>
#include <algorithm>
#include <cassert>

#include "Iterator.h"

using namespace std;
using namespace rookieiterator;

#include "gtest/gtest.h"

TEST(Size, RookieIterator) {
	RookieList<int> list;

	list.insert_front(2);
	ASSERT_EQ(list.size(), 1);
	list.insert_front(3);
	ASSERT_EQ(list.size(), 2);
	list.insert_front(100);
	ASSERT_EQ(list.size(), 3);

	ASSERT_EQ(list.front(), 100);
	list.pop_front();
	ASSERT_EQ(list.front(), 3);

	for_each(list.begin(), list.end(), [](auto& ele) { ele *= 2; });
	ASSERT_EQ(list.front(), 6);

	// auto b = find(list.begin(), list.end(), 6);
}

TEST(vector, RookieIterator) {
	RookieVector<int> v;
	v.push_back(4).push_back(3).push_back(5).push_back(10).push_back(12).push_back(-31);
	ASSERT_EQ(v.size(), 6);
	ASSERT_EQ(v.back(), -31);

	for_each(v.begin(), v.end(), [](auto& ele) { ele *= 2; });

	v.show();

	v.pop_back();

	v.show();

	v.pop_front();

	v.show();

	auto b = v.begin();
	b++;
	v.erase(b);
	v.show();

	// b = find(v.begin(), v.end(), 6);
}
