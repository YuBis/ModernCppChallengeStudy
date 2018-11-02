// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

std::vector<char> GetTokenList(const std::string &tokstr)
{
	std::string new_tokstr(tokstr);
	std::vector<char> ret_vec;

	while (new_tokstr.size())
	{
		ret_vec.push_back(new_tokstr.back());
		new_tokstr.pop_back();
	}

	return ret_vec;
}

void SepString(std::string n, std::string token)
{
	std::string new_str(n);
	std::vector<std::string> result;

	std::vector<char> tok_list = GetTokenList(token);

	std::for_each(tok_list.begin(), tok_list.end(), [&new_str, tok_list](char c) {
		std::transform(new_str.begin(), new_str.end(), new_str.begin(), [=](char ch) {
			if (ch == c)
				return *tok_list.begin();
			else
				return ch;
		});
	});

	std::istringstream ss(new_str);
	std::string ss_tok;
	while (std::getline(ss, ss_tok, *tok_list.begin()))
	{
		if( ss_tok != "" )
			result.push_back(ss_tok);
	}

	for (auto& item : result)
		std::cout << item << std::endl;

	return;
}

int main()
{
	SepString("this,is.a sample!!", ",.! ");
	_getch();
    return 0;
}

