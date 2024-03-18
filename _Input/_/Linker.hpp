#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    class CLinker
    {
        friend std::int32_t (::main());
        
        private : std::string FCommand;
        private : std::vector<std::vector<std::uintmax_t>> FRoutes;

        private : bool ARun();
    };
}