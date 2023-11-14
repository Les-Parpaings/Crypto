/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** rsa
*/

#include "PGP.hpp"
#include "uInt512.hpp"

namespace PGP
{

static uInt512 GCD(uInt512 a, uInt512 b)
{
    if (b == 0)
        return a;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a % b: " << a % b << std::endl;
    return GCD(b, a % b);
}

static int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

static uInt512 GCDExtended(uInt512 a, uInt512 b, uInt512 &x, uInt512 &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    uInt512 x1, y1;
    uInt512 gcd = GCDExtended(b%a, a, x1, y1);

    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

static std::string rsaKeyGen(std::string message, Args options)
{
    std::cout << "q: " << options.getQ() << std::endl;
    std::cout << "p: " << options.getP() << std::endl;
    uInt512 n = options.getP() * options.getQ();
    std::cout << "GCD: " << GCD(options.getP() - 1, options.getQ() - 1) << std::endl;
    uInt512 lambda = n / GCD(options.getP() - 1, options.getQ() - 1);
    uInt512 e = 3;
    uInt512 d, y;
    uInt512 gcdE = GCDExtended(e, lambda, d, y);
    std::cout << "n: " << n << std::endl;
    std::cout << "lambda: " << lambda << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "d: " << d << std::endl;
    return std::string("todo");
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
