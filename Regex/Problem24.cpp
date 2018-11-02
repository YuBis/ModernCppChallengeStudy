// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

char HexTable[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void PrintHex(std::string n)
{
	for (int i = 0; i < n.size(); i += 2)
	{
		std::string item{ n[i],n[i + 1] };
		std::transform(item.begin(), item.end(), item.begin(), [](char c) { return std::toupper(c); });

		if ('A' <= item[0] && item[0] <= 'F' ||
			'A' <= item[1] && item[1] <= 'F')
		{
			item = "0x" + item;
		}
		else if (item[0] == '0')
		{
			item[0] = item[1];
			item[1] = '\0';
		}

		std::cout << item << std::endl;
	}
}

int main()
{
	std::string input_arr;
	std::cin >> input_arr;
	PrintHex(input_arr);
	_getch();
    return 0;
}

