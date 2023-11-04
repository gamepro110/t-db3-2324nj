#include "Wheel.h"

//TODO implment all methods

Wheel::Wheel(int diameter, const std::string& material) :
    diameter(diameter),
    material(material)
{
}

const std::string& Wheel::GetMaterial() const {
    return material;
}

void Wheel::SetMaterial(const std::string& material) {
    this->material = material;
}

int Wheel::GetDiameter() const {
    return diameter;
}
