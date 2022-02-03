#include <ArgsParser.hpp>
#include <AlgorithmTest.hpp>
#include <EdmondsKarp.hpp>
#include <Dinic.hpp>
#include <iostream>

int main(void) {
    srand(time(0));
    int rep = 20;
    for (int i = 1; i <= 1; ++i) {
        auto config = std::make_shared<std::tuple<int, bool, bool, std::string>>(16, false, false, "");
        AlgorithmTest::testAlgorithm(*config, EdmondsKarp(), "EdmondsKarp", rep);
        AlgorithmTest::testAlgorithm(*config, Dinic(), "Dinic", rep);
    }

    auto config = std::make_shared<std::tuple<int, bool, bool, std::string>>(5, true, true, "./out/edmonds.json");
    AlgorithmTest::testAlgorithm(*config, EdmondsKarp(), "EdmondsKarp");
    auto config2 = std::make_shared<std::tuple<int, bool, bool, std::string>>(5, true, true, "./out/dynic.json");
    AlgorithmTest::testAlgorithm(*config2, Dinic(), "Dinic");
    return 0;
}