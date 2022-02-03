#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP


#include <limits>
#include <Graph.hpp>

class Algorithm {
    public:
        virtual int findFlow(std::shared_ptr<Graph> graph, int source, int sink, int* paths = NULL) const = 0;
};


#endif //ALGORITHM_HPP