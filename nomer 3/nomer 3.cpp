#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	double num;
	std::cout << "Введите число: ";
	std::cin >> num;
	std::cout << "Округление в меньшую: " << int(num)<< std::endl;
	std::cout << "Округление в большую: " << (int(num)+1) << std::endl;
	if ((num - int(num)) >= 0.5) {
		std::cout << "Округление от 0.5 в большую: " << int(num)+1 << std::endl;
	}
	else {
		std::cout << "Округление от 0.5 в большую: " << int(num) << std::endl;
	}
	std::cout << "Дробная часть: " << num - int(num) << std::endl;
} 