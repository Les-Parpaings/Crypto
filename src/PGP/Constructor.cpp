/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Constructor
*/

#include "PGP.hpp"
#include <sstream>

namespace PGP
{

PGP::PGP()
{
    _encrypt[Algorithm::XOR] = &PGP::my_xor;
    _encrypt[Algorithm::RSA] = &PGP::rsa;
    _encrypt[Algorithm::AES] = &PGP::aes;
    _decrypt[Algorithm::XOR] = &PGP::xor_decrypt;
    _decrypt[Algorithm::RSA] = &PGP::rsa_decrypt;
    _decrypt[Algorithm::AES] = &PGP::aes_decrypt;
}

PGP::~PGP()
{

}

std::string PGP::run(std::string message, Args options)
{
    if (options.getMode() == Mode::ENCRYPT)
        return (this->*_encrypt[options.getAlgorithm()])(message, options);
    return (this->*_decrypt[options.getAlgorithm()])(message, options);
}

std::string PGP::toHex(std::string message)
{
    std::string result;
    std::stringstream stream;

    for (std::size_t i = 0; i < message.size(); i++) {
        stream << std::hex << (int)message[i];
        if (message[i] == 0) {
            stream << "0";
        }
        result += stream.str();
        stream.str("");
    }
    return result;
}

} // namespace PGP
