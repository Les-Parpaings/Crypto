/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "Args.hpp"

#include <iostream>
#include <fstream>
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
    std::ifstream file(PATH_HELP);
    std::string buffer;

    while (std::getline(file, buffer)) {
        std::cout << buffer << std::endl;
    }
}

} // namespace PGP
