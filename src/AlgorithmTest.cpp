#include <AlgorithmTest.hpp>
#include <iostream>
#include <chrono>

void AlgorithmTest::testAlgorithm(std::tuple<int, bool, bool, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name, int repeats) {
    double flow = 0;
    double time = 0;
    double paths = 0;

    for (int i = 0; i < repeats; ++i) {
        auto graph = std::make_shared<Graph>();
        graph->generateHiperCube(std::get<0>(config));
        int path = 0;

        auto t1 = std::chrono::high_resolution_clock::now();
        int df = algorithm.findFlow(graph, 0, graph->getVerticesNum() - 1, &path);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        // std::cout << "\t ->" << df << "f " << duration << "us " << path << "p\n";
        // std::cout << "Flow matrix: \n";
        // auto adjacency = graph->getAdjacency();
        // for (auto &vertex : *adjacency) {
        //     for (auto &edge : *vertex) {
        //         if (edge->isOriginal())
        //             std::cout << "\t\t(" << edge->getSource() << "," << edge->getDestination() << ") = "
        //                 << edge->getFlow() << "/" << edge->getCapacity() << "\n";
        //     }
        // }

        time += duration;
        flow += df;
        paths += path;
    }

    std::cout << algorithm_name << " - k" << std::get<0>(config) << " : " << (flow / repeats) << "f " << (time / repeats) << "us " << (paths / repeats) << "p\n";
}

void AlgorithmTest::testAlgorithm(std::tuple<int, bool, bool, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name) {
    auto graph = std::make_shared<Graph>();
    graph->generateHiperCube(std::get<0>(config));
    int paths = 0;

    auto t1 = std::chrono::high_resolution_clock::now();
    int flow = algorithm.findFlow(graph, 0, graph->getVerticesNum() - 1, &paths);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

    std::cout << algorithm_name << " - k" << std::get<0>(config) << " : " << flow << "f\n";
    std::cerr << algorithm_name << " - k" << std::get<0>(config) << " : " << duration << "us " << paths << "p\n";

    if (std::get<1>(config)) {
        std::cout << "Flow matrix: \n";
        auto adjacency = graph->getAdjacency();
        for (auto &vertex : *adjacency) {
            for (auto &edge : *vertex) {
                if (edge->isOriginal())
                    std::cout << "(" << edge->getSource() << "," << edge->getDestination() << ") = "
                        << edge->getFlow() << "/" << edge->getCapacity() << "\n";
            }
        }
    }

    if (std::get<2>(config)) {
        auto adjacency = graph->getAdjacency();
        std::ofstream file(std::get<3>(config));
        file << "{\n    \"vertices\": " << graph->getVerticesNum() << ",\n    \"edges\": {\n";
        bool flag = false;
        for (auto &vertex : *adjacency) {
            for (auto &edge : *vertex) {
                if (edge->isOriginal()) {
                    if (flag) file << ",\n";
                    file << "        \"" << edge->getSource() + 1 << " -> " << edge->getDestination() + 1 << "\": " << edge->getCapacity();
                }
                flag = true;
            }
        }
        file << "\n    }\n}";
        file.close();
    }
}