/*
** EPITECH PROJECT, 2022
** test_buzz.cpp
** File description:
** test_buzz.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../Buzz.hpp"

Test(toy, function_buzz_ctor_with_one_argument)
{
    Buzz buzz("TOTO");

    cr_assert(buzz.getName() == "TOTO");
    cr_assert(buzz.getType() == Toy::BUZZ);
    std::string file = "tests/buzz.txt";

    std::ifstream inFile;
    std::stringstream strStream;
    inFile.open(file);
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    inFile.close();
    cr_assert(buzz.getAscii() == "");
    std::fflush(stdout);
}