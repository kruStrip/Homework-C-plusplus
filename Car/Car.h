#pragma once
class Car
{
	std::string mark;
	std::string model;
	std::string year_of_issue;
	std::string color;
	double mileage; //Пробег
	int price;

public:
	Car() {
		mark = "Mercedes";
		model = "Benz-G class";
		year_of_issue = "2025";
		color = "pink";
		mileage = 0;
		price = 50000000;
	}
	Car(Car const& other) {
		mark = other.mark;
		model = other.model;
		year_of_issue = other.year_of_issue;
		color = other.color;
		mileage = other.mileage;
		price = other.price;
	}
	Car& operator=(Car const& other) {
		mark = other.mark;
		model = other.model;
		year_of_issue = other.year_of_issue;
		color = other.color;
		mileage = other.mileage;
		price = other.price;
		return *this;
	}
	~Car() = default;

	void info() const {
		std::cout << "Марка: " << mark << std::endl;
		std::cout << "Модель: " << model << std::endl;
		std::cout << "Год выпуска: " << year_of_issue << std::endl;
		std::cout << "Цвет: " << color << std::endl;
		std::cout << "Пробег: " << mileage << std::endl;
		std::cout << "Цена: " << price << std::endl;
	}
	void change_color(std::string color) {
		this->color = color;
		std::cout << "Цвет изменен!";
	}
	void change_mileage(double mileage) {
		this->mileage = mileage;
		std::cout << "Пробег изменен!";
	}
};

