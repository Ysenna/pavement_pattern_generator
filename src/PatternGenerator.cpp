#include <ctime>
#include <cstdlib>

#include "PatternGenerator.h"

#include <iostream>
#include <random>


 std::vector<std::vector<unsigned>> PatternGenerator::generate(
    int areaWidth,
    int areaHeight,
    int seamThickness,
    int rowHeight,
    std::vector<unsigned> tileWidths)
{
    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 mtGenerator(rd());
    std::uniform_int_distribution<> rndDistrib(0, tileWidths.size() - 1);

    // Generate pavement pattern
    unsigned rowCount = (areaHeight - rowHeight) / (rowHeight + seamThickness) + 1;
    std::vector<std::vector<unsigned>> generatedTileSizes;
    for (int row = 0; row < rowCount; row++) {
        generatedTileSizes.push_back(std::vector<unsigned>());

        unsigned rowWidth = 0;
        // Fill each row with tiles
        while (rowWidth < areaWidth) {
            unsigned tileIdx = rndDistrib(mtGenerator) ;
            rowWidth += tileWidths.at(tileIdx)+ seamThickness;
            generatedTileSizes[row].push_back(tileWidths.at(tileIdx));
        }
    }

    return generatedTileSizes;
}

