/*
** EPITECH PROJECT, 2022
** COmmand
** File description:
** Command
*/

#include "Command.hpp"

void Command::registerCommand (const std::string &name, const std::function <void ()> &function)
{
    auto item = _map.find(name);
    if (item != _map.end())
        throw Error("Already registered command");
    _map[name] = function;
}

void Command::executeCommand(const std::string &name)
{
    auto item = _map.find(name);
    if (!(item != _map.end()))
        throw Error("Unknow command");

}