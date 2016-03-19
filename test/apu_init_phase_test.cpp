#include "apu_init_phase.h"
#include "gtest/gtest.h"

TEST(apu_init_phase, should_return_closest_neighbor_on_the_right) {
    EXPECT_EQ(1, closest_right("00", 0));
}

TEST(apu_init_phase, should_return_negative_one_if_no_node) {
    EXPECT_EQ(-1, closest_right(".....", 0));
}

TEST(apu_init_phase, should_return_negative_one_if_no_node_found) {
    EXPECT_EQ(-1, closest_right("0.0..", 3));
}

TEST(apu_init_phase, should_return_closest_neighbor_on_the_bottom) {
    EXPECT_EQ(1, closest_bottom(vector<string>({"0.0..",
                                                "0...0"}), 0, 0));
}

TEST(apu_init_phase, should_return_negative_one_if_no_node_at_y) {
    EXPECT_EQ(-1, closest_bottom(vector<string>({"..0..",
                                                 "....0"}), 0, 0));
}

TEST(apu_init_phase, should_return_negative_one_if_no_node_found_at_y) {
    EXPECT_EQ(-1, closest_bottom(vector<string>({"..0..",
                                                 "0....",
                                                 "....0"}), 0, 1));
}

TEST(apu_init_phase, should_return_neighbors_vectors) {
    EXPECT_EQ(
            vector<string>({"0 0 1 0 0 1",
                            "0 1 -1 -1 -1 -1",
                            "1 0 -1 -1 -1 -1"}

            ),
            closest_neighbors(vector<string>(
                    {"00",
                     "0."}
            )));
}




