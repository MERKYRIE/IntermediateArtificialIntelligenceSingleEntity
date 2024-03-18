#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    class CLinker
    {
        friend class CDriver;
        
        private : std::array<std::array<std::uintmax_t , 26> , 26> FRoutes;

        private : void IWrite();
        private : void IRead();
        
        private : void ARun();

        public : std::array<std::array<std::uintmax_t , 26> , 26> ORoutes();
    };
}