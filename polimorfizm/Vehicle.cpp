#include "Vehicle.h"
#include <random>
#include <vector>
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(100, 10000);
int distance_ = distribution(generator);
int distance_passed_ = distribution(generator);
int currentVehiolity_ = distribution(generator);

int main() {
	setlocale(0, "");
	std::vector<LandVehicle*> list = { new Car, new Truck, new Motorcycle };
	for (LandVehicle* l : list) {
		
		l->distance = distance_;
		l->distance_passed = distance_passed_;
		l->currentVelocity = currentVehiolity_;
	}

	
}
