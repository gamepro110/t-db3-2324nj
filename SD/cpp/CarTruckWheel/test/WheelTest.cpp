#include "Wheel.h"

#include <string>
#include <gtest/gtest.h>

class WheelTests : public testing::Test {
public:
    void SetUp() override {
    }
    void TearDown() override {
        if (w) {
            delete w;
            w = nullptr;
        }
    }

    Wheel* w{ nullptr };
    const int defaultDiameter{ 5 };
    const std::string defaultMaterial{ "rubber" };
};

TEST_F(WheelTests, ctor) {
    ASSERT_NO_THROW(w = new Wheel(defaultDiameter, defaultMaterial););
}

TEST_F(WheelTests, dtor) {
    w = new Wheel(defaultDiameter, defaultMaterial);

    ASSERT_NO_THROW(
        delete w;
        w = nullptr;
    );
}

TEST_F(WheelTests, GetDiameter) {
    w = new Wheel(defaultDiameter, defaultMaterial);
    int actual = w->GetDiameter();

    ASSERT_EQ(defaultDiameter, actual);
}

TEST_F(WheelTests, GetMaterial) {
    w = new Wheel(defaultDiameter, defaultMaterial);

    ASSERT_EQ(defaultMaterial, w->GetMaterial());
}

TEST_F(WheelTests, SetMaterial) {
    w = new Wheel(defaultDiameter, defaultMaterial);
    const std::string newMat{ "reinforced rubber" };

    ASSERT_EQ(defaultMaterial, w->GetMaterial());
    ASSERT_NO_THROW(w->SetMaterial(newMat););
    ASSERT_EQ(newMat, w->GetMaterial());
}
