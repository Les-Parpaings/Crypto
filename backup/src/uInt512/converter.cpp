/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** converter
*/

#include "uInt512.hpp"
#include "PGP.hpp"
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

uInt512 uInt512::fromHex(const std::string &other)
{
    uInt512 result;
    std::bitset<8> byte;
    std::string copy = other;

    for (auto it : copy) {
        byte = std::bitset<8>(it);
        result = result << 8;
        result = result + byte.to_ulong();
    }
    return result;
}

std::string uInt512::toHexLittleEndian() const
{
    std::string result;

    for (int i = 0; i < 512; i += 8) {
        result += std::bitset<8>(_bits.to_string().substr(i, 8)).to_ulong();
    }
    for (auto it = result.begin(); it != result.end(); ++it) {
        if (*it == '\0') {
            it = result.erase(it);
            it--;
            continue;
        }
        if (*it != '\0')
            break;
    }
    std::reverse(result.begin(), result.end());
    PGP p;
    result = p.toHex(result);
    return result;
}

std::string uInt512::toHex() const
{
    std::string result;

    for (int i = 0; i < 512; i += 8) {
        result += std::bitset<8>(_bits.to_string().substr(i, 8)).to_ulong();
    }
    for (auto it = result.begin(); it != result.end(); ++it) {
        if (*it == '\0') {
            it = result.erase(it);
            it--;
            continue;
        }
        if (*it != '\0')
            break;
    }
    PGP p;
    result = p.toHex(result);
    return result;
}

}
