#ifndef TRUCK_H_
#define TRUCK_H_

#include "Car.h"

class Truck : public Car {
private:
    int* power;

public:
	Truck(const std::string& model, const std::string& material, int diameter, int nrWheels, int power);
	virtual ~Truck();
    Truck(const Truck& other);
    Truck& operator=(const Truck& other);
    bool operator!=(const Truck& other) const;

	int GetPower() const;
};

class TruckTest;
#endif
