/*
** EPITECH PROJECT, 2022
** my
** File description:
** src/main.c
*/

#include "Args.hpp"
#include "PGP.hpp"
#include "uInt512.hpp"
#include <stdexcept>

int main(int argc, char* argv[])
{
    PGP::Args args;

    try {
        args.parse(argc, argv);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    if (args.getHelp()) {
        args.printHelp();
        return 0;
    }

    std::string message = PGP::readMessage(std::cin);
    message = PGP::parseMessage(message);
    PGP::PGP pgp;
    std::cout << pgp.run(message, args) << std::endl;
    return 0;
}
