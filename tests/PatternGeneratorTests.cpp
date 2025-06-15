#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PatternGenerator.h"



TEST(PatternGeneratorTests, ReturnsNotEmpty)
{
    PatternGenerator patternGenerator;
    const std::vector<unsigned> tileWidths = {40, 60, 90};
    EXPECT_FALSE(patternGenerator.generate(20, 20, 2, 20, tileWidths).empty());
}

TEST(PatternGeneratorTests, ReturnsEmpty_WhenZeroWidth)
{
    PatternGenerator patternGenerator;
    const std::vector<unsigned> tileWidths = {40, 60, 90};
    EXPECT_TRUE(patternGenerator.generate(0, 20, 2, 20, tileWidths).empty());
}

TEST(PatternGeneratorTests, ReturnsEmpty_WhenZeroHeight)
{
    PatternGenerator patternGenerator;
    const std::vector<unsigned> tileWidths = {40, 60, 90};
    EXPECT_TRUE(patternGenerator.generate(20, 0, 2, 20, tileWidths).empty());
}

TEST(PatternGeneratorTests, ReturnsCorrectRowCount)
{
    PatternGenerator patternGenerator;
    const std::vector<unsigned> tileWidths = {40, 60, 90};
    unsigned const expectedRowCount = 5;
    EXPECT_EQ(patternGenerator.generate(20, 100, 2, 20, tileWidths).size(), expectedRowCount);
}

