#include "Car.h"
#include "Wheel.h"

#include <iostream>
#include <stdexcept>

#ifdef SHOW_CTORS
    #define TRACE(txt) std::cout << txt << std::endl
#else
    #define TRACE(txt)
#endif


Car::Car(const std::string& model, const std::string& material, int diameter, int nrWheels) :
    licencePlate(""), model(model)
{
    TRACE("car constructor called!");

    for (int i = 0; i < nrWheels; i++) {
        wheels.emplace_back(new Wheel(diameter, material));
    }
}

Car::Car(const Car& other) {
    TRACE("car copy constructor called!");

    licencePlate = other.licencePlate;
    model = other.model;

    for (const auto* item : other.wheels) {
        wheels.emplace_back(new Wheel(item->GetDiameter(), item->GetMaterial()));
    }
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        model = other.model;
        licencePlate = other.licencePlate;

        for (auto* item : wheels) {
            delete item;
            item = 0;
        }
        wheels.clear();

        for (const auto* item : other.wheels) {
            wheels.emplace_back(new Wheel{ item->GetDiameter(), item->GetMaterial() });
        }
    }
    return (*this);
}

const std::string& Car::GetModel() const {
    return model;
}

void Car::SetLicencePlate(const std::string& licence) {
    licencePlate = licence;
}

const std::string& Car::GetLicencePlate() const {
    return licencePlate;
}

int Car::GetNrWheels() const {
    return wheels.size();
}

Car::~Car() {
    TRACE("car destructor called!");

    for (auto* item : wheels) {
        delete item;
    }
}

const Wheel* Car::GetWheel(size_t index) const
{
    if (index < 0 || index > wheels.size()) {
        return NULL;
    }

    return wheels.at(index);
}

void Car::RemoveWheel(size_t index) {
    if (index < 0 || index > wheels.size()) {
        throw std::invalid_argument("invalid index");
    }

    delete wheels.at(index);
    wheels.erase(wheels.begin() + index);
}

void Car::AddWheel(int diameter, const std::string& material) {
    wheels.emplace_back(new Wheel(diameter, material));
}
