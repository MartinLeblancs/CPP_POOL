/*
** EPITECH PROJECT, 2022
** ex01
** File description:
** convert_temp
*/

#include <iostream>
#include <iomanip>
#include <string.h>

void convert_temp(float number, const char *str)
{
    float result = 0;
    if (strcmp(str, "Fahrenheit") == 10)
        result = 5.0 / 9.0 * (number - 32);
    else if (strcmp(str, "Celsius") == 10)
        result = number * 9.0 / 5.0 + 32.0;
    
    std::cout << std::setw(16) << std::fixed << std::setprecision(3) << result;
    if (strcmp(str, "Fahrenheit") == 10)
        std::cout << std::setw(16) << "Celsius" << std::endl;
    if (strcmp(str, "Celsius") == 10)
        std::cout << std::setw(16) << "Fahrenheit" << std::endl;
}

int main(void)
{
    std::string str;
    float Number = 0;

    std::getline(std::cin, str, ' ');
    Number = ::atof(str.c_str());
    std::getline(std::cin, str, ' ');
    convert_temp(Number, str.c_str());

    return (0);
}