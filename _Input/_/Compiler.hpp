#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    class CCompiler
    {
        friend std::int32_t (::main());

        private : std::set<char> FNodes;

        private : void IWrite();
        private : void IRead();

        private : bool ARun();
    };
}