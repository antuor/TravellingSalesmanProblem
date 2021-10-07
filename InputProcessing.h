#pragma once
#include <string>
#include "Containers/Matrix.h"

class InputProcessing
{
private:
	InputProcessing() {}
	void LoadMatrixFromFile(const std::string& filePath);
	int GetSizeOfLine(std::ifstream& matrixFile);

	void PrintProgramInfo();

	Containers::Matrix<int> _inputMatrix;

public:
	static InputProcessing& Instance()
	{
		static InputProcessing instance;
		return instance;
	}

	// Запускаем обработку входной строки
	void ProcessInput();

	// Уничтожаем все ресурсы
	void Deinit();
};

