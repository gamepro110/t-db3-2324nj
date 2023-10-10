#include "Car.h"
#include "Limousine.h"

#include <iostream>
#include <vector>
#include <string>

template<typename T>
void printVec(std::vector<T> list)
{
    for (auto* item : list)
    {
        std::cout << item->ToString() << "\n";
    }

}

std::string GetInfo(Car* car)
{
    return std::string{ car->getManufacturer() + " - " + car->getModel() + " | " + car->getLicencePlate() };
}

int main()
{
    std::vector<Car*> cars;
    cars.emplace_back(new Limousine("limo", "big", 2000, "ab-12-cd", false));
    cars.emplace_back(new Limousine("limo", "big", 2000, "12-cd-34", true));

    printVec(cars);

    for (auto* item : cars)
    {
        std::cout << "\t" << GetInfo(item) << "\n";
        item->Rent();
        item->Return(500);
    }

    for (auto* item : cars)
    {
        delete item;
    }
    
    return 0;
}
