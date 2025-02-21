#include <iostream>
#include "Car.h"

int main()
{
	setlocale(0, "");
	Car car1;
	Car car2;
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
			car1.info();
			break;
		case 2:

			std::cout << "Введите цвет: ";
			std::cin >> cl;
			car1.change_color(cl);
			break;
		case 3:
			std::cout << "Введите пробег: ";
			std::cin >> ml;
			car1.change_mileage(ml);
			break;
		default:
			std::cout << "Неверный ввод";
			break;
		}
		std::cout << "\n";
	}
	return 0;
}
