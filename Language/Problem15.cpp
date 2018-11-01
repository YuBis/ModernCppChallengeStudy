// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
#include <cassert>

class IPv4
{
public:
	static IPv4* create(std::array<int, 4> oct_arr);

	void PrintThis();
private:
	explicit IPv4();
	virtual ~IPv4();
	
	std::array<int, 4> octet_arr_;
};

std::vector<IPv4*> item_vec_;
std::array<int, 4> CheckValidate(std::string addr);
void InsertAddress(const std::string& addr);
void PrintAllAddress();
static const std::array<int, 4> ERROR_VALUE{ -1, -1, -1, -1 };


IPv4* IPv4::create(std::array<int, 4> oct_arr) {
	auto instance = new(std::nothrow) IPv4();

	assert(instance != nullptr, "IPv4 memory alloc failed.");

	instance->octet_arr_ = oct_arr;
	
	return instance;
}

IPv4::IPv4()
{
	std::fill(octet_arr_.begin(), octet_arr_.end(), -1);
}

IPv4::~IPv4()
{

}
void IPv4::PrintThis()
{
	int point_left = 3;

	std::for_each(octet_arr_.cbegin(), octet_arr_.cend(), [&point_left](int item) { std::cout << item << (point_left-- > 0 ? "." : ""); });
	std::cout << std::endl;
}

void InsertAddress(const std::string& addr)
{
	auto validate_var = CheckValidate(addr);
	if (validate_var != ERROR_VALUE)
	{
		auto maked_addr = IPv4::create(validate_var);
		item_vec_.push_back(maked_addr);
	}
	else
		std::cout << "it is not ipv4 address form" << std::endl;
}

void PrintAllAddress()
{
	std::for_each(item_vec_.cbegin(), item_vec_.cend(), [=](IPv4* item) { item->PrintThis(); });
}

std::array<int, 4> CheckValidate(std::string addr)
{
	int oct_idx = 0;
	std::array<int, 4> ret_val{ -1, -1, -1, -1 };
	char* context = nullptr;
	char* tok_addr = const_cast<char*>(addr.c_str());

	char* ptr = strtok_s(tok_addr, ".", &context);
	while (ptr != nullptr)
	{
		if (oct_idx > 3)
			return ERROR_VALUE;

		std::stringstream n(ptr);
		int convert_value;

		if (n >> convert_value)
		{
			if (convert_value >= 0 && convert_value <= 255)
				ret_val[oct_idx++] = convert_value;
		}
		else
			return ERROR_VALUE;

		ptr = strtok_s(nullptr, ".", &context);
	}

	if (oct_idx != 4)
		return ERROR_VALUE;

	return ret_val;
}


int main()
{
	std::string input;
	int menu_input;

	while (true)
	{
		std::cout << "1. Input 2. PrintAll 0. exit" << std::endl;
		std::cin >> menu_input;

		if (menu_input == 1)
		{
			std::cout << "insert IPv4 class" << std::endl;
			std::cin >> input;
			InsertAddress(input);
		}
		else if (menu_input == 2)
		{
			PrintAllAddress();
		}
		else
			break;
	}
    return 0;
}

