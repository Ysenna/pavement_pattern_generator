#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PatternGenerator.h"



TEST(PatternGeneratorTests, ReturnsNotNull)
{
    PatternGenerator patternGenerator;
    std::vector<unsigned> tileWidths = {40, 60, 90};
    EXPECT_FALSE(patternGenerator.generate(20, 20, 20, 20, tileWidths).empty());
}