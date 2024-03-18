#include"Intermediate Artificial Intelligence Single Entity.hpp"

#include"Driver.hpp"
#include"Driver\\Preprocessor.hpp"
#include"Driver\\Compiler.hpp"
#include"Driver\\Linker.hpp"
#include"Driver\\Executor.hpp"

std::int32_t main()
{
    NIntermediateArtificialIntelligenceSingleEntity::GDriver = new NIntermediateArtificialIntelligenceSingleEntity::CDriver;
    NIntermediateArtificialIntelligenceSingleEntity::NDriver::GPreprocessor = new NIntermediateArtificialIntelligenceSingleEntity::NDriver::CPreprocessor;
    NIntermediateArtificialIntelligenceSingleEntity::NDriver::GCompiler = new NIntermediateArtificialIntelligenceSingleEntity::NDriver::CCompiler;
    NIntermediateArtificialIntelligenceSingleEntity::NDriver::GLinker = new NIntermediateArtificialIntelligenceSingleEntity::NDriver::CLinker;
    NIntermediateArtificialIntelligenceSingleEntity::NDriver::GExecutor = new NIntermediateArtificialIntelligenceSingleEntity::NDriver::CExecutor;
    if(!NIntermediateArtificialIntelligenceSingleEntity::GDriver->ARun())
    {
    
    }
    delete NIntermediateArtificialIntelligenceSingleEntity::NDriver::GExecutor;
    delete NIntermediateArtificialIntelligenceSingleEntity::NDriver::GLinker;
    delete NIntermediateArtificialIntelligenceSingleEntity::NDriver::GCompiler;
    delete NIntermediateArtificialIntelligenceSingleEntity::NDriver::GPreprocessor;
    delete NIntermediateArtificialIntelligenceSingleEntity::GDriver;
    return(0);
}