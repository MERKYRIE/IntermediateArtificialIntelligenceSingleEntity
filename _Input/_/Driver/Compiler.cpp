#include"Compiler.hpp"

#include"Driver.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity::NDriver
{
    void CCompiler::IWrite()
    {
        if(GDriver->OCommand() == "Write")
        {
            GDriver->OGetNewCommand(1);
            if(GDriver->OBreak())
            {
                GDriver->OCommand("");
                return;
            }
            std::ranges::for_each(GDriver->OCommand() , [&](char LNode){FNodes.insert(LNode - static_cast<std::intmax_t>('A'));});
            GDriver->OCommand("Write");
        }
    }
    void CCompiler::IRead()
    {
        if(GDriver->OCommand() == "Read")
        {
            GDriver->OSetNewCommand(1);
            std::cout << "{";
            std::ranges::for_each(FNodes , [](std::uintmax_t LNode){std::cout << static_cast<char>('A' + LNode);});
            std::cout << "}" << "\n";
            GDriver->OCommand("");
        }
    }

    void CCompiler::ARun()
    {
        IWrite();
        IRead();
    }

    std::set<std::uintmax_t> CCompiler::ONodes()
    {
        return FNodes;
    }
}