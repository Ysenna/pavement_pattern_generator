#ifndef CLIPARSER_H
#define CLIPARSER_H

#include <vector>



struct Params
{
    unsigned areaWidth;
    unsigned areaHeight;
    unsigned rowHeight;
    unsigned seamThickness;
    std::vector<unsigned> tileWidths;
};

Params parseCLI(int argc, char **argv);

#endif //CLIPARSER_H
