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

static uInt512 calculateE(uInt512 phi)
{
    uInt512 e = 2;
    while (GCD(e, phi) != 1) {
        e = e + 1;
    }
    if (e >= phi)
        throw std::runtime_error("Error: e > phi");
    return e;
}

static uInt512 calculateD(uInt512 e, uInt512 n)
{
    uInt512 k = 1;

    while (((k * n) +1) % e != 0) {
        k = k + 1;
    }
    uInt512 d = ((k * n) + 1) / e;
    return d;
}

static std::pair<std::string, std::string> rsaKeyGen(std::string message, Args options)
{
    uInt512 n = options.getP() * options.getQ();
    uInt512 phi = (options.getP() - 1) * (options.getQ() - 1);
    uInt512 lambda = phi / GCD(options.getP() - 1, options.getQ() - 1);
    uInt512 e = calculateE(phi);
    uInt512 d, y;
    std::pair<std::string, std::string> res;

    GCDExtended(e, lambda, d, y);
    if (GCD(e, lambda) != 1) {
        throw std::runtime_error("Error: lambda and e are not coprime");
    }
    if (d * e % lambda != 1) {
        throw std::runtime_error("Error: d * e % lambda != 1");
    }
    res.first = e.toHexLittleEndian();
    res.first += "-";
    res.first += n.toHexLittleEndian();
    res.second = d.toHexLittleEndian();
    res.second += "-";
    res.second += n.toHexLittleEndian();
    return res;
}

std::string PGP::rsa(std::string message, Args options)
{
    if (options.getMode() == Mode::GEN_RSA_KEY) {
        std::pair<std::string, std::string> res = rsaKeyGen(message, options);
        return "Public key: " + res.first + "\nPrivate key: " + res.second;
    }
    return std::string("todo");
}

std::string PGP::rsa_decrypt(std::string message, Args options)
{
    return std::string("todo");
}

}
