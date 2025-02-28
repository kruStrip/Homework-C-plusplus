#include <iostream>
#include "Car_and_Truck.h"

int main()
{
	setlocale(0, "");
	Truck truck;
	int var = 0;
	double ml;
	std::string cl;
	while (true) {
		std::cout <<
			R"(Выберите вариант : 
1 - Посмотреть информацию об автомобиле,
2 - Добавить груз,
3 - Посмотреть багажник,
4 - Узнать потянет ли груз,

Вариант: )";
		std::cin >> var;
		switch (var) {
		case 1:
			truck.info();
			break;
		case 2: {
			std::string name;
			double weight;
			std::cout << "Введите название: ";
			std::cin >> name;
			std::cout << "Введите вес: ";
			std::cin >> weight;

			Packege* p = new Packege(name, weight);
			truck.addPackege(p);
			break;
		}
		case 3:
			truck.printPackeges();
			break;
		case 4:
			truck.isReady();
			break;
		default:
			std::cout << "Неверный ввод";
			break;
		}
		std::cout << "\n";
	}
	return 0;
}
