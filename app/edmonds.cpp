#include <ArgsParser.hpp>
#include <AlgorithmTest.hpp>
#include <EdmondsKarp.hpp>
#include <iostream>

int main(int argc, char** argv) {
    auto config = ArgsParser::parseArgs(argc, argv);
    if (!config) return 1;

    AlgorithmTest::testAlgorithm(*config, EdmondsKarp(), "EdmondsKarp");
    return 0;
}