#include <ArgsParser.hpp>
#include <AlgorithmTest.hpp>
#include <Dinic.hpp>
#include <iostream>

int main(int argc, char** argv) {
    auto config = ArgsParser::parseArgs(argc, argv);
    if (!config) return 1;

    AlgorithmTest::testAlgorithm(*config, Dinic(), "Dinic");
    return 0;
}