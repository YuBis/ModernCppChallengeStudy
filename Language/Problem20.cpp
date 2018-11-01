// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>
#include <cassert>

template <typename T, typename C>
bool contains_any(C& container, std::initializer_list<T> value_list)
{
	for (const auto& checklist : value_list)
	{
		for (const auto& item : container)
		{
			if (checklist == item)
				return true;
		}
	}
	return false;
}

template <typename T, typename C>
bool contains_all(C& container, std::initializer_list<T> value_list)
{
	int contains_count = 0;

	for (const auto& checklist : value_list)
	{
		for (const auto& item : container)
		{
			if (checklist == item)
				++contains_count;
		}
	}
	if( contains_count == value_list.size())
		return true;

	return false;
}

template <typename T, typename C>
bool contains_none(C& container, std::initializer_list<T> value_list)
{
	for (const auto& checklist : value_list)
	{
		for (const auto& item : container)
		{
			if (checklist == item)
				return false;
		}
	}
	return true;
}

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
	assert(contains_any(v, { 0, 3, 30 }));

	std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
	assert(contains_all(a, { 1, 3, 5, 6 }));

	std::list<int> l{ 1, 2, 3, 4, 5, 6 };
	assert(!contains_none(l, { 0, 6 }));
	_getch();
    return 0;
}

