#include "lib/vec2.h"

vec2::vec2(float x, float y) :
    x(x),
    y(y)
{}

vec2::~vec2() {
}

vec2 vec2::operator*(float scaler) {
    float nX, nY;
    nX = x * scaler;
    nY = y * scaler;
    return { nX, nY };
}

vec2 &vec2::operator*=(float scaler) {
    x *= scaler;
    y *= scaler;

    return (*this);
}

float vec2::X() const {
    return x;
}

float vec2::Y() const {
    return y;
}
