#include<EdmondsKarp.hpp>
#include<queue>

int EdmondsKarp::findFlow(std::shared_ptr<Graph> graph, int source, int sink, int* paths) const {
    int flow = 0;
    auto adjacency = graph->getAdjacency();

    while (true) {
        auto queue = std::queue<int>();
        std::vector<std::shared_ptr<Edge>> parent(graph->getVerticesNum(), nullptr);
        queue.push(source);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();
            for (const std::shared_ptr<Edge>& edge : *(*adjacency)[current]) {
                if (!parent[edge->getDestination()] && edge->getDestination() != source && (edge->getCapacity() > edge->getFlow() || edge->getFlow() < 0)) {
                    parent[edge->getDestination()] = edge;
                    if (edge->getDestination() == sink) break;
                    queue.push(edge->getDestination());
                }
            }
        }

        if (!parent[sink]) return flow;

        int df = std::numeric_limits<int>::max();
        for (auto edge = parent[sink]; edge != nullptr; edge = parent[edge->getSource()])
            df = std::min(df, edge->getFlow() >= 0 ? edge->getCapacity() - edge->getFlow() : -edge->getFlow());

        for (auto edge = parent[sink]; edge != nullptr; edge = parent[edge->getSource()]) {
            edge->incrementFlow(df);
            edge->getReverse()->incrementFlow(-df);
        }
        flow += df;
        if (paths != NULL) (*paths)++;
    }

    return flow;
}