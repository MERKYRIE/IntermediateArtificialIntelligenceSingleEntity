#include"Compiler.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    void CCompiler::IWrite()
    {
        if(FCommand == "Write")
        {
            while(true)
            {
                IGetNewCommand(1);
                if(FCommand == "Break")
                {
                    break;
                }
                std::ranges::for_each(FCommand , [&](char LNode){FNodes.insert(LNode);});
            }
        }
    }

    void CCompiler::IRead()
    {
        if(FCommand == "Read")
        {
            ISetNewCommand(1);
            std::cout << "\"";
            std::ranges::for_each(FNodes , [](char LNode){std::cout << LNode;});
            std::cout << "\"" << "\n";
        }
    }

    bool CCompiler::ARun()
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