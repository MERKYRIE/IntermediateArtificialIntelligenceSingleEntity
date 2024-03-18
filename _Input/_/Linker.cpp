#include"Linker.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    bool CLinker::ARun()
    {
        while(true)
        {
            IGetNewCommand();
            if(IReturn())
            {
                return(true);
            }
            IWrite();
            IRead();
            if(IContinue())
            {
                break;
            }
        }
        return(false);
    }
}