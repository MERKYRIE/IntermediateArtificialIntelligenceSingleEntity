#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    class CLoader
    {
        friend std::int32_t (::main());

        private : std::uintmax_t FCost;
        private : std::uintmax_t FLength;
        private : std::uintmax_t FCurrent;
        private : std::vector<std::uintmax_t> FArrivals;

        private : void IRun();

        private : void ARun();
    };
}