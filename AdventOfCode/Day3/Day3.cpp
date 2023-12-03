// Day3.cpp : Defines the entry point for the application.
//

#include "Day3.h"
#include <tchar.h>
#include <cstdio>

using namespace std;

int part1(ifstream &fileToRead)
{
	string currentLine;
	vector<string> fileToVector;

	int currentNumStart;
	string currentNum = "";
	int sum = 0;

	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}

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


int main()
{
	ifstream fileToRead("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day3\\dayThreeInput.txt");
	
	cout << part1(fileToRead);
}

int part2(ifstream fileToRead)
{
	return 0;
	/*string currentLine;
	vector<string> fileToVector;

	int currentNumStart;
	string currentNum = "";
	int sum = 0;

	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}

	for (int i = 0; i < fileToVector.size(); i++)
	{
		currentLine = fileToVector[i];
		for (int parseLine = 0; parseLine < fileToVector[i].size(); parseLine++)
		{
			currentNum = "";
			if (currentLine[parseLine] = '*')
			{
				vector<int> gears;
				if (i > 0)
				{
					for (int parsePreviousLine = max(parseLine - 1, 0); parsePreviousLine <= min(parseLine + 1, (int)currentLine.size() - 1); parsePreviousLine++)
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
	return sum;*/
}
