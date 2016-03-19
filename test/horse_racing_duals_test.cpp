#include "horse_racing_duals.h"
#include "gtest/gtest.h"

TEST(horse_racing_duals, should_return_zero_when_elements_are_equal) {
    vector<int> elements({2,2,2,2});
    EXPECT_TRUE(diff_of_closest_elements(elements) == 0);
}

TEST(horse_racing_duals, should_return_diff_of_closest_elements) {
    vector<int> elements({2,5,8,9});
    EXPECT_TRUE(diff_of_closest_elements(elements) == 1);
}



