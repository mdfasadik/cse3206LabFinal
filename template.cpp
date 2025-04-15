#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int multiply(int a, int b)
{
    return a * b;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

TEST(MultiplyTests, PositiveNumbers)
{
    EXPECT_EQ(multiply(5, 4), 6); // ==============Failing Test
}

TEST(MultiplyTests, OneNegative)
{
    EXPECT_EQ(multiply(4, -5), -20);
}

TEST(MultiplyTests, TwoNegatives)
{
    EXPECT_EQ(multiply(-6, -7), 42);
}

TEST(MultiplyTests, ZeroCase)
{
    EXPECT_EQ(multiply(0, 5), 0);
    EXPECT_EQ(multiply(-3, 0), 0);
}

TEST(AdditionTests, PositiveNumbers)
{
    EXPECT_EQ(add(5, 4), 9);
}

TEST(AdditionTests, NegativeNumber)
{
    EXPECT_EQ(add(5, -3), 2);
}

TEST(AdditionTests, FailingCase)
{
    EXPECT_EQ(add(3, 3), 5); // ==============Failing Test
}

TEST(SubtractionTests, PositiveNumbers)
{
    EXPECT_EQ(subtract(10, 4), 6);
}

TEST(SubtractionTests, NegativeResult)
{
    EXPECT_EQ(subtract(3, 5), -2);
}

TEST(SubtractionTests, FailingCase)
{
    EXPECT_EQ(subtract(7, 2), 6); // ==============Failing Test
}

int main(int argc, char **argv)
{
    cout << "Running tests" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
