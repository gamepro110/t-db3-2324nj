#include "RentalAdministration.h"

#include <stdexcept>

RentalAdministration::RentalAdministration()
{
}

RentalAdministration::~RentalAdministration()
{
    for (int i = cars.size() - 1; i >= 0; i--)
    {
        delete cars.at(i);
    }
}

void RentalAdministration::Add(Car *car)
{
    if (car == nullptr){
        throw std::invalid_argument("car was nullptr");
    }
    
    cars.emplace_back(car);
}

const std::vector<Car*> &RentalAdministration::GetCars() const
{
    return cars;
}

bool RentalAdministration::RentCar(const std::string &licencePlate)
{
    Car* car = FindCarWithException(licencePlate);

    return car->Rent();
}

double RentalAdministration::ReturnCar(const std::string &licencePlate, int kilometers)
{
    Car* car = FindCarWithException(licencePlate);

    if (car->IsAvailable())
    {
        throw std::logic_error("car was not rented");
    }

    //TODO always invalid return
    return car->Return(kilometers);
}

void RentalAdministration::CleanCar(const std::string &licencePlate)
{
    FindCarWithException(licencePlate)->Clean();
}

Car* RentalAdministration::FindCar(const std::string &licencePlate)
{
    // non const coz return type is not
    Car* car = nullptr;
    for (size_t i = 0; i < cars.size(); i++)
    {
        car = cars.at(i);
        if (car && car->getLicencePlate() == licencePlate)
        {
            return car;
        }
    }

    return nullptr;
}

Car* RentalAdministration::FindCarWithException(const std::string &licencePlate)
{
    Car* car = FindCar(licencePlate);

    if (!car)
    {
        throw std::invalid_argument("no car found with this licenceplate");
    }

    return car;
}
