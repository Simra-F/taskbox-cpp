#include <iostream>
#include <string>
#include <vector>

#include "commands.h"
#include "storage.h"

int main(int argc, char** argv) {
    if (argc < 2 || COMMANDS.find(argv[1]) == COMMANDS.end()) {
        std::cerr << "usage: taskbox <add|list|clear> [args...]\n";
        return 2;
    }
    std::vector<std::string> rest(argv + 2, argv + argc);
    return COMMANDS.at(argv[1])(rest, STORAGE_PATH);
}
