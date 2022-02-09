/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** WarpSystem
*/

#include <iostream>
#include <ostream>
#include <string>
#include "WarpSystem.hpp"
#include "Federation.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
    
}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
    _coreReactor = coreReactor;
}

WarpSystem::Core::~Core()
{
    
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (_coreReactor);
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    _stability = stability;
}