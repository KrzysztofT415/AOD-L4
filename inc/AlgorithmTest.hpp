#ifndef ALGORITHMTEST_HPP
#define ALGORITHMTEST_HPP


#include<Algorithm.hpp>

class AlgorithmTest {
    public:
        static void testAlgorithm(std::tuple<int, bool, bool, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name);
        static void testAlgorithm(std::tuple<int, bool, bool, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name, int repeats);
};


#endif //ALGORITHMTEST_HPP
