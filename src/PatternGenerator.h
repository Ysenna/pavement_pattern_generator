#ifndef PATTERNGENERATOR_H
#define PATTERNGENERATOR_H

#include <vector>


class PatternGenerator {
    public:
     std::vector<std::vector<unsigned>>  generate(
         unsigned areaWidth,
         unsigned areaHeight,
         unsigned seamThickness,
         unsigned rowHeight,
         std::vector<unsigned> tileWidths);
};



#endif //PATTERNGENERATOR_H
