#include "Sedan.h"

Sedan::Sedan(const std::string& manufacturer, const std::string& model, int buildYear, const std::string& licencePlate, bool hasTowbar) :
    Car(manufacturer, model, buildYear, licencePlate, 0.29), pricePerKm(0.29), hasTowbar(hasTowbar)
{}

bool Sedan::GetHasTowbar() const
{
    return hasTowbar;
}

bool Sedan::NeedsCleaning() const
{
    return ((getKilometers() - lastCleanedAtKm) > 999);
}

void Sedan::Clean()
{
    lastCleanedAtKm = getKilometers();
}
