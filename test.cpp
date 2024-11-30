#include <gtest/gtest.h>
#include "Twelve.h"

TEST(TwelveTest, ConstructorTests) {
    Twelve t1;
    EXPECT_EQ(t1.toString(), "");

    Twelve t2(3, 5);
    EXPECT_EQ(t2.toString(), "555");

    Twelve t3({1, 2, 3});
    EXPECT_EQ(t3.toString(), "321");

    Twelve t4("1A2B");
    EXPECT_EQ(t4.toString(), "1A2B");
}

TEST(TwelveTest, AdditionTests) {
    Twelve t1("1A");
    Twelve t2("2B");
    Twelve t3 = t1 + t2;
    EXPECT_EQ(t3.toString(), "49");

    t1 += t2;
    EXPECT_EQ(t1.toString(), "49");
}

TEST(TwelveTest, SubtractionTests) {
    Twelve t1("2B");
    Twelve t2("1A");
    Twelve t3 = t1 - t2;
    EXPECT_EQ(t3.toString(), "11");

    t1 -= t2;
    EXPECT_EQ(t1.toString(), "11");
}

TEST(TwelveTest, ComparisonTests) {
    Twelve t1("1A");
    Twelve t2("2B");
    Twelve t3("1A");

    EXPECT_TRUE(t1 < t2);
    EXPECT_TRUE(t2 > t1);
    EXPECT_TRUE(t1 == t3);
    EXPECT_TRUE(t1 != t2);
    EXPECT_TRUE(t1 <= t3);
    EXPECT_TRUE(t2 >= t1);
}

TEST(TwelveTest, ExceptionTests) {
    // Проверка выброса исключения при создании объекта с некорректной цифрой
    EXPECT_THROW(Twelve(3, 12), std::invalid_argument);
    EXPECT_THROW(Twelve({1, 2, 12}), std::invalid_argument);
    EXPECT_THROW(Twelve("1A2C"), std::invalid_argument);

    // Проверка отсутствия выброса исключения при создании объекта с корректными данными
    EXPECT_NO_THROW(Twelve(3, 5));
    EXPECT_NO_THROW(Twelve({1, 2, 3}));
    EXPECT_NO_THROW(Twelve("1A2B"));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

