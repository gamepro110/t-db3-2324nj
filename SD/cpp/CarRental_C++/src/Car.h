#ifndef CAR_H_
#define CAR_H_

#include <string>

class Car {
public:
    Car(const std::string& manufacturer, const std::string& model, int buildYear, const std::string& licencePlate, double pricePerKm);
    virtual ~Car();

    bool Rent();
    virtual double Return(int kilometers);
    virtual void Clean();

    double getPricePerKm() const;
    const std::string& getManufacturer() const;
    const std::string& getModel() const;
    int getBuildYear() const;
    const std::string& getLicencePlate() const;
    int getKilometers() const;
    bool IsAvailable() const;
    virtual bool NeedsCleaning() const  {
        return needsCleaning;
    };
    virtual std::string ToString() const;

protected:
    bool needsCleaning{ false };

private:
    std::string manufacturer{ "" };
    std::string model{ "" };
    std::string licencePlate{ "" };
    int buildYear{ 1890 };
    int kilometers{ 0 };
    bool isAvailable{ true };
    double pricePerKm{ 0.0 };
};

#endif
