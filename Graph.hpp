//209374487
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>

class Graph{
    int size;
    std::vector<std::vector<int>> g;
    public:
        void loadGraph(std::vector<std::vector<int>> g);
        void printGraph();
        std::vector<std::vector<int>> getMat();
};
#endif // GRAPH_HPP