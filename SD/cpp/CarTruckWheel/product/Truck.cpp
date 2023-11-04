#include "Truck.h"
#include <iostream>

Truck::Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power) :
    Car(model, material, diameter, nrWheels), power(new int(power))
{
    if (diameter < 1) {
        throw std::invalid_argument("insufficient wheel diameter");
    }
    if (GetNrWheels() < 3) {
        throw std::invalid_argument("insufficient wheels");
    }
    if (*this->power < 1) {
        throw std::invalid_argument("insufficient power");
    }
}

Truck::~Truck() {
    delete power;
}

Truck::Truck(const Truck& other) :
    Car(
        other.GetModel(),
        other.GetWheel(0)->GetMaterial(),
        other.GetWheel(0)->GetDiameter(),
        other.GetNrWheels()
    ),
    power(new int(*other.power))
{}

Truck& Truck::operator=(const Truck& other) {
    if (this != &other) {
        Car::operator=(other);
        *power = *other.power;
    }
    return (*this);
}

/// @brief check if the power ptr is on the same address
bool Truck::operator!=(const Truck &other) const {
    return power != other.power;
}

int Truck::GetPower() const {
    return *power;
}
