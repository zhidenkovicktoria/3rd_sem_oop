#include <gtest/gtest.h>
#include "binary_representation.h"

TEST(BinaryRepresentationTest, Zero) {
    EXPECT_EQ(intToBinaryString(0), "00000000000000000000000000000000");
}

TEST(BinaryRepresentationTest, One) {
    EXPECT_EQ(intToBinaryString(1), "00000000000000000000000000000001");
}

TEST(BinaryRepresentationTest, MaxInt) {
    EXPECT_EQ(intToBinaryString(2147483647), "01111111111111111111111111111111");
}

TEST(BinaryRepresentationTest, PositiveNumber1) {
    EXPECT_EQ(intToBinaryString(123456), "00000000000000011110001001000000");
}

TEST(BinaryRepresentationTest, PositiveNumber2) {
    EXPECT_EQ(intToBinaryString(987654), "00000000000011110001001000000110");
}

TEST(BinaryRepresentationTest, PositiveNumber3) {
    EXPECT_EQ(intToBinaryString(1024), "00000000000000000000010000000000");
}

TEST(BinaryRepresentationTest, PositiveNumber4) {
    EXPECT_EQ(intToBinaryString(512), "00000000000000000000001000000000");
}
