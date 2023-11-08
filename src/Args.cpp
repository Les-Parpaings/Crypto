/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "Args.hpp"
#include <iostream>
#include <stdexcept>

namespace PGP
{

Args::Args()
{
    _mode = Mode::NONE;
    _algorithm = Algorithm::NONE;
    _help = false;
}

Args::~Args()
{

}

void Args::parse(char* argv[])
{
    for (int i = 0; argv[i] != NULL; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            _help = true;
            return;
        }
        if (arg == "-xor" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::XOR;
        }
        if (arg == "-rsa" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::RSA;
        }
        if (arg == "-aes" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::AES;
        }
        if (arg == "-c" && _mode == Mode::Mode::NONE) {
            _mode = Mode::ENCRYPT;
        }
        if (arg == "-d" && _mode == Mode::Mode::NONE) {
            _mode = Mode::DECRYPT;
        }
    }
    if (_help)
        return;
    if (_mode == Mode::NONE || _algorithm == Algorithm::NONE)
        throw std::runtime_error("Invalid arguments");
}

void Args::printHelp() const
{
    std::cout << "USAGE:\n";
    std::cout << "\t./mypgp [-xor | -aes | -rsa] [-c | -d] [-b] KEY\n";
    std::cout << "\tThe MESSAGE is read from standard input.\n";
    std::cout << "DESCRIPTION:\n";
    std::cout << "\t-xor\tcomputation using XOR algorithm\n";
    std::cout << "\t-aes\tcomputation using AES algorithm\n";
    std::cout << "\t-rsa\tcomputation using RSA algorithm\n";
    std::cout << "\t-c\tMESSAGE is clear and we want to cipher it\n";
    std::cout << "\t-d\tMESSAGE is ciphered and we want to decipher it\n";
    std::cout << "\t-b\tblock mode: for xor and aes, only works on one block\n";
    std::cout << "\t\tMESSAGE and KEY must be of the same size\n";
    std::cout << "\t-g P Q\tfor RSA only: generate a public and private key\n";
    std::cout << "\t\tpair from the prime number P and Q\n";
}

} // namespace PGP
