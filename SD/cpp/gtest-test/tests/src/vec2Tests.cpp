#include "lib/vec2.h"

#include <gtest/gtest.h>

class vec2Test : public testing::Test {
public:
    void SetUp() override {
        v = {};
    }
    void TearDown() override {
    }

protected:
    vec2 v;
};

TEST_F(vec2Test, CtorNoArg) {
    EXPECT_EQ(v.X(), 0);
    EXPECT_EQ(v.Y(), 0);
}

TEST_F(vec2Test, CtorSingleArg) {
    float val{ 3.1415 };

    v = { val };

    EXPECT_EQ(v.X(), val);
    EXPECT_EQ(v.Y(), 0);
}

TEST_F(vec2Test, CtorDoubleArg) {
    float val1{ 3.1415 };
    float val2{ 3.1415*2 };

    v = { val1, val2 };

    EXPECT_EQ(v.X(), val1);
    EXPECT_EQ(v.Y(), val2);
}

TEST_F(vec2Test, ScalerMultiply) {
    v = { 1, 2 };

    EXPECT_EQ(v.X(), 1);
    EXPECT_EQ(v.Y(), 2);

    v = v * 2;

    EXPECT_EQ(v.X(), 2);
    EXPECT_EQ(v.Y(), 4);
}

TEST_F(vec2Test, ScalerVec2Multiply) {
    v = { 1, 2 };
    vec2 multiplier{ 2, 2 };

    EXPECT_EQ(v.X(), 1);
    EXPECT_EQ(v.Y(), 2);

    v = v * multiplier;

    EXPECT_EQ(v.X(), 2);
    EXPECT_EQ(v.Y(), 4);
}

TEST_F(vec2Test, ScalerMultiplyAssignment) {
    v = { 1, 2 };

    EXPECT_EQ(v.X(), 1);
    EXPECT_EQ(v.Y(), 2);

    v *= 2;

    EXPECT_EQ(v.X(), 2);
    EXPECT_EQ(v.Y(), 4);
}

TEST_F(vec2Test, ScalerVec2MultiplyAssignment) {
    v = { 1, 2 };
    vec2 multiplier{ 2, 2 };

    EXPECT_EQ(v.X(), 1);
    EXPECT_EQ(v.Y(), 2);

    v *= multiplier;

    EXPECT_EQ(v.X(), 2);
    EXPECT_EQ(v.Y(), 4);
}
