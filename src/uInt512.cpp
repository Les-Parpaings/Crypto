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

uInt512::uInt512()
{
    _bits = std::bitset<512>(0);
}

uInt512::uInt512(const int value)
{
    _bits = value;
}

uInt512::uInt512(const uInt512& other)
{
    _bits = other._bits;
}

uInt512::~uInt512()
{
}

uInt512 uInt512::operator+(const uInt512& other)
{
    bool carry = false;
    bool a = false;
    uInt512 res;

    res = 0;
    for (int i = 0; i < 512; i++) {
        a = _bits[i];
        res._bits[i] = a ^ other._bits[i] ^ carry;
        carry = (a & other._bits[i]) | (carry & (a ^ other._bits[i]));
    }
    return res;
}

uInt512 uInt512::operator+(const int& other)
{
    uInt512 res;
    uInt512 tmp;
    tmp = other;
    res = other;
    res = *this + tmp;
    return res;
}

uInt512 uInt512::operator-(const uInt512& other)
{
    uInt512 res;
    bool borrow = false;

    for (int i = 0; i < 512; ++i) {
        bool bit1 = _bits[i];
        bool bit2 = other._bits[i];

        bool diff = bit1 ^ bit2 ^ borrow;

        borrow = (!bit1 & bit2) | ((!bit1 | bit2) & borrow);

        res._bits[i] = diff;
    }

    return res;
}

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

std::ostream &operator<<(std::ostream &out, const uInt512 &other)
{
    out << other._bits.to_string();
    return out;
}

uInt512 uInt512::operator<<(const int& other)
{
    uInt512 res;
    res = *this;
    res._bits = res._bits << other;
    return res;
}

uInt512 uInt512::operator>>(const int& other)
{
    uInt512 res;
    res = *this;
    res._bits = res._bits >> other;
    return res;
}

uInt512 uInt512::operator*(const uInt512& other)
{
    uInt512 res;
    uInt512 tmp;

    for (int i = 0; i < 512; i++) {
        if (other._bits[i]) {
            tmp = *this;
            tmp = tmp << i;
            res = res + tmp;
        }
    }
    return res;
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
    for (int i = 0; i < 512; ++i) {
        if (_bits[i] != other._bits[i]) {
            return (other._bits[i] < _bits[i]);
        }
    }
    return false;
}

bool uInt512::operator>(const uInt512& other) const
{
    for (int i = 0; i < 512; ++i) {
        if (_bits[i] != other._bits[i]) {
            return (other._bits[i] > _bits[i]);
        }
    }
    return false;
}

bool uInt512::operator<=(const uInt512& other) const
{
    for (int i = 0; i < 512; ++i) {
        if (_bits[i] != other._bits[i]) {
            return (other._bits[i] < _bits[i]);
        }
    }
    return true;
}

bool uInt512::operator>=(const uInt512& other) const
{
    for (int i = 0; i < 512; ++i) {
        if (_bits[i] != other._bits[i]) {
            return (other._bits[i] > _bits[i]);
        }
    }
    return true;
}

uInt512 uInt512::operator/(const uInt512& other)
{
    if (other._bits.none()) {
        throw std::runtime_error("Division by zero");
    }

    uInt512 quotient = 0;
    uInt512 remainder = *this;

    std::cout << "panic: " << remainder << std::endl;

    for (int i = 0; i < 512; i++) {
        if (remainder >= other) {
            std::cout << "before: " << remainder << std::endl;
            remainder = remainder - other;
            std::cout << "after: " << remainder << std::endl;
            quotient = quotient + 1;
        }
    }

    return quotient;
}

}
