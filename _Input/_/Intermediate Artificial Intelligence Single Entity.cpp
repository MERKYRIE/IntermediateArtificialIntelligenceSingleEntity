#include<algorithm>
#include<array>
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

std::int32_t main()
{
    std::unordered_map<std::string , std::unordered_map<std::string , std::uintmax_t>> LTransitions;
    std::uintmax_t LBegin;
    std::uintmax_t LEnd;
    std::unordered_set<std::string> LLocations;
    std::unordered_map<std::string , std::uintmax_t> LCosts;
    std::unordered_map<std::string , std::uintmax_t> LDistances;
    std::string LCurrent;
    LTransitions["A"]["B"] = 1;
    LTransitions["B"]["D"] = 2;
    LTransitions["A"]["C"] = 3;
    LTransitions["C"]["D"] = 4;
    LBegin = 0;
    LEnd = 3;
    for(std::pair<const std::string , std::unordered_map<std::string , std::uintmax_t>>& LTransition : LTransitions)
    {
        LLocations.insert(LTransition.first);
        for(std::pair<const std::string , std::uintmax_t>& LCost : LTransition.second)
        {
            LLocations.insert(LCost.first);
        }
    }
    std::ranges::for_each(LCosts , [](std::uintmax_t& PCost){PCost = std::numeric_limits<std::uintmax_t>::max();});
    LCosts[LBegin] = 0;
    std::ranges::for_each(LDistances , [](std::uintmax_t& PDistance){PDistance = std::numeric_limits<std::uintmax_t>::max();});
    LDistances[LBegin] = 0;
    while(!LLocations.empty())
    {
        LCurrent = std::ranges::min(LLocations);
        for(std::string LLocation : LLocations)
        {
            if(LCurrent != LLocation)
            {
                if(LTransitions[LCurrent][LLocation] != std::numeric_limits<std::uintmax_t>::max())
                {
                    if(LTransitions[LCurrent][LLocation] < LCosts[LLocation])
                    {
                        LCosts[LLocation] = LCosts[LCurrent] + LTransitions[LCurrent][LLocation];
                    }
                    if(LDistances[LCurrent] < LDistances[LLocation])
                    {
                        LDistances[LLocation] = LDistances[LCurrent] + 1;
                    }
                }
            }
        }
        LLocations.erase(std::ranges::find(LLocations , LCurrent));
    }
    std::cout << "Cost = " << LCosts[LEnd] << "\n"
              << "Distance = " << LDistances[LEnd] << "\n";
    #ifdef _WIN32
        std::system("Pause");
    #endif
    return(0);
}