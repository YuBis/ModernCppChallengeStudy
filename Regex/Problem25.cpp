// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>


void WordHeadToUpper(std::string n)
{

	std::string item(n);
	std::string result;

	std::transform(item.begin(), item.end(), item.begin(), [](char c) { return std::tolower(c); });

	std::stringstream ss;
	ss.str(item);
	

	std::string next;
	while (ss >> next)
	{
		if ('a' <= next[0] && next[0] <= 'z')
		{
			next[0] = std::toupper(next[0]);
		}

		result = result + next + ' ';
	}

	std::cout << result << std::endl;
}

int main()
{
	char input_arr[100];
	std::cin.getline(input_arr, sizeof(input_arr));
	WordHeadToUpper(input_arr);
	_getch();
    return 0;
}

