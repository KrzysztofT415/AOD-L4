#ifndef EDGE_HPP
#define EDGE_HPP


class Edge {
private:
    int _source;
    int _destination;
    int _capacity;
    int _flow;
    std::shared_ptr<Edge> _reverse;
    bool _isOriginal;
public:
    Edge(const int &source, const int &destination, const int &capacity, bool isOriginal = true)
            : _source(source), _destination(destination), _capacity(capacity), _flow(0), _reverse(nullptr), _isOriginal(isOriginal) {}
    int getSource() const { return _source; }
    int getDestination() const { return _destination; }
    int getCapacity() const { return _capacity; }
    int getFlow() const { return _flow; }
    void setReverse(std::shared_ptr<Edge> reverse) { _reverse = reverse; }
    std::shared_ptr<Edge> getReverse() { return _reverse; }
    void incrementFlow(int change) { _flow += change; }
    bool isOriginal() { return _isOriginal; }
};


#endif //EDGE_HPP
