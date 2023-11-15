/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** u_int512
*/

#pragma once

#include <bitset>

namespace PGP
{

    class uInt512
    {
        public:
            uInt512();
            uInt512(const uInt512& other);
            uInt512(const std::bitset<512> &other);
            uInt512(const std::string &other);
            uInt512(const char *other);
            uInt512(const int &other);
            ~uInt512();

            static uInt512 fromHexLittleEndian(const std::string &other);
            static uInt512 fromHex(const std::string &other);
            std::string toHex() const;
            std::string toHexLittleEndian() const;

            uInt512 operator+(const uInt512& other);
            uInt512 operator+(const int& other);
            uInt512 operator-(const uInt512& other);
            uInt512 operator-(const int& other);
            uInt512 operator*(const uInt512& other);
            uInt512 operator/(const uInt512& other);
            uInt512 operator%(const uInt512& other);

            uInt512 operator<<(const int& other);
            uInt512 operator>>(const int& other);

            uInt512 &operator=(const uInt512& other);
            uInt512 &operator=(const std::bitset<512> &other);
            uInt512 &operator=(const std::string &other);
            uInt512 &operator=(const int &other);

            bool operator==(const uInt512& other) const;
            bool operator!=(const uInt512& other) const;
            bool operator<(const uInt512& other) const;
            bool operator>(const uInt512& other) const;
            bool operator<=(const uInt512& other) const;
            bool operator>=(const uInt512& other) const;

            friend std::ostream & operator<<(std::ostream &out, const uInt512 &other);
        private:
            std::bitset<512> _bits;
    };

}
