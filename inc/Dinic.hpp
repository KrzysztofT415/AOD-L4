#ifndef DINIC_HPP
#define DINIC_HPP


#include<Algorithm.hpp>

class Dinic : public Algorithm {
    public:
        int findFlow(std::shared_ptr<Graph> graph, int source, int sink, int* paths = NULL) const;
};


#endif //DINIC_HPP