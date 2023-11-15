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
    _encrypt[Algorithm::PGP] = &PGP::pgp;
    _decrypt[Algorithm::XOR] = &PGP::xor_decrypt;
    _decrypt[Algorithm::RSA] = &PGP::rsa_decrypt;
    _decrypt[Algorithm::AES] = &PGP::aes_decrypt;
    _decrypt[Algorithm::PGP] = &PGP::pgp_decrypt;
}

PGP::~PGP()
{

}

std::string PGP::run(std::string message, Args options)
{
    if (options.getMode() == Mode::ENCRYPT || options.getMode() == Mode::GEN_RSA_KEY)
        return (this->*_encrypt[options.getAlgorithm()])(message, options);
    return (this->*_decrypt[options.getAlgorithm()])(message, options);
}

std::string PGP::toHex(std::string message)
{
    std::string result;
    std::stringstream stream;

    for (std::size_t i = 0; i < message.size(); i++) {
        if (static_cast<unsigned int>(message[i]) < 16)
            stream << "0";
        std::bitset<8> x(message[i]);
        stream << std::hex << x.to_ulong();
        result += stream.str();
        stream.str("");
    }
    return result;
}

} // namespace PGP
