#include"Driver.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    void CDriver::IGetNewCommand(const std::string& PModule , std::uintmax_t PIndentation)
    {
        for(std::uintmax_t LIndent{0} ; LIndent < PIndentation ; LIndent++)
        {
            std::cout << " ";
        }
        std::cout << PModule << " << ";
        std::getline(std::cin , FCommand);
    }

    void CDriver::ISetNewCommand(const std::string& PModule , std::uintmax_t PIndentation)
    {
        for(std::uintmax_t LIndent{0} ; LIndent < PIndentation ; LIndent++)
        {
            std::cout << "    ";
        }
        std::cout << PModule << " >> ";
    }

    bool CDriver::IReturn()
    {
        return(FCommand == "Return");
    }

    bool CDriver::IContinue()
    {
        return(FCommand == "Continue");
    }
}