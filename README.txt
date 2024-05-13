ID: 209374487
startup:
run the command make or make all to create the exe files.

recomanded: run ./test.exe to check all the API is working with your compiler.

Graph.cpp and Graph.hpp contains the class Graph
methodes: 
getMat() returns the matrix vector of the Graph
printGraph() prints the Graph
loadGraph() create a Graph instance from a matrix vector
example:
Graph g;
vector<vector<int>> graph = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}};
g.loadGraph(graph);
g.printGraph();


Algorithms.cpp and Algorithms.hpp contains the functions:
int isConnected(Graph graphObj);
1=is connected, 0=not connected.

bool isContainsCycle(Graph graphObj);
true and false, no explanation required.

std::string isBipartite(Graph graphObj);
returns "The graph is bipartite: A={vertex list}, B={vertex list}" or 0 if g is not Bipartite.

std::string shortestPath(Graph graphObj, int startVer, int endVer);
returns path as vertex list of the form "0->1->2" or "-1" if no path was found.

std::string negativeCycle(Graph graphObj);
returns cycle as vertex list of the form "0->1->2->0" or "No Negative Cycle".

addit demo as you wish and run:
make clean;clear;make
you can just run make but its safer to run the three comands.