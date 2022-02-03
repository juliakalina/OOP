#include "pch.h"

#include "pch.h"
#include "gtest\gtest.h"
#include <iostream>
#include <Windows.h>
#include "../lab4/LINK.h"

using namespace ArmyBase;


TEST(MVECTOR_METHODS, CONSTRUCTOR_AND_SIZE) {
	mvector<int> v(123);
	ASSERT_EQ(123, v.size());
}

TEST(MVECTOR_METHODS, PUSH_BACK_AND_SIZE) {
	mvector<int> v(123);
	v.push_back(1234);
	ASSERT_EQ(124, v.size());
	ASSERT_EQ(1234, v[123]);
}

TEST(MVECTOR_METHODS, EMPTY) {
	mvector<int> v;
	ASSERT_EQ(true, v.empty());
}

TEST(MVECTOR_METHODS, PUSH) {
	mvector<int> v(123);
	v.push(1234);
	ASSERT_EQ(1234, v[0]);
}

TEST(MVECTOR_METHODS, PUSH_BACK_AND_OPERATOR_BRACKETS) {
	mvector<int> v;
	v.push_back(111);
	v.push_back(222);
	v.push_back(333);
	ASSERT_EQ(111, v[0]);
	ASSERT_EQ(222, v[1]);
	ASSERT_EQ(333, v[2]);
}

TEST(MVECTOR_METHODS, ITERATOR_BEGIN_AND_END) {
	mvector<int> v(10);
	ASSERT_EQ(v.begin(), &v[0]);
	ASSERT_EQ(v.end(), &v[0] + 10);
}

TEST(VECITERATOR_METHODS, CONSTRUCTOR_AND_LINK) {
	mvector<int> v;
	v.push_back(1234);
	VecIterator<int> it1(&v[0]);
	ASSERT_EQ(*it1, v[0]);
}

TEST(VECITERATOR_METHODS, EQUAL) {
	mvector<int> v;
	v.push_back(1234);
	VecIterator<int> it = v.begin();
	ASSERT_EQ(it, v.begin());
}

TEST(VECITERATOR_METHODS, INCR_PREFIX) {
	mvector<int> v;
	v.push_back(1234);
	v.push_back(5678);
	VecIterator<int> it = v.begin();
	ASSERT_EQ(*(++it), v[1]);
}

TEST(VECITERATOR_METHODS, INCR_POSTFIX) {
	mvector<int> v;
	v.push_back(1234);
	v.push_back(5678);
	VecIterator<int> it = v.begin();
	ASSERT_EQ(*(it++), v[0]);
	ASSERT_EQ(*it, v[1]);
}

TEST(VECITERATOR_METHODS, ADD_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	VecIterator<int> it = v.begin();
	ASSERT_EQ(*(it += 2), 33);
}

TEST(VECITERATOR_METHODS, ADD) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	VecIterator<int> it = v.begin();
	ASSERT_EQ(*(it + 3), 44);
}

TEST(VECITERATOR_METHODS, SUBTRACT_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	VecIterator<int> it = v.end();
	ASSERT_EQ(*(it -= 3), 33);
}

TEST(VECITERATOR_METHODS, SUBTRACT) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	VecIterator<int> it = v.begin() + 3;
	ASSERT_EQ(*(it - 3), 11);
}

TEST(VECITERATOR_METHODS, SUBTRACT_ITERATORS) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 4;
	ASSERT_EQ(it2 - it1, 4);
}

TEST(VECITERATOR_METHODS, LESS) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 1;
	ASSERT_EQ(it1 < it2, true);
	ASSERT_EQ(it2 > it1, true);
}

TEST(VECITERATOR_METHODS, LESS_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 1;
	ASSERT_EQ(it1 <= it2, true);
	ASSERT_EQ(++it1 <= it2, true);
}

TEST(VECITERATOR_METHODS, MORE_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 1;
	ASSERT_EQ(it2 >= it1, true);
	ASSERT_EQ(--it2 >= it1, true);
}

TEST(VECITERATOR_METHODS, EQUAL_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 1;
	ASSERT_EQ(it2 == it1, false);
	ASSERT_EQ(--it2 == it1, true);
}

TEST(VECITERATOR_METHODS, NOT_EQUAL) {
	mvector<int> v;
	v.push_back(11);
	v.push_back(22);
	VecIterator<int> it1 = v.begin();
	VecIterator<int> it2 = v.begin() + 1;
	ASSERT_EQ(it2 != it1, true);
	ASSERT_EQ(--it2 != it1, false);
}

int _tmain(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}