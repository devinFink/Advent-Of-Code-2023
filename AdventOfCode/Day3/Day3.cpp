// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"
#include <tchar.h>
#include <cstdio>

using namespace std;

int part1(vector<string> fileToVector)
{
	string currentLine;

	int currentNumStart;
	string currentNum = "";
	int sum = 0;

	for (int i = 0; i < fileToVector.size(); i++)
	{
		currentLine = fileToVector[i];
		for (int parseLine = 0; parseLine < fileToVector[i].size(); parseLine++)
		{
			currentNum = "";
			if (isdigit(currentLine[parseLine]) != 0)
			{
				currentNumStart = parseLine;
				currentNum += currentLine[parseLine];
				while (isdigit(currentLine[parseLine + 1]) != 0)
				{
					parseLine++;
					currentNum += currentLine[parseLine];
				}

				if (i > 0)
				{
					for (int parsePreviousLine = max(currentNumStart - 1, 0); parsePreviousLine <= min(parseLine + 1, (int)currentLine.size() - 1); parsePreviousLine++)
					{
						if (isdigit(fileToVector[i - 1][parsePreviousLine] != 0))
							continue;
						else if (fileToVector[i - 1][parsePreviousLine] != '.')
						{
							sum += stoi(currentNum);
							goto newNum;
						}
					}
				}

				if (currentLine[max(currentNumStart - 1, 0)] != '.')
				{
					if (!isdigit(currentLine[max(currentNumStart - 1, 0)]))
					{
						sum += stoi(currentNum);
						continue;
					}
				}
				
				if (currentLine[min(parseLine + 1, (int)currentLine.size() - 1)] != '.')
				{
					if (!isdigit(currentLine[min(parseLine + 1, (int)currentLine.size() - 1)]))
					{
						sum += stoi(currentNum);
						continue;
					}
				}

				if (i < fileToVector.size() - 1)
				{
					for (int parseFutureLine = max(currentNumStart - 1, 0); parseFutureLine <= min(parseLine + 1, (int)currentLine.size() - 1); parseFutureLine++)
					{
						if (isdigit(fileToVector[i + 1][parseFutureLine] != 0))
							continue;
						else if (fileToVector[i + 1][parseFutureLine] != '.')
						{
							sum += stoi(currentNum);
							goto newNum;
						}
					}
				}
				
				newNum: continue;
			}
		}
	}
	return sum;
}

string findNum(vector<string> input, int y, int x)
{
	bool numFound = false;
	for (int i = 0; i < input[y].size(); i++)
	{
		string currentNum = "";
		while (isdigit(input[y][i]) != 0)
		{
			if (i == x)
				numFound = true;
			currentNum += input[y][i];
			i++;
		}

		if (numFound)
			return currentNum;
	}

	cout << "Houston we have a problem";
	return "error: num not Found";
}

int part2(vector<string> fileToVector)
{
	string currentLine;

	int sum = 0;

	for (int i = 0; i < fileToVector.size(); i++)
	{
		currentLine = fileToVector[i];
		for (int parseLine = 0; parseLine < fileToVector[i].size(); parseLine++)
		{
			if (currentLine[parseLine] == '*')
			{
				vector<int> gears;
				if (i > 0)
				{
					bool numProcessing = false;
					for (int parsePreviousLine = max(parseLine - 1, 0); parsePreviousLine <= min(parseLine + 1, (int)currentLine.size() - 1); parsePreviousLine++)
					{
						if (isdigit(fileToVector[i - 1][parsePreviousLine]) != 0 && !numProcessing)
						{
							numProcessing = true;
							gears.push_back(stoi(findNum(fileToVector, i - 1, parsePreviousLine)));
						}
						if (isdigit(fileToVector[i - 1][parsePreviousLine]) == 0)
						{
							numProcessing = false;
						}
					}
				}

				if (isdigit(currentLine[max(parseLine - 1, 0)]) != 0)
				{
					string tempNum = findNum(fileToVector, i, max(parseLine - 1, 0));
					gears.push_back(stoi(tempNum));
				}

				if (isdigit(currentLine[min(parseLine + 1, (int)currentLine.size())]) != 0)
				{
					gears.push_back(stoi(findNum(fileToVector, i, min(parseLine + 1, (int)currentLine.size()))));
				}

				if (i < fileToVector.size() - 1)
				{
					bool numProcessing = false;
					for (int parseFutureLine = max(parseLine - 1, 0); parseFutureLine <= min(parseLine + 1, (int)currentLine.size() - 1); parseFutureLine++)
					{
						if (isdigit(fileToVector[i + 1][parseFutureLine]) != 0 && !numProcessing)
						{
							numProcessing = true;
							gears.push_back(stoi(findNum(fileToVector, i + 1, parseFutureLine)));
						}
						if (isdigit(fileToVector[i + 1][parseFutureLine]) == 0)
						{
							numProcessing = false;
						}
					}
				}

				if (gears.size() == 2)
				{
					int power = gears.back();
					gears.pop_back();
					power *= gears.back();
					gears.pop_back();
					sum += power;
				}

				gears.clear();
			}
		}
	}
	return sum;
}


int main()
{
	ifstream fileToRead("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day3\\dayThreeInput.txt");

	string currentLine;
	vector<string> fileToVector;

	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}
	
	cout << part1(fileToVector) << endl;
	cout << part2(fileToVector);
}
