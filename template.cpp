#include <iostream>
#include <gtest/gtest.h>

using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    cout << "Running tests" << endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}