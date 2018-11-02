// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <cctype>

char HexTable[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void PrintHex(int n, bool islower = false)
{
	int n1 = n / 16, n2 = n % 16; // n1n2
	char c1 = islower ? tolower(HexTable[n1]) : HexTable[n1];
	char c2 = islower ? tolower(HexTable[n2]) : HexTable[n2];

	std::cout << c1 << c2;
}

int main()
{
	std::string input_arr[4];
	std::cin >> input_arr[0] >> input_arr[1] >> input_arr[2] >> input_arr[3];
	for (auto i : input_arr)
	{
		PrintHex(std::stoul(i, nullptr, 16), true);
	}
	_getch();
    return 0;
}

