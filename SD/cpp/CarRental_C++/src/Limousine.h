#ifndef LIMOUSINE_H_
#define LIMOUSINE_H_

#include "Car.h"

#include <string>

class Limousine : public Car
{
public:
    Limousine(const std::string& manufacturer, const std::string& model, int buildYear, const std::string& licencePlate, bool hasMinibar);
    ~Limousine() override
    {}

    bool NeedsCleaning() const override;
    void Clean() override;
    double Return(int kilometer) override;

private:
    const double pricePerKm;
    bool hasMinibar;
};

#endif
