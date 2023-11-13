/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "Args.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

namespace PGP
{

Args::Args()
{
    _mode = Mode::NONE;
    _algorithm = Algorithm::NONE;
    _help = false;
    _block = false;
    _p = 0;
    _q = 0;
    _key = "";
}

Args::~Args()
{

}

void Args::parse(int argc, char* argv[])
{
    std::vector<std::string> args;

    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    for (auto it = args.begin(); it != args.end(); it++) {
        std::string arg = *it;
        if (arg == "-h" || arg == "--help") {
            _help = true;
            return;
        }
        if (arg == "-xor" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::XOR;
            it = args.erase(it).operator--();
        }
        if (arg == "-rsa" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::RSA;
            it = args.erase(it).operator--();
        }
        if (arg == "-aes" && _algorithm == Algorithm::Algorithm::NONE) {
            _algorithm = Algorithm::AES;
            it = args.erase(it).operator--();
        }
        if (arg == "-c" && _mode == Mode::Mode::NONE) {
            _mode = Mode::ENCRYPT;
            it = args.erase(it).operator--();
        }
        if (arg == "-d" && _mode == Mode::Mode::NONE) {
            _mode = Mode::DECRYPT;
            it = args.erase(it).operator--();
        }
        if (arg == "-b" && !_block) {
            _block = true;
            it = args.erase(it).operator--();
        }
        if (arg == "-g" && _mode == Mode::Mode::NONE) {
            _mode = Mode::GEN_RSA_KEY;
            it = args.erase(it).operator--();
        }
    }
    if (_help)
        return;
    if (_mode == Mode::NONE || _algorithm == Algorithm::NONE)
        throw std::runtime_error("Invalid arguments");
    if (_block && (_algorithm != Algorithm::XOR && _algorithm != Algorithm::AES))
        throw std::runtime_error("Invalid arguments");
    if (args.empty()) {
        throw std::runtime_error("Invalid arguments");
    }
    if (_mode == Mode::GEN_RSA_KEY && _algorithm != Algorithm::RSA) {
        throw std::runtime_error("Invalid arguments");
    }
    if (_mode == Mode::GEN_RSA_KEY) {
        if (args.size() < 2)
            throw std::runtime_error("Invalid arguments");
        return;
    }
    _key = args.front();
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
