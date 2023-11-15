/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** readMessage
*/

#include <iostream>

namespace PGP
{

std::string readMessage(std::istream& stream)
{
    std::string message;
    std::string line;

    while (std::getline(stream, line)) {
        message += line;
    }
    return message;
}

} // namespace PGP