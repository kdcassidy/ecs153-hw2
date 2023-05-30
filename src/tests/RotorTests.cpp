extern "C" {
#include "Rotor.h"
#include "common.h"
}
#include <gtest/gtest.h>

namespace {

TEST(RotorTests, RotorForwardShuffleNoOffset) {
    EXPECT_EQ(forward_rotor_shuffle('A', ROTOR_I, 0), 'E');
    EXPECT_EQ(forward_rotor_shuffle('B', ROTOR_I, 0), 'K');
    EXPECT_EQ(forward_rotor_shuffle('C', ROTOR_I, 0), 'M');
    EXPECT_EQ(forward_rotor_shuffle('R', ROTOR_I, 0), 'U');
    EXPECT_EQ(forward_rotor_shuffle('S', ROTOR_I, 0), 'S');
    EXPECT_EQ(forward_rotor_shuffle('T', ROTOR_I, 0), 'P');
}

TEST(RotorTests, RotorForwardShuffleWithOffset) {
    EXPECT_EQ(forward_rotor_shuffle('A', ROTOR_I, 8), 'V');
    EXPECT_EQ(forward_rotor_shuffle('B', ROTOR_I, 3), 'L');
    EXPECT_EQ(forward_rotor_shuffle('C', ROTOR_I, 2), 'L');
    EXPECT_EQ(forward_rotor_shuffle('R', ROTOR_I, 8), 'J');
    EXPECT_EQ(forward_rotor_shuffle('S', ROTOR_I, 8), 'E');
    EXPECT_EQ(forward_rotor_shuffle('T', ROTOR_I, 8), 'K');
}

TEST(RotorTests, RotorReverseInvert) {
    EXPECT_EQ(reverse_rotor_shuffle('V', ROTOR_I, 8), 'A');
    EXPECT_EQ(reverse_rotor_shuffle('L', ROTOR_I, 3), 'B');
    EXPECT_EQ(reverse_rotor_shuffle('L', ROTOR_I, 2), 'C');
    EXPECT_EQ(reverse_rotor_shuffle('J', ROTOR_I, 8), 'R');
    EXPECT_EQ(reverse_rotor_shuffle('E', ROTOR_I, 8), 'S');
    EXPECT_EQ(reverse_rotor_shuffle('K', ROTOR_I, 8), 'T');
}

TEST(RotorTests, RotorReverseShuffleNoOffset) {
    EXPECT_EQ(reverse_rotor_shuffle('A', ROTOR_II, 0), 'A');
    EXPECT_EQ(reverse_rotor_shuffle('B', ROTOR_II, 0), 'J');
    EXPECT_EQ(reverse_rotor_shuffle('C', ROTOR_II, 0), 'P');
    EXPECT_EQ(reverse_rotor_shuffle('R', ROTOR_II, 0), 'G');
    EXPECT_EQ(reverse_rotor_shuffle('S', ROTOR_II, 0), 'E');
    EXPECT_EQ(reverse_rotor_shuffle('T', ROTOR_II, 0), 'N');
}

TEST(RotorTests, RotorReverseShuffleWithOffset) {
    EXPECT_EQ(reverse_rotor_shuffle('A', ROTOR_II, 8), 'S');
    EXPECT_EQ(reverse_rotor_shuffle('B', ROTOR_II, 3), 'G');
    EXPECT_EQ(reverse_rotor_shuffle('C', ROTOR_II, 2), 'N');
    EXPECT_EQ(reverse_rotor_shuffle('R', ROTOR_II, 8), 'Y');
    EXPECT_EQ(reverse_rotor_shuffle('S', ROTOR_II, 8), 'W');
    EXPECT_EQ(reverse_rotor_shuffle('T', ROTOR_II, 8), 'F');
}

}