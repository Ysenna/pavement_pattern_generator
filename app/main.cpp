#include <iostream>

#include "PatternGenerator.h"



int main(int argc, const char* argv[])
{
    std::cout << "Running pattern generator\n";

    PatternGenerator patternGenerator;
    std::vector <unsigned> const tileWidths = {40, 60, 90};
    std::vector<std::vector<unsigned>>  pattern = patternGenerator.generate(500, 800, 2, 40, tileWidths);

    return 0;
}