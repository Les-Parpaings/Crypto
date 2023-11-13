/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** constructor
*/

#include "uInt512.hpp"
#include <iostream>

namespace PGP
{

uInt512::uInt512()
{
    _bits = std::bitset<512>(0);
}

uInt512::~uInt512()
{

}

uInt512::uInt512(const uInt512& other)
{
    _bits = other._bits;
}

uInt512::uInt512(const std::string &other)
{
    _bits = std::bitset<512>(other);
}

uInt512::uInt512(const int &other)
{
    _bits = std::bitset<512>(other);
}

uInt512::uInt512(const char *other)
{
    std::string tmp(other);
    _bits = std::bitset<512>(tmp);
}

}
