/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "enum.hpp"
#include "uInt512.hpp"
#include <string>

#pragma once

namespace PGP
{

class Args {
    public:
        Args();
        ~Args();

        void parse(int argc, char* argv[]);

        Mode::Mode getMode() const { return _mode; }
        Algorithm::Algorithm getAlgorithm() const { return _algorithm; }
        bool getHelp() const { return _help; }
        bool getBlock() const { return _block; }
        uInt512 getP() const { return _p; }
        uInt512 getQ() const { return _q; }
        void setP(uInt512 p) { _p = p; }
        void setQ(uInt512 q) { _q = q; }
        std::string getKey() const { return _key; }

        void printHelp() const;

    protected:
    private:
        Mode::Mode _mode;
        Algorithm::Algorithm _algorithm;
        bool _help;
        bool _block;
        uInt512 _p;
        uInt512 _q;
        std::string _key;
};

} // namespace PGP
