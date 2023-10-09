# CarRentalC++

## part 2.2a

1. it is to prevent it from being included more than once. the linker cant figure out what to do with either if it is included more than once

2.  

    ```c++
    class thing {
    public:
        // start public area
        void foo();
        // end public area
    private:
        // start private area
        int value{ 0 };
        // end private area
    };
    ```

3. [C# decimals](https://learn.microsoft.com/en-us/dotnet/csharp/language-reference/builtin-types/floating-point-numeric-types) have 16 bytes and 28-29 bits of floating point precision.

    C++
    >"float has 7 decimal digits of precision. double is a 64-bit IEEE 754 double precision Floating Point Number – 1 bit for the sign, 11 bits for the exponent, and 52* bits for the value. double has 15 decimal digits of precision."

    ([source](https://www.google.com/search?q=c%2B%2B+64+bit+floating+point+precision&client=firefox-b-d&sca_esv=571720465&sxsrf=AM9HkKl6nTehzXXOkdZKYivZnoJ5_0h_8Q%3A1696768758532&ei=9qIiZaCNIMGIi-gP_-SokAo&ved=0ahUKEwig4PiYvOaBAxVBxAIHHX8yCqIQ4dUDCA8&uact=5&oq=c%2B%2B+64+bit+floating+point+precision&gs_lp=Egxnd3Mtd2l6LXNlcnAiI2MrKyA2NCBiaXQgZmxvYXRpbmcgcG9pbnQgcHJlY2lzaW9uMggQIRigARjDBEjdLFC9GVjBGXABeAGQAQCYAZQBoAGFAqoBAzAuMrgBA8gBAPgBAcICChAAGEcY1gQYsAPiAwQYACBBiAYBkAYI&sclient=gws-wiz-serp))

    so by using a 128 bit double-floating-point type (aka `long double`) would mean ~30 digits of precision.

4. u solve it by making a private variable and a `getVar()` and `setVar()` functions.

5. marking a member function as virtual means u allow them to be overwritten in inherited classes.

    example:

    ```c++
    class ShapeBase
    {
    public:
        virtual int Area() const;
        // mark function as virtual
    };

    class RectShape : public ShapeBase
    {
    public:
        int Area() const override;
        // override it for specific 
    }
    ```

    (source: [virtual keyword from cppreference.com](https://en.cppreference.com/w/cpp/language/virtual))

6. you can assign a vritual function with the value of `0`. making it a `pure virtual`, meaning it still needs an implementation.

7. >Specifies that a virtual function overrides another virtual function.

    see example in answer 5 above

    (cppreference [source](https://en.cppreference.com/w/cpp/language/override))

8. it provides a 'flag' to the compiler with the promise that class variables wont change, and the compiler will complain (with compile errors) when u try to.

9.  ```c++
    class thing
    {
    public:
        const char* const GetName() const;
    //  ^____                               constant return type
    //              ^____                   constant pointer pointing to a const variable
    //                              ^____   constant function
    };
    ```

10. only methods that are meant to change class variables. like a `SetValue()` function

11. you need to add '`Car::`' before the function name.

    ```c++
    // Car.h
    class Car
    {
    public:
        int GetKilometers();
    };
    // Car.cpp
    int Car::GetKilometers()
    {
        return kilometers;
    }
    ```

12. use a pointer.

13. yes, `const std::string&` for moving strings as arguments.

14. you can do multiple things.
    - return from the function
    - throw an exception
    - crash (not desireable)

15. `std::invalid_argument("<reason>")`

## part 2.2b

16. adding "`: public Car`" after the class name (Limousine in this case)

17. in c# classes inherits from object. in c++ classes inherits from nothing. to call the inherited class' constructor you need to use the initializer list.

    ```c++
    class vec2
    {
    public:
        // ctor
        vec2(float _x = 0.0f, float _y = 0.0f) :
            x(_x), y(_y) // initializer list
        {} // ctor body

    private:
        float x, y;
    };

    class vec3 : public vec2
    {
    public:
        vec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) :
            vec2(_x, _y), z(_z)
        {}
    private:
        float z;
    }
    ```

## part 2.2c

18. they decided to call it vector. i don't know why...

19. have a `std::vector<Car*>`. minimize stack size by using pointers and using it like a c# abstract/interface class.

## part 2.2d

20. `std::cin.ingnore()` extracts characters from `standard input` and discards them until N is reached or the delimiter is found.

## part 3

21. shared libraries are external blocks of code that get attached to the program durring runtime.

22. to prevent bloat, it is less efficient to dynamically link libraries. but it prevents the same block of code to be included en compiled into every program.

23. static libraries are libraries that are included and compiled into the program, the get "absorbed" into the compiled program and become part of it. it allowes the compiler to optimize while linking but could bloat the program.

24. the main reason would be preformance.
