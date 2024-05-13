//209374487
#include <vector>
#include <queue>
#include "Graph.hpp"
#include <string>


namespace Algorithms {
    int isConnected(Graph graphObj);
    bool isContainsCycle(Graph graphObj);
    std::string isBipartite(Graph graphObj);
    std::string shortestPath(Graph graphObj, int startVer, int endVer);
    std::string negativeCycle(Graph graphObj);
}