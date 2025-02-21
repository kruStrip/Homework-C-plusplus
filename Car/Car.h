#pragma once
class Car
{
	std::string mark;
	std::string model;
	std::string year_of_issue;
	std::string color;
	double mileage; //������
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
		std::cout << "�����: " << mark << std::endl;
		std::cout << "������: " << model << std::endl;
		std::cout << "��� �������: " << year_of_issue << std::endl;
		std::cout << "����: " << color << std::endl;
		std::cout << "������: " << mileage << std::endl;
		std::cout << "����: " << price << std::endl;
	}
	void change_color(std::string color) {
		this->color = color;
		std::cout << "���� �������!";
	}
	void change_mileage(double mileage) {
		this->mileage = mileage;
		std::cout << "������ �������!";
	}
};

