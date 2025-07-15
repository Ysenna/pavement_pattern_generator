#include <iostream>

#include <CLI/CLI.hpp>

#include "PatternGenerator.h"



int main(int argc, char* argv[])
{
    std::cout << "Running pattern generator\n";

    CLI::App app{"Pavement pattern generator"};
    argv = app.ensure_utf8(argv);

    Params params;
    params.areaWidth = 300;
    params.areaHeight = 500;
    params.rowHeight = 30;
    params.seamThickness = 2;

    app.add_option("-W, --area-width", params.areaWidth, "Width of paved area in cm");
    app.add_option("-H, --area-height", params.areaHeight, "Height of paved areain cm");
    app.add_option("-R, --row-height", params.rowHeight, "Height of row in cm");
    app.add_option("-S, --seam-thickness", params.seamThickness, "Thickness of seams in cm");

    CLI11_PARSE(app, argc, argv);

    std::cout << "Generation pattern for following parameters:" << std::endl;
    std::cout << "\tarea: " << params.areaWidth << "x" << params.areaHeight << std::endl;
    std::cout << "\trow height: " << params.rowHeight << std::endl;
    std::cout << "\tseam thickness: " << params.seamThickness << std::endl;

    PatternGenerator patternGenerator;
    std::vector <unsigned> const tileWidths = {40, 60, 90};
    std::vector<std::vector<unsigned>>  pattern = patternGenerator.generate(500, 800, 2, 40, tileWidths);

    return 0;
}