//============================================================================
// Name        : menu.cpp
// Author      : Freddy Hurkmans
// Version     :
// Copyright   : copyright Freddy Hurkmans
// Description : Assignment 1 example
//============================================================================

#include <iostream>
#include <stdexcept>
#include <string>
//using namespace std;

#include "RentalAdministration.h"
#include "Limousine.h"
#include "Sedan.h"

void addTestDataToAdministration(RentalAdministration* administration)
{
    std::string licencePlates[] = {"SD-001", "SD-002", "SD-003", "SD-004", "LM-001", "LM-002"};

    for (int i = 0; i < 4; i++)
    {
        Car* sedan = new Sedan("BMW", "535d", 2012 + i, licencePlates[i], false);
        administration->Add(sedan);
    }
    for (int i = 4; i < 6; i++)
    {
        Car* limousine = new Limousine("Rolls Roys", "Phantom Extended Wheelbase", 2015, licencePlates[i], true);
        administration->Add(limousine);
    }
}

static const Car* GetCurrentCar(const RentalAdministration* administration, size_t carNumber)
{
    if (carNumber > administration->GetCars().size())
    {
        std::cout << "\nError: car with car number " << carNumber << " does not exist!\n";
        return NULL;
    }

    return administration->GetCars().at(carNumber);
}

static void PrintCars(const RentalAdministration* administration)
{
    const std::vector<Car*>& list = administration->GetCars();
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout
            << i << ") "
            << list.at(i)->ToString()
            << std::endl;
    }
}

static size_t selectCar(const RentalAdministration* administration)
{
    size_t carNumber = 0;
    std::cout << "These cars are currently listed:\n";
    PrintCars(administration);
    std::cout << "\nPlease enter a car number: ";
    std::cin >> carNumber;
    std::cin.ignore();
    return carNumber;
}

static void rentCar(RentalAdministration* administration, size_t carNumber)
{
    // rent this car, functionality comparable to btnRent_Click
    const Car* curr = GetCurrentCar(administration, carNumber);

    if (!administration->RentCar(curr->getLicencePlate()))
    {
        std::cout << "failed to rent " << curr->getLicencePlate() << std::endl;
    }
}

static void returnCar(RentalAdministration* administration, size_t carNumber)
{
    // return this car, do handle exceptions
    const Car* curr = GetCurrentCar(administration, carNumber);

    try
    {
        //FIXME update kilometers, user input?
        double cost = administration->ReturnCar(curr->getLicencePlate(), 500 + curr->getKilometers());
        std::cout << "Car " << curr->ToString() << " returned. price: " << cost << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

static void printIfCarNeedsCleaning(const RentalAdministration* administration, size_t carNumber)
{
    const Car* curr = GetCurrentCar(administration, carNumber);
    
    if (curr->NeedsCleaning())
    {
        std::cout << curr->ToString() << " needs to be cleaned" << std::endl;
    }
    else
    {
        std::cout << curr->ToString() << " does not need cleaning" << std::endl;
    }
}

static void cleanCar(RentalAdministration* administration, size_t carNumber)
{
    // clean this car, see: btnClean_Click
    const Car* curr = GetCurrentCar(administration, carNumber);
    administration->CleanCar(curr->getLicencePlate());
}


static void showMenu( void )
{
    std::cout << "\n\nCar Rental menu\n";
    std::cout << "===============\n";
    std::cout << "(1) Show all cars\n";
    std::cout << "(2) Select car\n";
    std::cout << "(3) Rent selected car\n";
    std::cout << "(4) Return selected car\n";
    std::cout << "(5) Check if car needs cleaning\n";
    std::cout << "(6) Clean car\n";
    std::cout << "-----------------------\n";
    std::cout << "(9) QUIT\n\n";
    std::cout << "Choice : ";
}

int main( void )
{
    bool quit = false;
    size_t carNumber = 0;

    RentalAdministration administration;
    addTestDataToAdministration(&administration);

    while (!quit)
    {
        char choice = '\0';
        showMenu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case '1' :
            PrintCars(&administration);
            break;
        case '2' :
            carNumber = selectCar(&administration);
            break;
        case '3' :
            rentCar(&administration, carNumber);
            break;
        case '4' :
            returnCar(&administration, carNumber);
            break;
        case '5' :
            printIfCarNeedsCleaning(&administration, carNumber);
            break;
        case '6' :
            cleanCar(&administration, carNumber);
            break;

        case '9' :
            quit = true;
            break;
        default:
            std::cout << "\n\nI did not understand your choice (" << choice << ")" << std::endl;
            break;
        }
    }

    return 0;
}
