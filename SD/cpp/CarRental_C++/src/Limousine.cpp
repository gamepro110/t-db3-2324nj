#include "Limousine.h"

Limousine::Limousine(const std::string &manufacturer, const std::string &model, int buildYear, const std::string &licencePlate, bool hasMinibar) :
    Car(manufacturer, model, buildYear, licencePlate, 2.5), pricePerKm(2.5), hasMinibar(hasMinibar)
{
    needsCleaning = false;
}

bool Limousine::NeedsCleaning() const
{
    return needsCleaning;
}

void Limousine::Clean()
{
    needsCleaning = false;
}

double Limousine::Return(int kilometer)
{
    double price = Car::Return(kilometer);
    needsCleaning = true;
    return price;
}
