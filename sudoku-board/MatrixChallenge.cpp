#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>

auto removePunctuation(std::string strArr[], int arrLength)
{
    std::vector<std::string> sudokuBoard;
    
    auto isPunctuation = [](char c) { return c == '(' || c == ')' || c == ','; };

    for (int i = 0; i < arrLength; i++)
    {     
        sudokuBoard.push_back(strArr[i]);
    }

    for(auto& row : sudokuBoard)        
        row.erase(std::remove_if(row.begin(), row.end(), isPunctuation), row.end());

    return sudokuBoard;
}

auto mapDigits(std::vector<std::string> strArr)
{
    std::map<char, std::vector<std::pair<int, int>>> digitMap;

    for (auto i = 0; i < strArr.size(); i++)
    {
        auto row = strArr[i];
        for (auto j = 0; j < row.length(); j++)
        {
            auto c = strArr[i][j];
            if (isdigit(c))
            {
                if (digitMap.count(c))
                {
                    digitMap[c].push_back({ i,j });
                }
                else
                {
                    digitMap[c] = std::vector<std::pair<int, int>>{ {i,j} };
                }

            }
        }
    }
        
    return digitMap;
}

auto computeSubGridNumber(int row, int column)
{
    auto subRow = row / 3 + 1;
    auto subColumn = column / 3 + 1;
    auto subGridNumber = (subRow - 1) * 3 + subColumn;

    return subGridNumber;
}

auto computeIllegalDigitCoordinates(std::map<char, std::vector<std::pair<int, int>>> digitMap)
{
    std::map<char, std::vector<std::pair<int, int>>> illegalDigitMap;

    for (auto mapIt = digitMap.begin(); mapIt != digitMap.end(); mapIt++)
    {
        auto coordinatesArray = mapIt->second;
        for (auto vectorIt = coordinatesArray.begin(); vectorIt != coordinatesArray.end(); vectorIt++)
        {
            auto foundMatch = false;
            for (auto nextIt = vectorIt + 1; nextIt != coordinatesArray.end(); nextIt++)
            {
                auto digitsAreOnSameRowOrColumn = vectorIt->first == nextIt->first || vectorIt->second == nextIt->second;
                auto digitsOcuppySameSubgrid = computeSubGridNumber(vectorIt->first, vectorIt->second) == computeSubGridNumber(nextIt->first, nextIt->second);
                if (digitsAreOnSameRowOrColumn || digitsOcuppySameSubgrid)
                {
                    foundMatch = true;
                    if (illegalDigitMap.count(mapIt->first))
                    {
                        auto illegalDigitCoord = illegalDigitMap[mapIt->first];
                        if(std::find(illegalDigitCoord.begin(), illegalDigitCoord.end(), *nextIt) == illegalDigitCoord.end())
                            illegalDigitMap[mapIt->first].push_back(*nextIt);
                    }
                    else
                        illegalDigitMap[mapIt->first] = std::vector < std::pair<int, int> >{*nextIt};                    
                }
                    
            }
            if (foundMatch)
            {
                auto illegalDigitCoordinates = illegalDigitMap[mapIt->first];
                if (std::find(illegalDigitCoordinates.begin(), illegalDigitCoordinates.end(), *vectorIt) == illegalDigitCoordinates.end())
                    illegalDigitMap[mapIt->first].push_back(*vectorIt);
            }
                
        }
    }        

    return illegalDigitMap;
}

auto computeIllegalSubGrids(std::map<char, std::vector<std::pair<int, int>>> illegalDigitMap)
{
    std::vector<int> illegalSubGrids;

    for (auto mapIt = illegalDigitMap.begin(); mapIt != illegalDigitMap.end(); mapIt++)
    {
        auto coordinatesArray = mapIt->second;
        for (auto vectorIt = coordinatesArray.begin(); vectorIt != coordinatesArray.end(); vectorIt++)
        {           
            auto subGridNumber = computeSubGridNumber(vectorIt->first, vectorIt->second);
            if (std::find(illegalSubGrids.begin(), illegalSubGrids.end(), subGridNumber) == illegalSubGrids.end())
                illegalSubGrids.push_back(subGridNumber);
        }
        
    }

    std::sort(illegalSubGrids.begin(), illegalSubGrids.end());

    return illegalSubGrids;

}

std::string MatrixChallenge(std::string strArr[], int arrLength) {

    auto sudokuBoard = removePunctuation(strArr, arrLength);

    auto digitMap = mapDigits(sudokuBoard);

    auto illegalDigitMap = computeIllegalDigitCoordinates(digitMap);

    auto illegalSubGrids = computeIllegalSubGrids(illegalDigitMap);

    if(!illegalSubGrids.size())
        return "legal";

    std::stringstream subgrids;
    for (auto subGridNumber : illegalSubGrids)
        subgrids << subGridNumber << ((subGridNumber != illegalSubGrids.back()) ? "," : "");

    return subgrids.str();

}


int main()
{

	//Illegal Case
    std::string A[] = { "(1,2,3,4,5,6,7,8,9)", "(x,x,x,x,x,x,8,x,x)", "(6,x,5,x,3,x,x,4,7)",
        "(2,x,1,1,1,x,x,2,x)", "(x,x,x,x,x,x,x,x,x)",
        "(x,x,x,x,x,1,x,x,x)", "(,x,x,x,x,x,x,x,x)",
        "(1,x,x,x,x,x,x,x,x)", "(1,x,x,x,x,x,x,x,9)" };

	//Legal Case
   /* std::string A[] = { "(x,x,x,x,x,x,x,x,x)", "(x,x,x,x,x,x,8,x,x)", "(x,x,x,x,x,x,x,x,x)",
        "(x,x,x,x,x,x,x,x,x)", "(x,x,x,x,x,x,x,x,x)",
        "(x,x,x,x,x,1,x,x,x)", "(,x,x,x,x,x,x,x,x)",
        "(x,x,x,x,x,x,x,x,x)", "(1,x,x,x,x,x,x,x,9)" };*/

    int arrLength = sizeof(A) / sizeof(*A);
    auto result = MatrixChallenge(A, arrLength);

    return 0;
}