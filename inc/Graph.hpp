#ifndef GRAPH_HPP
#define GRAPH_HPP


#include <vector>
#include <fstream>
#include <memory>
#include <stack>
#include <Edge.hpp>

class Graph {
private:
    std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>> _adjacency;
    int _edges = 0;

public:
    explicit Graph() {};

    void addEdge(int source, int destination, int capacity);
    void addEdge(std::shared_ptr<Edge> newEdge);
    void generateHiperCube(int dimensions);

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>>> getAdjacency() const {
        return std::make_shared<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>>>(_adjacency);
    }
    int getVerticesNum() const { return _adjacency.size(); }
    int getEdgesNum() const { return _edges; }
};


#endif //GRAPH_HPP
