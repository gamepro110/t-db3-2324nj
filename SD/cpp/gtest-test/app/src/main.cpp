#include "lib/vec2.h"

#include <iostream>

void printV(const vec2& v);

int main() {
    vec2 v{ 2, 2 };
    printV(v);
    v *= 2;
    printV(v);
    return 0;
}

void printV(const vec2& v) {
    std::cout << "v<" << v.X() << "," << v.Y() << ">\n";
}
