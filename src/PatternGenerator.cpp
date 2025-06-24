#include <ctime>
#include <cstdlib>
#include <iostream>
#include <random>

#include "PatternGenerator.h"


 std::vector<std::vector<unsigned>> PatternGenerator::generate(
    const unsigned areaWidth,
    const unsigned areaHeight,
    const unsigned seamThickness,
    const unsigned rowHeight,
    const std::vector<unsigned> tileWidths)
{
    std::random_device rd;
    std::mt19937 mtGenerator(rd());
    return generateWithSeed(areaWidth, areaHeight, seamThickness, rowHeight, tileWidths, mtGenerator);
}

std::vector<std::vector<unsigned>> PatternGenerator::generateWithSeed(
    const unsigned areaWidth,
    const unsigned areaHeight,
    const unsigned seamThickness,
    const unsigned rowHeight,
    const std::vector<unsigned> tileWidths,
    std::mt19937 mtGenerator)
 {
     // Generate pavement pattern
     const unsigned rowCount = ceil(static_cast<double>(areaHeight - rowHeight) / (rowHeight + seamThickness)) + 1;
     std::vector<std::vector<unsigned>> generatedTileSizes;
     if (areaHeight == 0 || areaWidth == 0) {
         return generatedTileSizes;
     }

     std::uniform_int_distribution<> rndDistrib(0, tileWidths.size() - 1);
     unsigned minAllowedWidth = 14;
     for (int row = 0; row < rowCount; row++) {
         generatedTileSizes.push_back(std::vector<unsigned>());

         // Fill row with tiles
         unsigned rowWidth = 0;
         while (rowWidth < areaWidth) {
             unsigned tileIdx = rndDistrib(mtGenerator) ;
             rowWidth += tileWidths.at(tileIdx)+ seamThickness;
             generatedTileSizes[row].push_back(tileWidths.at(tileIdx));
         }
         rowWidth -= seamThickness;

         // Trim edge tiles to fit the area
         if (rowWidth > areaWidth) {
             unsigned trimmedWidth = generatedTileSizes[row].back() - (rowWidth - areaWidth);
             if (trimmedWidth <= minAllowedWidth) {
                 generatedTileSizes[row].front() -= minAllowedWidth - trimmedWidth;
                 generatedTileSizes[row].back() = minAllowedWidth;
             }
             else {
                 generatedTileSizes[row].back() = trimmedWidth;
             }
         }
     }

     return generatedTileSizes;
 }

