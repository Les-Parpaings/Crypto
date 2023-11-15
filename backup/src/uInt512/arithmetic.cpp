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

uInt512 uInt512::operator-(const int& other)
{
    uInt512 tmp = other;
    uInt512 res = *this - tmp;
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

static int topBitSet(const std::bitset<512> &a) {
    int i;
    for (i = 511; i >= 0; i--) {
        if (a.test(i)) {
            break;
        }
    }
    return i;
}

static std::bitset<512> gf2Sub(std::bitset<512> a, std::bitset<512> b)
{
    std::bitset<512> res;
    bool borrow = false;

    for (int i = 0; i < 512; i++) {
        bool bit1 = a[i];
        bool bit2 = b[i];

        bool diff = bit1 ^ bit2 ^ borrow;

        borrow = (!bit1 & bit2) | ((!bit1 | bit2) & borrow);

        res[i] = diff;
    }

    return res;
}

static bool gf2IsLower(const std::bitset<512> &a, const std::bitset<512> &b)
{
    for (int i = 511; i >= 0; i--) {
        if (a[i] != b[i]) {
            return (a[i] < b[i]);
        }
    }
    return false;
}

static std::bitset<512> gf2Div(std::bitset<512> dividend, std::bitset<512> divisor, std::bitset<512> &remainder) {
    std::bitset<512> quotient(0);
    int divisorSize = topBitSet(divisor);

    if (divisorSize < 0) {
        throw std::runtime_error("Division by zero");
    }
    int bit;
    while ((bit = topBitSet(dividend)) >= divisorSize) {
        if (gf2IsLower(dividend, (divisor << (bit - divisorSize)))) {
            if (bit == divisorSize) {
                break;
            }
            bit--;
        }
        quotient.set(bit - divisorSize);
        dividend = gf2Sub(dividend, (divisor << (bit - divisorSize)));
    }
    remainder = dividend;
    return quotient;
}

uInt512 uInt512::operator/(const uInt512& other)
{
    uInt512 res;
    uInt512 remainder;
    res._bits = gf2Div(_bits, other._bits, remainder._bits);
    return res;
}

uInt512 uInt512::operator%(const uInt512& other)
{
    uInt512 remainder;
    gf2Div(_bits, other._bits, remainder._bits);
    return remainder;
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

}
