#include <iostream>
#include "Car.h"

int main()
{
	setlocale(0, "");
	Car car;
	int var = 0;
	double ml;
	std::string cl;
	while (true) {
		std::cout <<
			R"(Выберите вариант : 
1 - Посмотреть информацию об автомобиле,
2 - Поменять цвет,
3 - Поменять пробег

Вариант: )";
		std::cin >> var;
		switch (var) {
		case 1:
			car.info();
			break;
		case 2:
			std::cout << "Введите цвет: ";
			std::cin >> cl;
			car.change_color(cl);
			break;
		case 3:
			std::cout << "Введите пробег: ";
			std::cin >> ml;
			car.change_mileage(ml);
			break;
		default:
			std::cout << "Неверный ввод";
			break;
		}
		std::cout << "\n";
	}
	return 0;
}
