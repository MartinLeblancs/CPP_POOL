/*
** EPITECH PROJECT, 2022
** day7AM
** File description:
** WarpSystem
*/

#ifndef __WARPSYSTEM__
#define __WARPSYSTEM__

#include <string>

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable();
            void setStability(bool stability);
        private:
            bool _stability;
    };
    class Core
    {
        public:
        Core(QuantumReactor *coreReactor);
        ~Core();
        QuantumReactor *checkReactor();
        private:
        QuantumReactor *_coreReactor;
    };
}

#endif