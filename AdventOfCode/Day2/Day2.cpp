// Day2.cpp : Defines the entry point for the application.
//

#include "Day2.h"

using std::ifstream;
using std::map;
using std::string;



int main()
{
	ifstream fileToRead;
	string currentLine;
	int gamePower = 0;
	bool readyForInput = false;
	int inputStartIndex;
	int runningTotal = 0;

	fileToRead.open("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day2\\dayTwoInput.txt");
	map<char, int> minBallCount =
	{ {'r', 0},
	  {'g', 0},
	  {'b', 0},
	};
	
	while (getline(fileToRead, currentLine))
	{
		gamePower = 1;
		currentLine.erase(remove_if(currentLine.begin(), currentLine.end(), isspace), currentLine.end());
		readyForInput = false;
		minBallCount['r'] = 0;
		minBallCount['g'] = 0;
		minBallCount['b'] = 0;

		while (!readyForInput)
		{
			for (int i = 0; i < currentLine.size(); i++)
			{
				if (currentLine[i] == ':')
				{
					readyForInput = true;
					inputStartIndex = i;
				}
			}
		}

		for (int i = inputStartIndex; i < currentLine.size(); i++)
		{
			if (isdigit(currentLine[i]) != 0)
			{
				string currentNumOfBalls;
				currentNumOfBalls += currentLine[i];

				while (isdigit(currentLine[i + 1]) != 0)
				{
					currentNumOfBalls += currentLine[i + 1];
					i++;
				}

				int value = stoi(currentNumOfBalls);
				char color = currentLine[i + 1];

				if (value > minBallCount[color])
				{
					minBallCount[color] = value;
				}
			}
		}

		for (auto const& pair : minBallCount)
		{
			gamePower *= pair.second;
		}

		runningTotal += gamePower;
	}

	std::cout << runningTotal;
}
