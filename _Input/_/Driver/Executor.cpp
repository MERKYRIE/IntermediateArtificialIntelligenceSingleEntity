#include"Executor.hpp"

#include"Driver.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    void CExecutor::IWrite()
    {
        if(GDriver->OCommand() == "Depart")
        {
            GDriver->OGetNewCommand(1);
            FDeparture = GDriver->OCommand()[0] - static_cast<std::intmax_t>('A');
            FArrival = GDriver->OCommand()[1] - static_cast<std::intmax_t>('A');
        }
    }
    void CExecutor::IRead()
    {
        if(GDriver->OCommand() == "Arrive")
        {
            GDriver->OSetNewCommand(1);
            std::cout << "{" << FDeparture << FArrival << "}" << "\n";
        }
    }

    void CExecutor::ARun()
    {
        IWrite();
        IRead();
    }

    std::uintmax_t CExecutor::ODeparture()
    {
        return FDeparture;
    }
    std::uintmax_t CExecutor::OArrival()
    {
        return FArrival;
    }
}