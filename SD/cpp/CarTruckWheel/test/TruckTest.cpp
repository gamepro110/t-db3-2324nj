#include "Truck.h"

#include <string>
#include <gtest/gtest.h>

class TruckTest : public testing::Test {
protected:
    TruckTest(){}
    virtual ~TruckTest(){}

    void SetUp() override {
        t = new Truck("ford f550", "Alloy", 35, 4, 9001);
    }

    void TearDown() override {
        if (t) {
            delete t;
            t = nullptr;
        }
    }

    friend Truck;

    void compareTrucks(Truck* a, Truck* b);

    Truck* t{ nullptr };
};

void TruckTest::compareTrucks(Truck* a, Truck* b) {
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

    ASSERT_EQ(
        a->GetPower(),
        b->GetPower()
    );
}

TEST_F(TruckTest, ctor) {
    Truck* a{ nullptr };

    ASSERT_NO_THROW(
        a = new Truck("ford f550", "Alloy", 35, 4, 9001);
    );

    delete a;
}

TEST_F(TruckTest, dtor) {
    ASSERT_NO_THROW(
        delete t;
        t = nullptr;
    );
}

TEST_F(TruckTest, copy_ctor) {
    Truck a{ *t };

    compareTrucks(t, &a);
}

TEST_F(TruckTest, copy_ctor_shallowCopyTest) {
    Truck a{ *t };
    int numWheels = t->GetNrWheels();

    for (int i = 0; i < numWheels; i++) {
        const Wheel* wt = t->GetWheel(i);
        const Wheel* wa = a.GetWheel(i);

        ASSERT_NE(wt, wa);
    }

    ASSERT_NE(*t, a);
}

TEST_F(TruckTest, getPower) {
    ASSERT_EQ(9001, t->GetPower());
}
