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
    std::string LBegin;
    std::string LEnd;
    std::unordered_set<std::string> LLocations;
    std::unordered_map<std::string , std::uintmax_t> LCosts;
    std::unordered_map<std::string , std::vector<std::string>> LPaths;
    std::string LCurrent;
    LTransitions["A"]["B"] = 9;
    LTransitions["B"]["C"] = 8;
    LTransitions["A"]["D"] = 1;
    LTransitions["D"]["C"] = 2;
    LBegin = "A";
    LEnd = "C";
    for(std::pair<const std::string , std::unordered_map<std::string , std::uintmax_t>>& LTransition : LTransitions)
    {
        LLocations.insert(LTransition.first);
        LCosts[LTransition.first] = std::numeric_limits<std::uintmax_t>::max();
        for(std::pair<const std::string , std::uintmax_t>& LCost : LTransition.second)
        {
            LLocations.insert(LCost.first);
            LCosts[LCost.first] = std::numeric_limits<std::uintmax_t>::max();
        }
    }
    LCosts[LBegin] = 0;\
    LPaths[LBegin] = {};
    while(!LLocations.empty())
    {
        LCurrent
        =
        std::ranges::min_element
        (
            LCosts
            ,
            [&]
            (std::pair<const std::string , std::uintmax_t>& PCost , std::pair<const std::string , std::uintmax_t>& PMinimum)
            {return !LLocations.contains(PMinimum.first) || (LLocations.contains(PCost.first) && PCost.second < PMinimum.second);}
        )
        ->
        first;
        for(std::string LLocation : LLocations)
        {
            if(LCurrent != LLocation)
            {
                if(LTransitions[LCurrent].contains(LLocation))
                {
                    if(LTransitions[LCurrent][LLocation] < LCosts[LLocation])
                    {
                        LCosts[LLocation] = LCosts[LCurrent] + LTransitions[LCurrent][LLocation];
                    }
                    if(!LPaths.contains(LLocation) || LPaths[LCurrent].size() + 1 < LPaths[LLocation].size())
                    {
                        LPaths[LLocation] = LPaths[LCurrent];
                        LPaths[LLocation].push_back(LCurrent);
                    }
                }
            }
        }
        LLocations.erase(std::ranges::find(LLocations , LCurrent));
    }
    std::cout << "Cost = " << LCosts[LEnd] << "\n"
              << "Distance = " << LPaths[LEnd].size() << "\n"
              << "Path = ";
    std::ranges::for_each(LPaths[LEnd] , [](std::string& PPath){std::cout << ">" << PPath;});
    std::cout << "\n";
    #ifdef _WIN32
        std::system("Pause");
    #endif
    return(0);
}