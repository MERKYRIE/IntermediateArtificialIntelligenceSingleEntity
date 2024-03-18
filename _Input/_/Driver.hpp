#pragma once

#include"Intermediate Artificial Intelligence Single Entity.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    class CDriver
    {
        friend std::int32_t (::main());

        private : std::string FModule;
        private : std::string FCommand;

        private : bool ARun();

        public : void OGetNewCommand(std::uintmax_t PIndentation);
        public : void OSetNewCommand(std::uintmax_t PIndentation);
        public : std::string OCommand();
        public : void OCommand(std::string PCommand);
        public : bool OReturn();
        public : bool OContinue();
        public : bool OBreak();
    };
}