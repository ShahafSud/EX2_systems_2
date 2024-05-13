//209374487
#include <vector>
#include <iostream>
#include "Graph.hpp"


void Graph::loadGraph(std::vector<std::vector<int>> g) {
    if(g.size()!=g[0].size())throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    for(int i=0;i<g.size();i++){
        if(g[i][i]!=0)throw std::invalid_argument("Invalid graph: No self edges allowed!");
    }
    this->g = g;this->size = g.size();
}
void Graph::printGraph() {
    for (const auto& row : this->g) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
std::vector<std::vector<int>> Graph::getMat(){
    std::vector<std::vector<int>> ans = this->g;
    return ans;
}