#include <CLI/CLI.hpp>

#include "CLIParser.h"



Params parseCLI(int argc, char **argv)
{
    CLI::App app{"Pavement pattern generator"};
    argv = app.ensure_utf8(argv);

    Params params;
    params.areaWidth = 300;
    params.areaHeight = 500;
    params.rowHeight = 30;
    params.seamThickness = 2;
    params.tileWidths = {40, 60, 90};

    app.add_option("-W, --area-width", params.areaWidth, "Width of paved area in cm");
    app.add_option("-H, --area-height", params.areaHeight, "Height of paved areain cm");
    app.add_option("-R, --row-height", params.rowHeight, "Height of row in cm");
    app.add_option("-S, --seam-thickness", params.seamThickness, "Thickness of seams in cm");
    app.add_option(
        "-T, --tile-width",
        params.tileWidths,
        "List of tile widths in cm separated by a space");

    try {
        app.parse(argc, argv);
    } catch(const CLI::ParseError &e) {
        std::exit(app.exit(e));
    }
    return params;
}
