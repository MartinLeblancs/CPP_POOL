/*
** EPITECH PROJECT, 2022
** ex00
** File description:
** cat.cpp
*/

#include <iostream>
#include <fstream>

void cat(char *file_name)
{
    std::ifstream file(file_name);
    std::string str;
    if (file.is_open()) {
        while (std::getline(file, str))
            std::cout << str << '\n';
    }
    else 
        std::cerr << "my_cat: " << file_name << ": No such file or directory" << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 1)
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    for (int i = 1; av[i] != NULL; i++) {
        cat(av[i]);
    }
}

