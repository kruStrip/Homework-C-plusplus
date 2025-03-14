#include "Vehicle.h"
#include <random>
#include <vector>

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(100, 10000);


int main() {
	setlocale(0, "");
	LandVehicle* winner = new LandVehicle;
	int max = 0;
	
	std::vector<LandVehicle*> list = { new Car, new Truck, new Motorcycle };
	for (LandVehicle* l : list) {
		l->print();

		l->distance = distribution(generator);
		l->distance_passed = distribution(generator);
		l->currentVelocity = distribution(generator);
		l->move();
		l->get_distance();

		if (max < l->distance_passed) {
			winner = l;
			max = l->distance_passed;
		}
	}
	std::cout << "\nПобедитель: " << winner->get_name();

	return 0;
}
