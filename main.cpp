#include <iostream>
#include <cstdlib>

int main() {
    while (true) {
        std::cout << "\033[33m~> \033[0m";
        std::string command;
        std::getline(std::cin, command);
        std::cout << std::system(command.c_str()) << std::endl;
    }
    return 0;
}

// Notes: It's currently just a useless REPL and not a shell yet