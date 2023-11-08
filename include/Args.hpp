/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "enum.hpp"
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
        std::string getKey() const { return _key; }

        void printHelp() const;

    protected:
    private:
        Mode::Mode _mode;
        Algorithm::Algorithm _algorithm;
        bool _help;
        bool _block;
        std::string _key;
};

} // namespace PGP
