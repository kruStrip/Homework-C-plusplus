#pragma once
#include <vector>
#include <iostream>
#include <string>

class Packege {
public:
    ~Packege() = default;
private:
    std::string name;
    double weight_kg;

    Packege(std::string const& name = "���������", double const& weight = 10)
        : name(name), weight_kg(weight) {}

    Packege(Packege const& other)
        : name(other.name), weight_kg(other.weight_kg) {}

    void info() const {
        std::cout << name << ", ���: " << weight_kg << "��\n";
    }
    friend class Truck;
};

class Car {
protected:
    std::string mark;
    std::string model;
    std::string year_of_issue;
    std::string color;
    double mileage; // ������
    int price;

public:
    Car()
        : mark("Mercedes"), model("Benz-G class"), year_of_issue("2025"),
        color("pink"), mileage(0), price(50000000) {}

    Car(Car const& other)
        : mark(other.mark), model(other.model), year_of_issue(other.year_of_issue),
        color(other.color), mileage(other.mileage), price(other.price) {}

    Car& operator=(Car const& other) {
        if (this == &other) return *this;
        mark = other.mark;
        model = other.model;
        year_of_issue = other.year_of_issue;
        color = other.color;
        mileage = other.mileage;
        price = other.price;
        return *this;
    }

    virtual ~Car() = default;

    virtual void info() const {
        std::cout << "�����: " << mark << std::endl;
        std::cout << "������: " << model << std::endl;
        std::cout << "��� �������: " << year_of_issue << std::endl;
        std::cout << "����: " << color << std::endl;
        std::cout << "������: " << mileage << std::endl;
        std::cout << "����: " << price << std::endl;
    }

    virtual void change_color(std::string const& color) {
        this->color = color;
        std::cout << "���� �������!\n";
    }

    virtual void change_mileage(double mileage) {
        this->mileage = mileage;
        std::cout << "������ �������!\n";
    }
};

class Truck final : virtual public Car {
    std::string type;
    double maxPayload;
    std::vector<Packege*> packeges;

public:
    Truck(
        std::string const& type = "�������� ����������",
        double maxPayload = 1000,
        std::vector<Packege*> const& packeges = {}
    )
        : Car(), type(type), maxPayload(maxPayload), packeges(packeges) {}

    Truck(Truck const& other)
        : Car(other), type(other.type), maxPayload(other.maxPayload) {
        for (auto p : other.packeges) {
            packeges.push_back(new Packege(*p));
        }
    }

    Truck& operator=(Truck const& other) {
        Car::operator=(other);
        type = other.type;
        maxPayload = other.maxPayload;

        packeges.clear();

        for (auto p : other.packeges) {
            packeges.push_back(new Packege(*p));
        }

        return *this;
    }

    ~Truck() {
        packeges.clear();
    }

    void addPackege(Packege* p) {
        packeges.push_back(p);
    }

    void printPackeges() const {
        std::cout << "��������:\n";
        for (auto p : packeges) {
            p->info();
        }
    }

    void info() {
        std::cout << "�����: " << mark << std::endl;
        std::cout << "������: " << model << std::endl;
        std::cout << "���: " << type << std::endl;
        std::cout << "�������� ��������: " << maxPayload << "��" << std::endl;
        std::cout << "����: " << price << std::endl;
    }

    void isReady() const {
        double total_weight = 0;
        for (auto obj : packeges) {
            total_weight += obj->weight_kg;
        }

        if (total_weight <= maxPayload) {
            std::cout << "�������\n";
        }
        else {
            std::cout << "����� ������\n";
        }
    }
};