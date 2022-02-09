/*
** EPITECH PROJECT, 2022
** test_toy.cpp
** File description:
** test_toy.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "../Toy.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(toy, functions_toy_ctor_without_arguments, .init = redirect_all_stdout)
{
    Toy toy;

    cr_assert(toy.getType() == Toy::BASIC_TOY);
    cr_assert(toy.getName() == "toy");
    cr_assert(toy.getAscii() == "");
    toy.speak("Bonjour !");
    std::cout << toy;
    toy << "\\o/";
    std::cout << toy;
    std::fflush(stdout);
    cr_assert_stdout_eq_str("toy \"Bonjour !\"\ntoy\n\ntoy\n\\o/\n");
}

Test(toy, functions_toy_ctor_with_arguments)
{
    std::string file = "tests/alien.txt";
    Toy simple_toy(Toy::BASIC_TOY, "TOTO", file);

    std::ifstream inFile;
    std::stringstream strStream;
    inFile.open(file);
    strStream << inFile.rdbuf();
    std::string str = strStream.str();
    inFile.close();

    cr_assert(simple_toy.getName() == "TOTO");
    cr_assert(simple_toy.getType() == Toy::BASIC_TOY);
    cr_assert(simple_toy.getAscii() == str);

    simple_toy.setName("TATA");
    file = "tests/bo_beep.txt";
    simple_toy.setAscii(file);

    inFile.open(file);
    strStream << inFile.rdbuf();
    str = "";
    str += strStream.str();

    cr_assert(simple_toy.getName() == "TATA");
    cr_assert(simple_toy.getAscii() == str);
}