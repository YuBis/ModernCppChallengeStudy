// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <array>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>


void MixString(std::array<std::string, 4> n, std::string token)
{
	std::string result;

	std::for_each(n.begin(), n.end(), [&result, token](std::string item)
	{
		result += item;
		result += token;
	});

	result.erase(result.end() - token.size(), result.end());

	std::cout << result << std::endl;
}

int main()
{
	std::array<std::string, 4> arr{ "this", "is", "an", "example" };
	MixString(arr, std::string("__TOKEN__"));
	_getch();
    return 0;
}

