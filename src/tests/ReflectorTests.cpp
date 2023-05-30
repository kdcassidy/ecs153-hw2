extern "C" {
#include "Reflector.h"
#include "common.h"
}
#include <gtest/gtest.h>

namespace {

TEST(ReflectorTests, TestReflectorShuffle) {
    char reflector[] = "YXWVUTSRQPONMLKJIHGFEDCBAX";    
    EXPECT_EQ(reflector_shuffle('A', reflector), 'Y');
    EXPECT_EQ(reflector_shuffle('B', reflector), 'X');
    EXPECT_EQ(reflector_shuffle('C', reflector), 'W');
	EXPECT_EQ(reflector_shuffle('I', reflector), 'Q');
    EXPECT_EQ(reflector_shuffle('Y', reflector), 'A');
    EXPECT_EQ(reflector_shuffle('Z', reflector), 'X');
}

TEST(ReflectorTests, TestReflectorIdentity) {    
    EXPECT_EQ(reflector_shuffle('A', LETTERS), 'A');
    EXPECT_EQ(reflector_shuffle('B', LETTERS), 'B');
    EXPECT_EQ(reflector_shuffle('C', LETTERS), 'C');
	EXPECT_EQ(reflector_shuffle('I', LETTERS), 'I');
    EXPECT_EQ(reflector_shuffle('Y', LETTERS), 'Y');
    EXPECT_EQ(reflector_shuffle('Z', LETTERS), 'Z');
}

TEST(ReflectorTests, TestReflector_I_UKW_A) { 
    EXPECT_EQ(reflector_shuffle('A', I_UKW_A), 'E');
    EXPECT_EQ(reflector_shuffle('B', I_UKW_A), 'J');
    EXPECT_EQ(reflector_shuffle('C', I_UKW_A), 'M');
	EXPECT_EQ(reflector_shuffle('I', I_UKW_A), 'V');
    EXPECT_EQ(reflector_shuffle('Y', I_UKW_A), 'G');
    EXPECT_EQ(reflector_shuffle('Z', I_UKW_A), 'D');
}

}