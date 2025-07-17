#include <iostream>

#include "CLIParser.h"
#include "PatternGenerator.h"



int main(int argc, char* argv[])
{
    std::cout << "Running pattern generator\n";

    Params params = parseCLI(argc, argv);

    std::cout << "Generation pattern for following parameters:" << std::endl;
    std::cout << "\tarea: " << params.areaWidth << "x" << params.areaHeight << std::endl;
    std::cout << "\trow height: " << params.rowHeight << std::endl;
    std::cout << "\tseam thickness: " << params.seamThickness << std::endl;
    std::cout << "\ttile width: ";
    for (auto tile : params.tileWidths) {
        std::cout << tile << ", ";
    }
    std::cout << std::endl;

    PatternGenerator patternGenerator;
    std::vector<std::vector<unsigned>>  pattern = patternGenerator.generate(params.areaWidth, params.areaHeight, params.seamThickness, params.rowHeight, params.tileWidths);

    return 0;
}