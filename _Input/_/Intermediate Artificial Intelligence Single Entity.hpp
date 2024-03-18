#pragma once

#include<algorithm>
#include<array>
#include<iostream>
#include<set>
#include<string>
#include<vector>

std::int32_t main();

namespace NIntermediateArtificialIntelligenceSingleEntity
{
    inline class CDriver* GDriver;
    namespace NDriver
    {
        inline class CPreprocessor* GPreprocessor;
        inline class CCompiler* GCompiler;
        inline class CLinker* GLinker;
        inline class CExecutor* GExecutor;
    }
}