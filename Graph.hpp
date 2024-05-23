//209374487
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>

class Graph{
    int size;
    std::vector<std::vector<int>> g;

    int compare(const Graph& other) const;
    public:
        void loadGraph(std::vector<std::vector<int>> g);
        void printGraph();
        std::vector<std::vector<int>> getMat() const;


    // Prefix
    Graph& operator++();
    // Postfix
    Graph operator++(int);

    Graph operator+(const Graph& other) const;
    Graph operator-(const Graph& other) const;
    Graph& operator+=(const Graph& other);
    Graph& operator-=(const Graph& other);
    Graph& operator+=(int x);
    Graph& operator-=(int x);
    Graph operator*(int scalar) const;

    Graph operator-() const;
    Graph operator+() const;

    Graph operator*(const Graph& other) const;


    bool operator>(const Graph& other)const;
    bool operator>=(const Graph& other)const;
    bool operator<(const Graph& other)const;
    bool operator<=(const Graph& other)const;
    bool operator==(const Graph& other)const;
    bool operator!=(const Graph& other)const;
};

Graph operator*(int scalar, const Graph& graph);

#endif // GRAPH_HPP