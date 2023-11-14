/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** uInt512
*/

#include "uInt512.hpp"
#include <iostream>

namespace PGP
{

uInt512 &uInt512::operator=(const uInt512& other)
{
    _bits = other._bits;
    return *this;
}

uInt512 &uInt512::operator=(const std::string &other)
{
    _bits = std::bitset<512>(other);
    return *this;
}

uInt512 &uInt512::operator=(const int &other)
{
    _bits = std::bitset<512>(other);
    return *this;
}

uInt512 &uInt512::operator=(const std::bitset<512> &other)
{
    _bits = other;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const uInt512 &other)
{
    out << other._bits.to_string();
    return out;
}

bool uInt512::operator==(const uInt512& other) const
{
    return _bits == other._bits;
}

bool uInt512::operator!=(const uInt512& other) const
{
    return _bits != other._bits;
}

bool uInt512::operator<(const uInt512& other) const
{
    for (int i = 511; i >= 0; i--) {
        if (_bits[i] != other._bits[i]) {
            return (_bits[i] < other._bits[i]);
        }
    }
    return false;
}

bool uInt512::operator>(const uInt512& other) const
{
    for (int i = 511; i >= 0; i--) {
        if (_bits[i] != other._bits[i]) {
            return (_bits[i] > other._bits[i]);
        }
    }
    return false;
}

bool uInt512::operator<=(const uInt512& other) const
{
    for (int i = 511; i >= 0; i--) {
        if (_bits[i] != other._bits[i]) {
            return (_bits[i] < other._bits[i]);
        }
    }
    return true;
}

bool uInt512::operator>=(const uInt512& other) const
{
    for (int i = 511; i >= 0; i--) {
        if (_bits[i] != other._bits[i]) {
            return (_bits[i] > other._bits[i]);
        }
    }
    return true;
}

}
