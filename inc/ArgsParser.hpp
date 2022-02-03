#ifndef ARGSPARSER_HPP
#define ARGSPARSER_HPP

#include <memory>
#include <iostream>
#include <string.h>

class ArgsParser {
public:
    static std::shared_ptr<std::tuple<int, bool, bool, std::string>> parseArgs(int argc, char** argv) {
        bool printFlow = false;
        int size = 0;
        std::string file = "";
        for (int i = 0; i < argc; ++i) {
            if (strcmp(argv[i], "--size") == 0) size = std::atoi(argv[++i]);
            if (strcmp(argv[i], "--printFlow") == 0) printFlow = true;
            if (strcmp(argv[i], "--glpk") == 0) file = argv[i + 1];
        }
        if (size < 1 || size > 16) return nullptr;
        return std::make_shared<std::tuple<int, bool, bool, std::string>>(size, printFlow, file != "", file);
    }
};


#endif //ARGSPARSER_HPP
