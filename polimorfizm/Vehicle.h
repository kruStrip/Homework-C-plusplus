#pragma once
#include <string>
#include <iostream>

class Vehicle
{
public:
	virtual ~Vehicle() = default;
	virtual void move() = 0;
};

class LandVehicle : public Vehicle {
public:
    int currentVelocity; //������� ��������
    int distance;
    int distance_passed;

    LandVehicle(
        int currentVelocity = 0,
        int distance = 0,
        int distance_passed = 0
    ) :
        currentVelocity(currentVelocity),
        distance(distance),
        distance_passed(distance_passed)
    {}

    void move() override {
        std::cout << distance_passed + distance << std::endl;
    }
    void get_distance() const {
        std::cout << "����������: " << distance << std::endl;
    }
    void print(){ printInf(this) }

    struct VTable {
        void(*print)(LandVehicle);

        VTable(void(*method)(LandVehicle*) = printInf) : print(method){}
    };
};

class Car : public LandVehicle{
protected:
    std::string mark;
public:
    Car()
        : LandVehicle(), mark("Mercedes") {}

    Car(Car const& other)
        : LandVehicle(), mark(other.mark) {}

    Car& operator=(Car const& other) {
        if (this == &other) return *this;
        LandVehicle::operator=(other);
        mark = other.mark;
        return *this;
    }

    ~Car() = default;

    void print() {
        std::cout << "��������� - ������, �����: " << mark << std::endl;
    }

    /*
    void move() override {
        std::cout << distance_passed + distance << std::endl;
    }
    void distance() const {
        std::cout << "����������: " << distance << std::endl;
    }*/
};

class Truck : public Car {
    std::string type;
public:
    Truck(
        std::string const& type = "�������� ����������"
    ): Car(), type(type) {}

    Truck(Truck const& other)
        : Car(other), type(other.type) {
    }
    Truck& operator=(Truck const& other) {
        Car::operator=(other);
        type = other.type;
        return *this;
    }

    ~Truck() = default;

    void move() override {
        std::cout << distance_passed + distance << std::endl;
    }
    void get_distance() const {
        std::cout << "����������: " << distance << std::endl;
    }

    void print() {
        std::cout << "��������� - ������, ���: " << type << std::endl;
    }
};

class Motorcycle : public LandVehicle {
    std::string name;
public:
    Motorcycle(std::string const& name = "BMX") : LandVehicle(), name(name) {}
    Motorcycle(Motorcycle const& other): LandVehicle(), name(other.name){}
    ~Motorcycle() = default;

    void print() {
        std::cout << "��������� - ���������, �����: " << name << std::endl;
    }
};