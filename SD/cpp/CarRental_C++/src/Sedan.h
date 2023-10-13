#ifndef SEDAN_H_
#define SEDAN_H_

#include "Car.h"

#include <string>

class Sedan : public Car
{
public:
    Sedan(const std::string& manufacturer, const std::string& model, int buildYear, const std::string& licencePlate, bool hasTowbar);
    
    bool GetHasTowbar() const;
    bool NeedsCleaning() const override;
    void Clean() override;

private:
    const double pricePerKm = 0.29;
    bool hasTowbar{ true };
    double lastCleanedAtKm{ 0 };
};

#endif
