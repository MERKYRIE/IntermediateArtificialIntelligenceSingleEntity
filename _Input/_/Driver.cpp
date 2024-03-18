#include"Driver.hpp"

#include"Driver\\Preprocessor.hpp"
#include"Driver\\Compiler.hpp"
#include"Driver\\Linker.hpp"
#include"Driver\\Executor.hpp"

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    bool CDriver::ARun()
    {
        FModule = "Preprocessor";
        while(true)
        {
            if(FCommand.empty())
            {
                OGetNewCommand(0);
                if(OReturn())
                {
                    return(true);
                }
                if(OContinue())
                {
                    continue;
                }
            }
            if(FModule == "Preprocessor")
            {
                NDriver::GPreprocessor->ARun();
                continue;
            }
            if(FModule == "Compiler")
            {
                NDriver::GCompiler->ARun();
                continue;
            }
            if(FModule == "Linker")
            {
                NDriver::GLinker->ARun();
                continue;
            }
            if(FModule == "Executor")
            {
                NDriver::GExecutor->ARun();
                continue;
            }
            if(FModule.empty())
            {
                break;
            }
        }
        return(false);
    }
    
    void CDriver::OGetNewCommand(std::uintmax_t PIndentation)
    {
        for(std::uintmax_t LIndent{0} ; LIndent < PIndentation ; LIndent++)
        {
            std::cout << "    ";
        }
        std::cout << FModule << " << ";
        std::getline(std::cin , FCommand);
    }
    void CDriver::OSetNewCommand(std::uintmax_t PIndentation)
    {
        for(std::uintmax_t LIndent{0} ; LIndent < PIndentation ; LIndent++)
        {
            std::cout << "    ";
        }
        std::cout << FModule << " >> ";
    }
    std::string CDriver::OCommand()
    {
        return FCommand;
    }
    void CDriver::OCommand(std::string PCommand)
    {
        FCommand = PCommand;
    }
    bool CDriver::OReturn()
    {
        if(FCommand == "Return")
        {
            FCommand.clear();
            return(true);
        }
        return(false);
    }
    bool CDriver::OContinue()
    {
        if(FCommand == "Continue")
        {
            if(FModule == "Executor")
            {
                FModule.clear();
            }
            if(FModule == "Linker")
            {
                FModule = "Executor";
            }
            if(FModule == "Compiler")
            {
                FModule = "Linker";
            }
            if(FModule == "Preprocessor")
            {
                FModule = "Compiler";
            }
            FCommand.clear();
            return(true);
        }
        return(false);
    }
    bool CDriver::OBreak()
    {
        if(FCommand == "Break")
        {
            FCommand.clear();
            return(true);
        }
        return(false);
    }
}