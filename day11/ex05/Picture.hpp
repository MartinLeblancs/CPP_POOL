/*
** EPITECH PROJECT, 2022
** Picture
** File description:
** Picture
*/

#ifndef __PICTURE__
#define __PICTURE__

#include <iostream>
#include <fstream>

class Picture
{
    public:
        Picture();
        Picture(const Picture &picture);
        ~Picture();
        Picture &operator=(const Picture &picture);
        Picture(const std::string &file);
        bool getPictureFromFile(const std::string &file);
        std::string data;

};

#endif