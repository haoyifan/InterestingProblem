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

	for_each(list.begin(), list.end(), [](auto& ele) { ele.value() *= 2; });
	ASSERT_EQ(list.front(), 6);
}
