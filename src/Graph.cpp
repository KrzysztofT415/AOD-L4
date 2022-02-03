#include <Graph.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <time.h>


void Graph::addEdge(int source, int destination, int capacity) {
    addEdge(std::make_shared<Edge>(source, destination, capacity));
}

void Graph::addEdge(std::shared_ptr<Edge> newEdge) {
    uint cap = std::max(newEdge->getSource(), newEdge->getDestination()) + 1;
    if (_adjacency.size() < cap) {
        int j = cap - _adjacency.size();
        _adjacency.reserve(j);
        for (int i = 0; i < j; ++i)
            _adjacency.push_back(std::make_shared<std::vector<std::shared_ptr<Edge>>>());
    }
    _edges += 1;
    _adjacency[newEdge->getSource()]->push_back(newEdge);
}

void Graph::generateHiperCube(int dimensions) {
    int size = std::pow(2, dimensions);
    auto count1bits = [](int n) { return std::bitset < 32 > (n).count(); };

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int ei = count1bits(i);
            int ej = count1bits(j);
            bool oneDiff = count1bits(i ^ j) == 1;
            if (oneDiff && ei + 1 == ej) {
                int l = std::max(std::max(ei, dimensions - ei), std::max(ej, dimensions - ej));
                l = rand() % (int)std::pow(2, l) + 1;
                std::shared_ptr<Edge> newEdge = std::make_shared<Edge>(i, j, l);
                std::shared_ptr<Edge> reversed = std::make_shared<Edge>(j, i, l, false);
                addEdge(newEdge);
                addEdge(reversed);
                newEdge->setReverse(reversed);
                reversed->setReverse(newEdge);
            }
        }
    }

    if (_edges != dimensions * size) {
        std::cout << "Edges miscounted\n";
        exit(1);
    }
}