// Project.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <fstream>
#include <algorithm>

enum FILE_MODE
{
	WRITE_MODE,
	READ_MODE
};

class FileController
{
public:
	explicit FileController(FILE_MODE mode, std::string file_name, std::ios_base::openmode open_mode = -1);

private:
	virtual ~FileController();

	std::ofstream out_file;
	std::ifstream in_file;

	FileController& operator=(const FileController& rhs)
	{
		out_file = rhs.out_file;
		in_file = rhs.in_file;

	}
};

FileController::FileController(FILE_MODE mode, std::string file_name, std::ios_base::openmode open_mode)
{
	std::ios_base::openmode setted_open_mode = open_mode;

	if (mode == FILE_MODE::WRITE_MODE)
	{
		if (setted_open_mode == -1)
			setted_open_mode = std::ios_base::out;

		out_file.open(file_name, setted_open_mode);
	}
	else
	{
		if (setted_open_mode == -1)
			setted_open_mode = std::ios_base::in;

		in_file.open(file_name, setted_open_mode);
	}
}

FileController::~FileController()
{
	if (out_file.is_open())
		out_file.close();

	if (in_file.is_open())
		in_file.close();
}

int main()
{
	_getch();
    return 0;
}

