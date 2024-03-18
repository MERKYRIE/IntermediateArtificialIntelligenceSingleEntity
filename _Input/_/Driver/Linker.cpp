#include"Linker.hpp"

#include"Driver.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    void CLinker::IWrite()
    {
        if(GDriver->OCommand() == "Write")
        {
            GDriver->OGetNewCommand(1);
            if(GDriver->OBreak())
            {
                GDriver->OCommand("");
                return;
            }
            FRoutes[GDriver->OCommand()[0] - static_cast<std::intmax_t>('A')][GDriver->OCommand()[1] - static_cast<std::intmax_t>('A')] = std::stoull(GDriver->OCommand().substr(2));
            GDriver->OCommand("Write");
        }
    }
    void CLinker::IRead()
    {
        if(GDriver->OCommand() == "Read")
        {
            GDriver->OSetNewCommand(1);
            std::cout << "{" << "\n";
            for(std::uintmax_t LDeparture{0} ; LDeparture < FRoutes.size() ; LDeparture++)
            {
                GDriver->OSetNewCommand(2);
                for(std::uintmax_t LArrival{0} ; LArrival < FRoutes[LDeparture].size() ; LArrival++)
                {
                    std::cout << static_cast<char>('A' + LDeparture) << static_cast<char>('A' + LArrival) << FRoutes[LDeparture][LArrival] << " ";
                }
                std::cout << "\n";
            }
            GDriver->OSetNewCommand(1);
            std::cout << "}" << "\n";
            GDriver->OCommand("");
        }
    }

    void CLinker::ARun()
    {
        IWrite();
        IRead();
    }

    std::array<std::array<std::uintmax_t , 26> , 26> CLinker::ORoutes()
    {
        return FRoutes;
    }
}