/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** PGP
*/

#pragma once

#include <iostream>
#include <array>

#include "enum.hpp"
#include "Args.hpp"

namespace PGP
{
    class PGP {
        public:
            PGP();
            ~PGP();

            std::string run(std::string message, Args options);

            std::string my_xor(std::string message, Args options);
            std::string xor_decrypt(std::string message, Args options);

            std::string rsa(std::string message, Args options);
            std::string rsa_decrypt(std::string message, Args options);

            std::string aes(std::string message, Args options);
            std::string aes_decrypt(std::string message, Args options);

            std::string pgp(std::string message, Args options);
            std::string pgp_decrypt(std::string message, Args options);

            std::string toHex(std::string message);

            typedef std::string (PGP::PGP::*FuncPGP)(std::string, Args);

        private:
            std::array<FuncPGP, Algorithm::SIZE> _encrypt;
            std::array<FuncPGP, Algorithm::SIZE> _decrypt;
    };

    std::string readMessage(std::istream& stream);
    std::string parseMessage(std::string message);
}
