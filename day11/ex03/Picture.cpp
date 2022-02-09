/*
** EPITECH PROJECT, 2022
** Picture
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture()
{
    data = "";
}

Picture::Picture(const Picture &picture)
{
    data = picture.data;
}

Picture &Picture::operator=(const Picture &picture)
{
    data = picture.data;

    return (*this);
}

Picture::~Picture()
{
}

Picture::Picture(const std::string &file)
{
    std::ifstream the_file(file.c_str());
    std::string str;
    if (the_file.is_open()) {
        while (getline(the_file, str, '\0'))
            data += str;
    }
    else
        data = "ERROR";
    the_file.close();
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream the_file(file.c_str());
    std::string str;
    if (the_file.is_open()) {
        while (std::getline(the_file, str, '\0')) {
            data += str;
        }
    }
    else {
        return (false);
    }
    the_file.close();
    return (true);
}