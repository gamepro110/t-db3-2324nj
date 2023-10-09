#ifndef RentalAdministration_H_
#define RentalAdministration_H_

#include "Car.h"

#include <vector>

class RentalAdministration final
{
public:
    RentalAdministration();
    ~RentalAdministration();

    void Add(Car* car);
    const std::vector<Car*>& GetCars() const;
    bool RentCar(const std::string& licencePlate);
    double ReturnCar(const std::string& licencePlate, int kilometers);
    void CleanCar(const std::string& licencePlate);
    Car* FindCar(const std::string& licencePlate);
    Car* FindCarWithException(const std::string& licencePlate);

private:
    std::vector<Car*> cars;
};

#endif
