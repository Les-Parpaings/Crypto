/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** converter
*/

#include "uInt512.hpp"
#include <algorithm>

namespace PGP
{

uInt512 uInt512::fromHexLittleEndian(const std::string &other)
{
    uInt512 result;
    std::bitset<8> byte;
    std::string copy = other;
    std::reverse(copy.begin(), copy.end());
    for (auto it : copy) {
        byte = std::bitset<8>(it);
        result = result << 8;
        result = result + byte.to_ulong();
    }
    return result;
}

}
