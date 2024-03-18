#include"Intermediate Artificial Intelligence Single Entity.hpp"

#include"Driver.hpp"
#include"Compiler.hpp"
#include"Linker.hpp"

std::int32_t main()
{
    NIntermediateArtificialIntelligenceSingleEntity::GCompiler = new NIntermediateArtificialIntelligenceSingleEntity::CCompiler;
    NIntermediateArtificialIntelligenceSingleEntity::GLinker = new NIntermediateArtificialIntelligenceSingleEntity::CLinker;
    NIntermediateArtificialIntelligenceSingleEntity::GDriver = new NIntermediateArtificialIntelligenceSingleEntity::CDriver;
    if(LCompiler.ARun())
    {
        return(0);
    }
    delete NIntermediateArtificialIntelligenceSingleEntity::GLinker;
    delete NIntermediateArtificialIntelligenceSingleEntity::GCompiler;
    delete NIntermediateArtificialIntelligenceSingleEntity::GDriver;
    return(0);
}