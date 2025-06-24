#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PatternGenerator.h"
#include "PatternGeneratorTests.h"



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
    EXPECT_EQ(patternGenerator
            .generate(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths).size(), expectedRowCount);
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



TEST_F(PatternGeneratorTests, AllEdgeTilesHaveAtLeastMinimumAllowedWidth)
{
    // seed 14 - vygeneruje celou řadu ze stejného formátu
    std::mt19937 mt(128);
    const std::vector<std::vector<unsigned>> pattern =
        generateWithSeed(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths, mt);

    const unsigned minEdgeWidth = 14;    // At least 1/3 of smallest tile
    for (const auto &row : pattern) {
        EXPECT_TRUE(row.front() >= minEdgeWidth && row.back() >= minEdgeWidth);
    }
}



const std::vector<std::vector<unsigned>> PatternGeneratorTests::generateWithSeed(
    unsigned areaWidth,
    unsigned areaHeight,
    unsigned seamThickness,
    unsigned rowHeight,
    std::vector<unsigned> tileWidths,
    std::mt19937 mtGenerator)
{
    return patternGenerator.generateWithSeed(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths, mtGenerator);
}
