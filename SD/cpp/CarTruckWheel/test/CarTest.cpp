#include "Car.h"

#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

class CarTest : public testing::Test {
protected:
    CarTest() {
        c = new Car("Aston Martin Vanquish", "Alloy", 20, 4);
    }

    virtual ~CarTest() {
        delete c;
        c = NULL;
    }

    void CheckWheels(int n);// example of a method within the cartest class
    void TestWheels(Car* car, int idx, const std::string& expectedMaterial, int expectedDiameter);
    void CompareCars(Car* a, Car* b) const;

    Car* c;
};

void CarTest::CheckWheels(int n) {
    // just an example which need to be completed
    for (int i = 0; i < n; i++) {
        const Wheel* w = c->GetWheel(i);
        ASSERT_TRUE(w != nullptr);
        ASSERT_EQ(w->GetDiameter(), 20);
        ASSERT_EQ(w->GetMaterial(), std::string{"Alloy"});
    }
}

void CarTest::TestWheels(Car* car, int idx, const std::string& expectedMaterial, int expectedDiameter) {
    if (car == nullptr) {
        FAIL();
    }

    size_t numWheels = car->GetNrWheels();

    for (size_t i = 0; i < numWheels; i++) {
        const Wheel* w = car->GetWheel(i);
        ASSERT_TRUE(w != nullptr);
        ASSERT_EQ(
            expectedDiameter,
            w->GetDiameter()
        );
        ASSERT_EQ(
            expectedMaterial,
            w->GetMaterial()
        );
    }
}

void CarTest::CompareCars(Car* a, Car* b) const {
    ASSERT_EQ(
        a->GetModel(),
        b->GetModel()
    );

    ASSERT_EQ(
        a->GetLicencePlate(),
        b->GetLicencePlate()
    );

    int numWheels = a->GetNrWheels();
    for (int i = 0; i < numWheels; i++)
    {
        const Wheel* wa = a->GetWheel(i);
        const Wheel* wb = b->GetWheel(i);

        ASSERT_TRUE(wa && wb); // pointers are memory addresses, if they are NULL or nullptr it would result in 0 and fail this check
        ASSERT_EQ(
            wa->GetDiameter(),
            wb->GetDiameter()
        );
        ASSERT_EQ(
            wa->GetMaterial(),
            wb->GetMaterial()
        );
    }
}

TEST_F(CarTest, ctor) {
    ASSERT_NO_THROW(
        Car* car = new Car("Aston Martin Vanquish", "Alloy", 20, 4);
        delete car;
    );
}

TEST_F(CarTest, dtor) {
    Car* car = new Car("Aston Martin Vanquish", "Alloy", 20, 4);

    ASSERT_NO_THROW(
        delete car;
    );
}

TEST_F(CarTest, copy_ctor) {
    Car a{ "Aston Martin Vanquish", "Alloy", 20, 4 };

    ASSERT_STREQ(
        a.GetModel().c_str(),
        "Aston Martin Vanquish"
    );

    Car b{ a };

    CompareCars(&a, &b);
}

TEST_F(CarTest, copy_ctor_shallowCopyCheck) {
    Car* d{ c };

    for (int i = 0; i < c->GetNrWheels(); i++)
    {
        const Wheel* wc = c->GetWheel(i);
        const Wheel* wd = d->GetWheel(i);

        ASSERT_NE(
            &wc,
            &wd
        );
    }
}

TEST_F(CarTest, copy_assignment) {
    Car a{ "Aston Martin Vanquish", "Alloy", 20, 4 };

    ASSERT_STREQ(
        a.GetModel().c_str(),
        "Aston Martin Vanquish"
    );

    Car b = a;

    CompareCars(&a, &b);
}

TEST_F(CarTest, copy_assignment_shallowCopyCheck) {
    Car* d = new Car{ "opel astra", "rubber", 18, 4 };
    (*c) = (*d);

    int numWheels = c->GetNrWheels();
    for (int i = 0; i < numWheels; i++)
    {
        const Wheel* wc = c->GetWheel(i);
        const Wheel* wd = d->GetWheel(i);

        ASSERT_NE(
            &wc,
            &wd
        );
    }

    delete d;
}

TEST_F(CarTest, test_ifAllWheelsAreThere)
{
    Car* car = new Car("Aston Martin Vanquish", "Alloy", 20, 4);
    const Wheel* w = car->GetWheel(2);
    ASSERT_TRUE(w != NULL);
    CheckWheels(4);

    delete car;
}

TEST_F(CarTest, getModel) {
    ASSERT_EQ(
        c->GetModel(),
        std::string{ "Aston Martin Vanquish" }
    );
}


TEST_F(CarTest, get_setLicencePlate) {
    ASSERT_EQ(
        c->GetLicencePlate(),
        std::string{ "" }
    );

    const std::string licence{ "abc-def-ghi" };
    c->SetLicencePlate(licence);

    ASSERT_EQ(
        c->GetLicencePlate(),
        licence
    );
}

TEST_F(CarTest, getNrWheels) {
    ASSERT_EQ(
        4,
        c->GetNrWheels()
    );
}

class CarTestParam : public testing::TestWithParam<int> {
protected:
    CarTestParam() {
        car = new Car{ "", "Alloy", 30, 4 };
    }
    ~CarTestParam() {
        delete car;
        car = nullptr;
    }

    Car* car;
};

TEST_F(CarTest, removeWheel) {
    int numWheels = c->GetNrWheels();

    /*
    const auto printWheels = [&](int size){
        for (int i = 0; i < size; i++) {
            const Wheel* w = c->GetWheel(i);
            std::cout << "w: " << ((w) ? (void*)w : "nullptr") << "\n";
        }
        std::cout << "\n";
    };
    //*/

    ASSERT_TRUE(numWheels == 4);
    //printWheels(numWheels);
    ASSERT_NO_THROW(
        c->RemoveWheel(2);
    );
    int newNumWheels = c->GetNrWheels();
    ASSERT_NE(numWheels, newNumWheels);
    ASSERT_TRUE(newNumWheels == 3);
    //printWheels(newNumWheels);
}

TEST_F(CarTest, removeWheelInvalidIdx) {
    int numWheels = c->GetNrWheels();

    ASSERT_THROW(
        c->RemoveWheel(numWheels + 1),
        std::invalid_argument
    );
}

TEST_F(CarTest, addWheel) {
    int numWheels = c->GetNrWheels();

    const Wheel* w = c->GetWheel(0);

    ASSERT_NO_THROW(
        c->AddWheel(w->GetDiameter(), w->GetMaterial());
    );

    int newNumWheels = c->GetNrWheels();
    ASSERT_NE(numWheels, newNumWheels);
}

//src: <https://www.sandordargo.com/blog/2019/04/24/parameterized-testing-with-gtest>
TEST_P(CarTestParam, getNrWheels) {
    int num = GetParam();
    int numWheels = car->GetNrWheels();

    ASSERT_TRUE((numWheels != num));
}

TEST_P(CarTestParam, getWheel) {
    int idx = GetParam();
    const Wheel* w{ 0 };

    ASSERT_FALSE(w);
    ASSERT_NO_THROW(
        w = car->GetWheel(idx);
    );

    int numWheels = car->GetNrWheels();
    if (idx < numWheels) {
        ASSERT_TRUE(w);
        ASSERT_EQ(
            std::string{ "Alloy" },
            w->GetMaterial()
        );
        ASSERT_EQ(
            30,
            w->GetDiameter()
        );
    }
    else {
        ASSERT_FALSE(w);
    }
}

INSTANTIATE_TEST_CASE_P(
    CarTest,
    CarTestParam,
    testing::Values(
        // not testing 4 because the ctor says to add 4 wheels to the car
        0,1,2,3,5,6,7,8,9,10
    )
);
