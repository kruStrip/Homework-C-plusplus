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
			R"(�������� ������� : 
1 - ���������� ���������� �� ����������,
2 - �������� ����,
3 - ���������� ��������,
4 - ������ ������� �� ����,

�������: )";
		std::cin >> var;
		switch (var) {
		case 1:
			truck.info();
			break;
		case 2: {
			std::string name;
			double weight;
			std::cout << "������� ��������: ";
			std::cin >> name;
			std::cout << "������� ���: ";
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
			std::cout << "�������� ����";
			break;
		}
		std::cout << "\n";
	}
	return 0;
}
