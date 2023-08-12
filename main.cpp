#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

typedef std::string str;

std::vector<str> parse_command(const str& command) {
    std::istringstream iss(command);
    std::vector<std::string> parts;
    std::string part;

    while (iss >> part) { parts.push_back(part); }

    return parts;
}

int fs_run(str command) {
    if (command.find("+") != str::npos) {
        return std::stoi(parse_command(command)[1]) + std::stoi(parse_command(command)[2]);
    } else if (command.find("-") != str::npos) {
        return std::stoi(parse_command(command)[1]) - std::stoi(parse_command(command)[2]);
    } else if (command.find("&") != str::npos) {
        std::system(parse_command(command)[1].c_str());
        std::system(parse_command(command)[1].c_str());
    } else {
        return std::system(command.c_str());
    }
}

int main() {
    while (true) {
        std::cout << "Welcome To Freeshell Lite \n by mkukiro \n"
        std::cout << "\033[33m~> \033[0m";
        std::string command;
        std::getline(std::cin, command);
        std::cout << fs_run(command) << std::endl;
    }
    return 0;
}
