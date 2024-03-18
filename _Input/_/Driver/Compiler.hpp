#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    class CCompiler
    {
        friend class CDriver;

        private : std::set<std::uintmax_t> FNodes;

        private : void IWrite();
        private : void IRead();

        private : void ARun();

        public : std::set<std::uintmax_t> ONodes();
    };
}