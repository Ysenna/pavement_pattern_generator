#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PatternGenerator.h"



class PatternGeneratorTests : public ::testing::Test {
protected:
    PatternGenerator patternGenerator;
    std::vector<unsigned> tileWidths = {40, 60, 90};
    const unsigned areaWidth = 200;
    const unsigned areaHeight = 100;
    const unsigned rowHeight = 20;
    const unsigned seamThickness = 2;
};

TEST_F(PatternGeneratorTests, ReturnsNotEmpty)
{
    EXPECT_FALSE(patternGenerator.generate(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths).empty());
}

TEST_F(PatternGeneratorTests, ReturnsEmpty_WhenZeroWidth)
{
    EXPECT_TRUE(patternGenerator.generate(0, areaHeight, seamThickness, rowHeight, tileWidths).empty());
}

TEST_F(PatternGeneratorTests, ReturnsEmpty_WhenZeroHeight)
{
    EXPECT_TRUE(patternGenerator.generate(areaWidth, 0, seamThickness, rowHeight, tileWidths).empty());
}

TEST_F(PatternGeneratorTests, ReturnsCorrectRowCount)
{
    unsigned const expectedRowCount = 5;
    EXPECT_EQ(patternGenerator.generate(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths).size(), expectedRowCount);
}

TEST_F(PatternGeneratorTests, AllRowsHaveAreaWidth)
{
    const std::vector<std::vector<unsigned>> pattern =
        patternGenerator.generate(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths);

    for (const auto &row : pattern) {
        unsigned rowWidth = 0;
        for (auto col : row) {
            rowWidth += col + seamThickness;
        }
        rowWidth -= seamThickness;
        EXPECT_EQ(rowWidth, areaWidth);
    }
}