#include"Loader.hpp"

#include"Driver\\Compiler.hpp"
#include"Driver\\Linker.hpp"
#include"Driver\\Executor.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    void CLoader::IRun()
    {
        for(std::uintmax_t LArrival{0} ; LArrival < NDriver::GLinker->ORoutes()[FCurrent].size() ; LArrival++)
        {
            if(NDriver::GLinker->ORoutes()[FCurrent][LArrival])
            {
                FArrivals.push_back(LArrival);
            }
        }
    }

    void CLoader::ARun()
    {
        FCurrent = NDriver::GExecutor->ODeparture();
        IRun();
    }
}