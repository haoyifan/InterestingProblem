#include "Graph.h"

int main(int argc, char *argv[]) {
    std::string file(argv[1]);
    mincut::Graph graph;
    graph.init(file);
    std::cout << graph.get_mincut() << std::endl;
}
