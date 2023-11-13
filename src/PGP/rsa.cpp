/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** rsa
*/

#include "PGP.hpp"

namespace PGP
{

static int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

static int GCDExtended(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = GCDExtended(b%a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

static std::string rsaKeyGen(std::string message, Args options)
{
    int n = options.getP() * options.getQ();
    int lambda = abs(n) / GCD(options.getP() - 1, options.getQ() - 1);
    int e = 3;
    int d, y;
    int gcdE = GCDExtended(e, lambda, d, y);
    std::cout << "n: " << n << std::endl;
    std::cout << "lambda: " << lambda << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "d: " << d << std::endl;
}

std::string PGP::rsa(std::string message, Args options)
{
    if (options.getMode() == Mode::GEN_RSA_KEY) {
        return rsaKeyGen(message, options);
    }
    return std::string("todo");
}

std::string PGP::rsa_decrypt(std::string message, Args options)
{
    return std::string("todo");
}

}
