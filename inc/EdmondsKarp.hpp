#ifndef EDMONDSKARP_HPP
#define EDMONDSKARP_HPP


#include<Algorithm.hpp>

class EdmondsKarp : public Algorithm {
    public:
        int findFlow(std::shared_ptr<Graph> graph, int source, int sink, int* paths = NULL) const;
};


#endif //EDMONDSKARP_HPP