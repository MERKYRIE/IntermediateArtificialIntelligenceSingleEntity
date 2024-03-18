#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    class CDriver
    {
        friend std::int32_t (::main());

        private : std::string FCommand;

        private : void IGetNewCommand(const std::string& PModule , std::uintmax_t PIndentation = 0);
        private : void ISetNewCommand(const std::string& PModule , std::uintmax_t PIndentation = 0);
        private : bool IReturn();
        private : bool IContinue();
    };
}