// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>

template <typename T, typename C>
auto Extend_Container(std::initializer_list<T> value_list, C& container)
{
	for (auto item : value_list)
	{
		container.push_back(item);
	}
}

int main()
{
	std::vector<int> vec{ 1,2,3,4,5,6 };
	Extend_Container({ 7,8,9,10 }, vec);

	for (auto item : vec)
	{
		std::cout << item;
	}
	_getch();
    return 0;
}

