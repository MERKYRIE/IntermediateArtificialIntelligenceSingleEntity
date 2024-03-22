#include<algorithm>
#include<array>
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

/*
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
*/

std::int32_t main(std::int32_t , char**)
{
    struct STerrain
    {
        double FCost;
    };
    struct SNode
    {
        std::intmax_t FTo;
        std::intmax_t FFrom;
        std::intmax_t FSum;
        STerrain FTerrain;
        SNode* FParent;
        std::intmax_t FX;
        std::intmax_t FY;
    };

    STerrain LNormal;
    STerrain LChallenging;
    STerrain LDifficult;
    STerrain LImpossible;
    std::intmax_t LWidth;
    std::intmax_t LHeight;
    std::vector<SNode> LNodes;
    SNode* LBegin;
    SNode* LEnd;
    SNode* LCurrent;
    std::vector<SNode*> LOpened;
    std::vector<SNode*> LClosed;
    std::vector<SNode*> LChildren;

    LNormal = {1.0};
    LChallenging = {1.5};
    LDifficult = {2.0};
    LImpossible = {1'000'000'000.0};
    LWidth = 10;
    LHeight = 10;
    for(std::intmax_t LX{0} ; LX < LWidth ; LX++)
    {
        for(std::intmax_t LY{0} ; LY < LHeight ; LY++)
        {
            LNodes.emplace_back(0 , 0 , 0 , LNormal , nullptr , LX , LY);
        }
    }
    std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == 2 && PNode.FY == 2;})->FTerrain = LImpossible;
    std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == 2 && PNode.FY == 1;})->FTerrain = LImpossible;
    LBegin = &*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == 1 && PNode.FY == 1;});
    LEnd = &*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == 3 && PNode.FY == 2;});
    LOpened.push_back(LBegin);
    while(!LOpened.empty())
    {
        LCurrent = std::ranges::min(LOpened , [&](SNode*& PNode , SNode*& PMinimum){return PNode->FSum < PMinimum->FSum;});
        LOpened.erase(std::ranges::find(LOpened , LCurrent));
        LClosed.push_back(LCurrent);
        if(LCurrent == LEnd)
        {
            std::cout << "Width = " << LWidth << "\n"
                      << "Height = " << LHeight << "\n"
                      << "Begin = [" << LBegin->FX << "][" << LBegin->FY << "]" << "\n"
                      << "End = [" << LEnd->FX << "][" << LEnd->FY << "]" << "\n"
                      << "Path = " << "\n"
                      << "{" << "\n";
            for(SNode* LNode{LCurrent} ; LNode ; LNode = LNode->FParent)
            {
                std::cout << "    [" << LNode->FX << "][" << LNode->FY << "] = {To = " << LNode->FTo
                          << " , From = " << LNode->FFrom
                          << " , Sum = " << LNode->FSum
                          << " , Terrain = " << LNode->FTerrain.FCost
                          << "}" << "\n";
            }
            std::cout << "}" << "\n";
            break;
        }
        if(LCurrent->FX - 1 == std::clamp<std::intmax_t>(LCurrent->FX - 1 , 0 , LWidth - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX - 1 && PNode.FY == LCurrent->FY;}));
        }
        if(LCurrent->FX + 1 == std::clamp<std::intmax_t>(LCurrent->FX + 1 , 0 , LWidth - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX + 1 && PNode.FY == LCurrent->FY;}));
        }
        if(LCurrent->FY - 1 == std::clamp<std::intmax_t>(LCurrent->FY - 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX && PNode.FY == LCurrent->FY - 1;}));
        }
        if(LCurrent->FY + 1 == std::clamp<std::intmax_t>(LCurrent->FY + 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX && PNode.FY == LCurrent->FY + 1;}));
        }
        if(LCurrent->FX - 1 == std::clamp<std::intmax_t>(LCurrent->FX - 1 , 0 , LWidth - 1) && LCurrent->FY - 1 == std::clamp<std::intmax_t>(LCurrent->FY - 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX - 1 && PNode.FY == LCurrent->FY - 1;}));
        }
        if(LCurrent->FX + 1 == std::clamp<std::intmax_t>(LCurrent->FX + 1 , 0 , LWidth - 1) && LCurrent->FY + 1 == std::clamp<std::intmax_t>(LCurrent->FY + 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX + 1 && PNode.FY == LCurrent->FY + 1;}));
        }
        if(LCurrent->FX - 1 == std::clamp<std::intmax_t>(LCurrent->FX - 1 , 0 , LWidth - 1) && LCurrent->FY + 1 == std::clamp<std::intmax_t>(LCurrent->FY + 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX - 1 && PNode.FY == LCurrent->FY + 1;}));
        }
        if(LCurrent->FX + 1 == std::clamp<std::intmax_t>(LCurrent->FX + 1 , 0 , LWidth - 1) && LCurrent->FY - 1 == std::clamp<std::intmax_t>(LCurrent->FY - 1 , 0 , LHeight - 1))
        {
            LChildren.push_back(&*std::ranges::find_if(LNodes , [&](SNode& PNode){return PNode.FX == LCurrent->FX + 1 && PNode.FY == LCurrent->FY - 1;}));
        }
        for(SNode*& LChild : LChildren)
        {
            if(std::ranges::find(LClosed , LChild) != LClosed.end())
            {
                continue;
            }
            LChild->FTo = LCurrent->FTo + static_cast<std::intmax_t>
            (
                std::sqrt((LCurrent->FX - LChild->FX) * (LCurrent->FX - LChild->FX) + (LCurrent->FY - LChild->FY) * (LCurrent->FY - LChild->FY)) * 10.0 * LChild->FTerrain.FCost
            );
            LChild->FFrom = (std::abs(LChild->FX - LEnd->FX) + std::abs(LChild->FY - LEnd->FY)) * 10;
            LChild->FSum = LChild->FTo + LChild->FFrom;
            LChild->FParent = LCurrent;
            std::vector<SNode*>::iterator LIterator{std::ranges::find(LOpened , LChild)};
            if(LIterator != LOpened.end())
            {
                if(LChild->FTo > (*LIterator)->FTo)
                {
                    continue;
                }
            }
            LOpened.push_back(LChild);
        }
    }
    #ifdef _WIN32
        std::system("Pause");
    #endif
    return(0);
}