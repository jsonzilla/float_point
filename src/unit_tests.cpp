#include "gtest/gtest.h"

#include "../src/ieee745.h"
#include "../src/binarySum.h"

TEST(ieee745_behavior, correct_convert_value)
{
  ieee745 f;
  f.signal = 1;
  f.matissa = 1;
  f.expoent = -1;

  EXPECT_EQ(f.value(), -0.5);
}

TEST(ieee745_behavior, correct_convert_value_binary_input)
{
  ieee745 f;
  f.signal = 0b0;
  f.matissa = 0b1;
  f.expoent = 0b010;

  EXPECT_EQ(f.valueByBinaryInput(), 0.5);
}

TEST(ieee745_behavior, correct_convert_signal)
{
  ieee745 f;
  f.signal = 1;
  EXPECT_EQ(f.value(), -0.0);
}

TEST(ieee745_behavior, check_invalid_matissa)
{
  ieee745 f;
  EXPECT_EQ(f.check(), false);
  f.matissa = 0xA;
  EXPECT_EQ(f.check(), false);
}

TEST(ieee745_behavior, check_valid_matissa)
{
  ieee745 f;
  f.matissa = 0x01;
  EXPECT_EQ(f.check(), true);
}

TEST(binary_sum_behavior, check)
{
  auto bs = BS(-1) + BS(-2) + BS(-2);
  
  EXPECT_EQ(bs.dec(), 0.0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}