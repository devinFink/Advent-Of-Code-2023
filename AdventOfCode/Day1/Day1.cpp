// Day1.cpp : Defines the entry point for the application.
//

#include "Day1.h"

using std::ifstream;
using std::string;
using std::map;
using std::vector;

map<string, int> possibleNums =
{ {"one", 1},
    {"two", 2},
    {"three",3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9}
};

map<string, int> reverseNums = 
{ {"eno", 1},
    {"owt", 2},
    {"eerht",3},
    {"ruof", 4},
    {"evif", 5},
    {"xis", 6},
    {"neves", 7},
    {"thgie", 8},
    {"enin", 9}
};

string findFirstPattern(std::string currentLine, map<string, int> mapOfValues)
{
    string firstDigit;
    string tempNum;
    int firstIndex = 0;
    for (int i = 0; i < currentLine.size(); i++)
    {
        if (isdigit(currentLine[i]) != 0)
        {
            firstDigit = currentLine[i];
            firstIndex = i;
            break;
        }
    }

    for (auto const& pair : mapOfValues)
    {
        if (currentLine.find(pair.first) < firstIndex)
        {
            firstDigit = std::to_string(pair.second);
            firstIndex = currentLine.find(pair.first);
        }
    }

    return firstDigit;
}

string reverseString(std::string currentLine)
{
    string reverse;
    for (int i = (int)currentLine.size() - 1; i >= 0; i--)
    {
        reverse += currentLine[i];
    }

    return reverse;
}

int calculateSum(ifstream &fileToRead)
{
    int totalSum = 0;
    using std::ifstream;
    std::string currentLine;

    if (fileToRead.is_open())
    {
        while (getline(fileToRead, currentLine))
        {
            int length = currentLine.length();
            char* brokenLine = new char[length];

            std::string lineValue;

            lineValue += findFirstPattern(currentLine, possibleNums);

            string temp = reverseString(currentLine);

            lineValue += findFirstPattern(temp, reverseNums);

            totalSum += stoi(lineValue);
        }
    }

    return totalSum;
}

int main()
{
    std::ifstream fileToRead;

    fileToRead.open("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day1\\dayOneInput.txt");

    std::cout << calculateSum(fileToRead);
}