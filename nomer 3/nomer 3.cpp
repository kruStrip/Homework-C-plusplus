#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "");
	double num;
	double i;
	std::cout << "Введите число: ";
	std::cin >> num;
	std::cout << "Округление в меньшую: " << floor(num)<< std::endl;
	std::cout << "Округление в большую: " << ceil(num) << std::endl;
	std::cout << "Округление от 0.5 в большую: " << round(num) << std::endl;
	double n = modf(num,&i);
	std::cout << "Дробная часть: " << n << std::endl;
}

