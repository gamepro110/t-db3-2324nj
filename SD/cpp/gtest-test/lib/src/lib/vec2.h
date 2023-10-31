#pragma once

class vec2 {
public:
    vec2(float x = 0, float y = 0);
    ~vec2();

public:
    vec2 operator*(float scaler);
    vec2 operator*(const vec2 scaler);
    vec2& operator*=(float scaler);
    vec2& operator*=(const vec2 scaler);
    float X() const;
    float Y() const;

private:
    float x, y;
};
