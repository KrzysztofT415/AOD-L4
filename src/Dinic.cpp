#include<Dinic.hpp>
#include<queue>
#include <functional>

int Dinic::findFlow(std::shared_ptr<Graph> graph, int source, int sink, int* paths) const {
    int flow = 0;
    auto adjacency = graph->getAdjacency();

    while (true) {
        std::queue<int> queue;
        std::vector<int> level(graph->getVerticesNum(), -1);
        level[source] = 0;
        queue.push(source);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            for (const std::shared_ptr<Edge>& edge : *(*adjacency)[current]) {
                if (level[edge->getDestination()] == -1 && edge->getDestination() != source && (edge->getCapacity() > edge->getFlow() || edge->getFlow() < 0)) {
                    level[edge->getDestination()] = level[current] + 1;
                    queue.push(edge->getDestination());
                }
            }
        }
        if (level[sink] == -1) return flow;

        std::vector<int> visited(graph->getVerticesNum(), 0);
        std::function<int(int c, int f)> flowRecursive = [&](int current, int f){
            if (current == sink) {
                if (paths != NULL) (*paths)++;
                return f;
            }

            int edges = (*adjacency)[current]->size();
            for (; visited[current] < edges; ++visited[current]) {
                auto edge = (*(*adjacency)[current])[visited[current]];
                
                if (level[current] + 1 == level[edge->getDestination()] && edge->getDestination() != source && (edge->getCapacity() > edge->getFlow() || edge->getFlow() < 0)) {
                    int df = std::min(f, edge->getFlow() >= 0 ? edge->getCapacity() - edge->getFlow() : -edge->getFlow());
                    df = flowRecursive(edge->getDestination(), df);
                    if (df > 0) {
                        edge->incrementFlow(df);
                        edge->getReverse()->incrementFlow(-df);
                        return df;
                    }
                }
            }
            return 0;
        };

        while (int df = flowRecursive(source, std::numeric_limits<int>::max())) flow += df;
    }
}