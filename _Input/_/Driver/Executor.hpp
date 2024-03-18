#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    class CExecutor
    {
        friend class CDriver;

        private : std::uintmax_t FDeparture;
        private : std::uintmax_t FArrival;

        private : void IWrite();
        private : void IRead();

        private : void ARun();

        public : std::uintmax_t ODeparture();
        public : std::uintmax_t OArrival();
    };
}