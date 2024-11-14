// include/Visualization.h

#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Graph.h"
#include <string>

class Visualization {
public:
    static void generateDotFile(const Graph &graph, const std::string &filename);
};

#endif
