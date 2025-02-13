// practice03_test.cpp
#include <gtest/gtest.h>
#include "/workspaces/cpsc2376-martinez/practice/practice03/practice03.cpp"

TEST(MathUtilsTest, SumRange) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 10);
    EXPECT_EQ(MathUtils::sumRange(0, 0), 0);
    EXPECT_EQ(MathUtils::sumRange(-3, 3), -3);
}

TEST(MathUtilsTest, ContainsNegative) {
    std::vector<int> values1 = { 3, -1, 5, 7 };
    std::vector<int> values2 = { 3, 1, 5, 7 };
    std::vector<int> values3 = { -3, -1, -5, -7 };
    std::vector<int> values4 = {};

    EXPECT_TRUE(MathUtils::containsNegative(values1));
    EXPECT_FALSE(MathUtils::containsNegative(values2));
    EXPECT_TRUE(MathUtils::containsNegative(values3));
    EXPECT_FALSE(MathUtils::containsNegative(values4));
}

TEST(MathUtilsTest, FindMax) {
    std::vector<int> values1 = { 3, -1, 5, 7 };
    std::vector<int> values2 = { 3, 1, 5, 7 };
    std::vector<int> values3 = { -3, -1, -5, -7 };
    std::vector<int> values4 = {};

    EXPECT_EQ(MathUtils::findMax(values1), 7);
    EXPECT_EQ(MathUtils::findMax(values2), 7);
    EXPECT_EQ(MathUtils::findMax(values3), -1);
    EXPECT_EQ(MathUtils::findMax(values4), 0);
}

