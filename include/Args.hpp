/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Args
*/

#include "enum.hpp"

#pragma once

namespace PGP
{

class Args {
    public:
        Args();
        ~Args();

        void parse(char* argv[]);

        Mode::Mode getMode() const { return _mode; }
        Algorithm::Algorithm getAlgorithm() const { return _algorithm; }
        bool getHelp() const { return _help; }

        void printHelp() const;

    protected:
    private:
        Mode::Mode _mode;
        Algorithm::Algorithm _algorithm;
        bool _help;

};

} // namespace PGP
