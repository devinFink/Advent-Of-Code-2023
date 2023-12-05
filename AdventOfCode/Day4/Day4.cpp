// Day4.cpp : Defines the entry point for the application.
//

#include "Day4.h"

using namespace std;

int getNumberOfWinners(string currentLine)
{
	vector<int> winningNums;
	vector<int> myNums;
	bool onRightSide = false;
	bool readyForInput = false;

	for (int j = 0; j < currentLine.size(); j++)
	{
		if (currentLine[j] != ':' && !readyForInput)
		{
			continue;
		}
		else
		{
			readyForInput = true;
		}

		string num;
		if (isdigit(currentLine[j]) != 0)
		{
			num += currentLine[j];
			while (isdigit(currentLine[j + 1]) != 0)
			{
				j++;
				num += currentLine[j];
			}

			if (!onRightSide)
			{
				winningNums.push_back(stoi(num));
			}
			else
			{
				myNums.push_back(stoi(num));
			}
		}
		else if (currentLine[j] == '|')
		{
			onRightSide = true;
		}
	}

	int count = 0;
	for (int num : winningNums)
	{
		for (int myNum : myNums)
		{
			if (myNum == num)
			{
				count++;
			}
		}
	}

	return count;
}

int part1(vector<string> input)
{
	int totalWinnings = 0;
	for (int i = 0; i < input.size(); i++)
	{
		int count = getNumberOfWinners(input[i]);
		
		totalWinnings += (pow(2, count - 1));
	}
	return totalWinnings;
}

int countCards(int index, int depth, map<int, int> lineValues)
{
	int score = lineValues[index];
	if (score == 0)
	{
		return 1;
	}
	int totalCards = 1;
	for (int i = 0; i < score; i++)
	{
		totalCards += countCards(index + i + 1, depth + 1, lineValues);
	}

	return totalCards;
}
int part2(vector<string> input)
{
	int totalCards = 0;
	int lineValue = 0;
	map<int, int> lineValues;
	for (int i = 0; i < input.size(); i++)
	{
		lineValue = getNumberOfWinners(input[i]);
		lineValues.emplace(i, lineValue);
	}

	for (int i = 0; i < input.size(); i++)
	{
		totalCards += countCards(i, 0, lineValues);
	}

	return totalCards;
}

int main()
{
	ifstream fileToRead("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day4\\dayFourInput.txt");

	string currentLine;
	vector<string> fileToVector;

	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}

	cout << part1(fileToVector) << endl;
	cout << part2(fileToVector);
}
