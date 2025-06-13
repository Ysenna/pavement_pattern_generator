#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H

#include <vector>


class PatternGenerator {
    public:
     std::vector<std::vector<unsigned>>  generatePattern(
         int areaWidth,
         int areaHeight,
         int seamThickness,
         int rowHeight,
         std::vector<unsigned> tileWidths);
};



#endif //PATTERNGENERATOR_H
