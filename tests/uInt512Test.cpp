/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** uInt512Test
*/

#include <criterion/criterion.h>

#include "uInt512.hpp"

#include <iostream>

Test(uInt512, addition)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 3;

    cr_assert((a + b) == c);
}

Test(uInt512, addition2)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 2;

    cr_assert((a + b) == c);
}

Test(uInt512, addition3)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 1;

    cr_assert((a + b) == c);
}

Test(uInt512, addition4)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert((a + b) == c);
}

Test(uInt512, addition5)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 1;

    cr_assert((a + b) == c);
}

Test(uInt512, addition6)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 2;

    cr_assert((a + b) == c);
}

Test(uInt512, addition7)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 3;
    PGP::uInt512 c = 3;

    cr_assert((a + b) == c);
}

Test(uInt512, addition8)
{
    PGP::uInt512 a = 76839;
    PGP::uInt512 b = -893;
    PGP::uInt512 c = "10000000000000000000000000000000000000000000000010010100010101010";

    cr_assert((a + b) == c);
}

Test(uInt512, soustraction)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 3;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction2)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 2;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction3)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 1;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction4)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction5)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 1;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction6)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 2;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction7)
{
    PGP::uInt512 a = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    PGP::uInt512 b = 4;
    PGP::uInt512 c = 3;

    cr_assert((c - b) == a);
}

Test(uInt512, soustraction8)
{
    PGP::uInt512 a = 76839;
    PGP::uInt512 b = -893;
    PGP::uInt512 c = "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111110000000000000000000000000000000000000000000000010010111110100100";

    cr_assert((a - b) == c);
}

Test(uInt512, multiplication)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 2;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication2)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 1;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication3)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication4)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication5)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 0;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication6)
{
    PGP::uInt512 a = 9;
    PGP::uInt512 b = 9;
    PGP::uInt512 c = 81;

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication7)
{
    PGP::uInt512 a = 9;
    PGP::uInt512 b = -8;
    PGP::uInt512 c = "10001111111111111111111111111111111111111111111111111111111110111000";

    cr_assert((a * b) == c);
}

Test(uInt512, multiplication8)
{
    PGP::uInt512 a = "10101110101101101010000110111111111110101010000111";
    PGP::uInt512 b = "11110110010010000001000011000000001000111011100010100101011000101001010110001";
    PGP::uInt512 c = "1010100000010100101011100011101010000100010011000011011111100100100101001100100000000110101101001101110110001000110010101010111";

    cr_assert((a * b) == c);
}

Test(uInt512, division)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 2;

    cr_assert((c / b) == a);
}

Test(uInt512, division2)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 1;

    cr_assert((c / b) == a);
}

Test(uInt512, division3)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert_throw((c / b), std::runtime_error, "Division by zero");
}

Test(uInt512, division4)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert_throw((c / b), std::runtime_error, "Division by zero");
}

Test(uInt512, division5)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 0;

    cr_assert((c / b) == a);
}

Test(uInt512, division6)
{
    PGP::uInt512 a = 9;
    PGP::uInt512 b = 9;
    PGP::uInt512 c = 1;

    cr_assert((a / b) == c);
}

Test(uInt512, division7)
{
    PGP::uInt512 a = -8;
    PGP::uInt512 b = 9;
    PGP::uInt512 c = "1110001110001110001110001110001110001110001110001110001110001";

    cr_assert((a / b) == c);
}

Test(uInt512, division8)
{
    PGP::uInt512 a = "1010100000010100101011100011101010000100010011000011011111100100100101001100100000000110101101001101110110001000110010101010111";
    PGP::uInt512 b = "11110110010010000001000011000000001000111011100010100101011000101001010110001";
    PGP::uInt512 c = "111101010100010100010110010111111101001011111000001";

    cr_assert((a / b) == c);
}

Test(uInt512, modulo)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 2;
    PGP::uInt512 c = 2;

    cr_assert((c % b) == a);
}

Test(uInt512, modulo2)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 1;

    cr_assert((c % b) == a);
}

Test(uInt512, modulo3)
{
    PGP::uInt512 a = 1;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert_throw((c % b), std::runtime_error, "Division by zero");
}

Test(uInt512, modulo4)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 0;
    PGP::uInt512 c = 0;

    cr_assert_throw((c % b), std::runtime_error, "Division by zero");
}

Test(uInt512, modulo5)
{
    PGP::uInt512 a = 0;
    PGP::uInt512 b = 1;
    PGP::uInt512 c = 0;

    cr_assert((c % b) == a);
}

Test(uInt512, modulo6)
{
    PGP::uInt512 a = 9;
    PGP::uInt512 b = 9;
    PGP::uInt512 c = 0;

    cr_assert((a % b) == c);
}

Test(uInt512, modulo7)
{
    PGP::uInt512 a = -8;
    PGP::uInt512 b = 9;
    PGP::uInt512 c = 1;

    cr_assert((a % b) == c);
}

Test(uInt512, modulo8)
{
    PGP::uInt512 a = "1010100000010100101011100011101010000100010011000011011111100100100101001100100000000110101101001101110110001000110010101010111";
    PGP::uInt512 b = "11110110010010000001000011000000001000111011100010100101011000101001010110001";
    PGP::uInt512 c = "111011000000011111000101001010101001100000010001111010001010100010000100110";

    cr_assert((a % b) == c);
}
