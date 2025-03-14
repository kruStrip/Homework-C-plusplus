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
    int currentVelocity; //текущая скорость
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
        std::cout << "Передвинулся на: " << distance_passed + distance << std::endl;
    }
    void get_distance() {
        std::cout << "Расстояние: " << distance << std::endl;
    }
    virtual void print() {}
    virtual std::string get_name() { return ""; }
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

    void print() override {
        std::cout << "Транспорт - машина, марка: " << mark << std::endl;
    }

    std::string get_name() override {
        return mark;
    }
};

class Truck : public Car {
    std::string type;
public:
    Truck(
        std::string const& type = "Грузовой автомобиль"
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

    void print() override {
        std::cout << "Транспорт - грузовик, марка: " << type << std::endl;
    }
    std::string get_name() override {
        return type;
    }
};

class Motorcycle : public LandVehicle {
    std::string name;
public:
    Motorcycle(std::string const& name = "BMX") : LandVehicle(), name(name) {}
    Motorcycle(Motorcycle const& other): LandVehicle(), name(other.name){}
    ~Motorcycle() = default;

    void print() override { 
        std::cout << "Транспорт - мотоцикл, марка: " << name << std::endl;
    }
    std::string get_name() override {
        return name;
    }
};