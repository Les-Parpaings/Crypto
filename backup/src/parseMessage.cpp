/*
** EPITECH PROJECT, 2023
** Crypto
** File description:
** parseMessage
*/

#include <iostream>
#include <array>

namespace PGP
{

std::string parseMessage(std::string message)
{
    std::string result = "";

    std::string byte;
    int i = 0;

    for (auto it : message) {
        byte += it;
        i++;
        if (i == 2) {
            result += std::stoi(byte, nullptr, 16);
            byte.clear();
            i = 0;
        }
    }
    return result;
}

}
