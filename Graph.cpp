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
std::vector<std::vector<int>> Graph::getMat() const{
    std::vector<std::vector<int>> ans = this->g;
    return ans;
}
// Prefix
Graph& Graph::operator++() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g[i][j]++;
        }
        g[i][i]=0;
    }
    return *this;
}
// Postfix
Graph Graph::operator++(int) {
    Graph temp(*this); // Make a copy
    ++(*this);
    return temp;
}

Graph Graph::operator+(const Graph& other) const {
    std::vector<std::vector<int>> g = other.getMat();
    if(this->size!=g.size())throw("Unable to add graphs of unequal sizes!");
    std::vector<std::vector<int>> ans(this->size, std::vector<int>(this->size, 0));
    for(int i=0;i<this->size;i++){
        for(int j=0;j<this->size;j++){
            ans[i][j] = this->g[i][j] + g[i][j];
        }
    }
    Graph grph = Graph();
    grph.loadGraph(ans);
    return grph;
}
Graph Graph::operator-(const Graph& other) const {
    return *this + (-other);
}

Graph& Graph::operator+=(const Graph& other) {
    if (this->size != other.size) throw std::invalid_argument("Graphs must be of the same size!");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            this->g[i][j] += other.g[i][j];
        }
    }
    return *this;
}
Graph& Graph::operator-=(const Graph& other) {
    *this+=((-1)*other);
    return *this;
}
Graph& Graph::operator+=(int x) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g[i][j] = g[i][j] + x;
        }
        g[i][i]=0;
    }
    return *this;
}
Graph& Graph::operator-=(int x) {
    int y = -1*x;
    *this+=y;
    return *this;
}

Graph Graph::operator*(int scalar) const {
    Graph ans(*this);
    for (int i = 0; i < ans.size; ++i) {
        for (int j = 0; j < ans.size; ++j) {
            ans.g[i][j] *= scalar;
        }
    }
    return ans;
}
Graph operator*(int scalar, const Graph& graph) {
    return graph * scalar; // Use the Graph * int operator
}
Graph Graph::operator-() const {
    
    return *this * (-1);
}
Graph Graph::operator+() const {
    return *this;
}
Graph Graph::operator*(const Graph& other) const{
    if (this->size != other.size) throw std::invalid_argument("Graphs must be of the same size!");
    std::vector<std::vector<int>> resultMat(this->size, std::vector<int>(this->size, 0));
    
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < this->size; ++j) {
            for (int k = 0; k < this->size; ++k) {
                resultMat[i][j] += this->g[i][k] * other.g[k][j];
            }
        }
        resultMat[i][i] = 0;//make sure the result is a valid graph otherwise loadthrows errors.
    }
    
    Graph result;
    result.loadGraph(resultMat);
    return result;
}

int Graph::compare(const Graph& other) const{
    //check if equal
    std::vector<std::vector<int>> g = other.getMat();
    bool identical = g.size()==this->size;
    int counter_this = 0;
    int counter_other = 0;
    for(int i=0;i<this->size;i++){
        for(int j=0;j<this->size;j++){
            if(this->g[i][j]!=g[i][j])identical=false;
            if(this->g[i][j]!=0)counter_this++;
            if(g[i][j]!=0)counter_other++;
        }
    }
    if(identical)return 0;//equal
    if(counter_this>counter_other)return -1;//left is bigger
    if(counter_this<counter_other)return 1;//right is bigger

    if(g.size()>this->size)return 1;//right is bigger
    if(g.size()<this->size)return -1;//left is bigger

    //other canot be a subgraph of this if not equal and reached here, but if equal we didnt reach here.
    return 0;
}
bool Graph::operator>(const Graph& other) const{
    int ans = this->compare(other);
    return ans==-1;
}
bool Graph::operator>=(const Graph& other) const{
    int ans = this->compare(other);
    return ans!=1;
}
bool Graph::operator<(const Graph& other) const{
    int ans = this->compare(other);
    return ans==1;
}
bool Graph::operator<=(const Graph& other) const{
    int ans = this->compare(other);
    return ans!=-1;
}
bool Graph::operator==(const Graph& other) const{
    int ans = this->compare(other);
    return ans==0;
}
bool Graph::operator!=(const Graph& other) const{
    int ans = this->compare(other);
    return ans!=0;
}