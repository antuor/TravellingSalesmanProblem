#include "InputProcessing.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

void InputProcessing::LoadMatrixFromFile(const std::string& filePath)
{
	int matrixDimetion = 0;
	std::ifstream matrixFile(filePath);
	matrixDimetion = GetSizeOfLine(matrixFile);
	
	std::istream_iterator<int> start(matrixFile), end;
	std::vector<int> numbers(start, end);
	matrixFile.close();
	
	Containers::Matrix<int> inputMatrix(matrixDimetion, matrixDimetion, numbers);
	_inputMatrix = inputMatrix;
}

int InputProcessing::GetSizeOfLine(std::ifstream& matrixFile)
{
	int x = 0, counter = 0;
	std::string dummy;
	
	std::getline(matrixFile, dummy);
	std::istringstream str(dummy);
	while (str >> x)
		counter++;
	
	matrixFile.clear();
	matrixFile.seekg(0);
	
	return counter;
}

void InputProcessing::PrintProgramInfo()
{
	std::cout << "��������� ��� ������� ������ ������������.\n" << std::endl;
	std::cout << "������ �������� -f ����� ��� ����� � �������� ����������." << std::endl;
	std::cout << "������ �������� -m ������ ����� �������." << std::endl;
	std::cout << "��������� -m:\nnp_complete - ������� ������ ������ ���������." << std::endl;
	std::cout << "np_partial - ������� ������ ���������� ������.\n" << std::endl;
	std::cout << "�������� -h ���������� ���������� � ���������." << std::endl;
	std::cout << "�������� exit ������������ ��� ������ �� ���������." << std::endl;
}

void InputProcessing::ProcessInput()
{
	setlocale(LC_ALL, "Russian");

	std::string input, temp;
	std::list<std::string> parameters;
	
	PrintProgramInfo();

	while(true)
	{
		std::getline(std::cin, input);
		
		std::istringstream inputStream(input);
		
		while (inputStream >> temp)
			parameters.push_back(temp);

		if (parameters.back() == "exit")
			break;

		if (parameters.back() == "-h")
		{
			PrintProgramInfo();
			continue;
		}

		LoadMatrixFromFile(parameters.front());


	}
}

void InputProcessing::Deinit()
{

}
