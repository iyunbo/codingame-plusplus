#include <algorithm>
#include "defibrillators.h"
#include "gtest/gtest.h"

TEST(defibrillators_test, nearest_should_return_string) {
    list<string> defs;
    defs.push_back("1");
    EXPECT_TRUE(nearest(defs, "1", "2").size() > 1);
}

TEST(defibrillators_test, distance_should_return_pisitive) {
    const Location locA = {1.0, 1.0};
    const Location locB = {2.0, 2.0};
    EXPECT_GE(distance(locA, locB), 0.0);
}

