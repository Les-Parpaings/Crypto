/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** xor
*/

#include "PGP.hpp"

namespace PGP
{

std::string PGP::my_xor(std::string message, Args options)
{
    std::string result;
    std::string key = options.getKey();
    key = parseMessage(key);
    int size = message.size();

    if (options.getBlock()) {
        size = key.size();
    }
    for (std::size_t i = 0; i < size; i++) {
        result += message[i] ^ key[i % (key.size() - 1)];
    }
    return toHex(result);
}

std::string PGP::xor_decrypt(std::string message, Args options)
{
    return std::string("todo");
}

}
