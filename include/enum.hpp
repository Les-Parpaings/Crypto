/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** Mode
*/

#pragma once

namespace PGP
{
    namespace Algorithm {
        enum Algorithm {
            NONE = -1,
            XOR,
            RSA,
            AES,
        };
    }

    namespace Mode {
        enum Mode {
            NONE = -1,
            ENCRYPT,
            DECRYPT,
        };
    }
} // namespace PGP
