/*
** EPITECH PROJECT, 2022
** my
** File description:
** src/main.c
*/

#include "Args.hpp"
#include "PGP.hpp"
#include <stdexcept>

int main(int argc, char* argv[]) {

    PGP::Args args;
    try {
        args.parse(argv);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    if (args.getHelp()) {
        args.printHelp();
        return 0;
    }
    std::string message = readMessage(std::cin);
    return 0;
}
