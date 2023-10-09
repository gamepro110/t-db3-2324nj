#include "Car.h"

#include <stdexcept>

Car::Car(const std::string& manufacturer, const std::string& model, int buildYear, const std::string& licencePlate, double pricePerKm) :
    manufacturer(manufacturer), model(model), licencePlate(licencePlate), buildYear(buildYear), isAvailable(true), pricePerKm(pricePerKm)
{
    if (buildYear < 1890)
    {
        throw std::invalid_argument("build year cannot be before 1890");
    }

    if (pricePerKm < 0)
    {
        throw std::invalid_argument("price per km cannot be smaller than 0");
    }
}

Car::~Car()
{
}

bool Car::Rent()
{
    if (!isAvailable)
    {
        return false;
    }

    isAvailable = false;
    return true;
}

double Car::Return(int kilometers)
{
    if (isAvailable)
    {
        throw std::logic_error("car was not rented, invalid action");
    }

    if (this->kilometers > kilometers)
    {
        throw std::invalid_argument("car was returned with less kilometers than it had");
    }

    double cost = pricePerKm * (kilometers - this->kilometers);
    return cost;
}

void Car::Clean()
{
    needsCleaning = false;
}

double Car::getPricePerKm() const
{
    return pricePerKm;
}

const std::string& Car::getManufacturer() const
{
    return manufacturer;
}

const std::string& Car::getModel() const
{
    return model;
}

int Car::getBuildYear() const
{
    return buildYear;
}

const std::string& Car::getLicencePlate() const
{
    return licencePlate;
}

int Car::getKilometers() const
{
    return kilometers;
}

bool Car::IsAvailable() const
{
    return isAvailable;
}

std::string Car::ToString() const
{
    return std::string{ manufacturer + " - " + model + ", " + licencePlate };
}
