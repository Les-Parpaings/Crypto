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
    size_t size = message.size();

    if (options.getBlock()) {
        size = key.size();
    }
    for (size_t i = 0; i < size; i++) {
        result += message[i] ^ key[i % key.size()];
    }
    return toHex(result);
}

std::string PGP::xor_decrypt(std::string message, Args options)
{
    return my_xor(message, options);
}

}
