// Day6.cpp : Defines the entry point for the application.
//

#include "Day6.h"


using namespace std;

vector<int> splitInts(string str)
{
	vector<int> nums;
	string currentNum;

	for (int i = 0; i < str.size(); i++)
	{
		currentNum.clear();
		if (isdigit(str[i]) != 0)
		{
			currentNum += str[i];
			while (isdigit(str[i + 1]) != 0)
			{
				i++;
				currentNum += str[i];
			}

			nums.push_back(stoi(currentNum));
		}
	}

	return nums;
}

int part1(vector<string> file)
{
	vector<int> times = splitInts(file[0]);
	vector<int> distance = splitInts(file[1]);
	int count = 1;
	for (int i = 0; i < times.size(); i++)
	{
		int distanceTraveled = 0;
		int currentWaysToWin = 0;
		for (int holdButton = 0; holdButton < times[i]; holdButton++)
		{
			distanceTraveled = holdButton * (times[i] - holdButton);
			if (distanceTraveled > distance[i])
			{
				currentWaysToWin++;
			}
			else if (currentWaysToWin > 0)
			{
				break;
			}
		}

		count *= currentWaysToWin;
	}

	return (count);
}

int part2(vector<string> file)
{
	vector<int> times = splitInts(file[0]);
	string realTime;
	for (int time : times)
	{
		realTime += to_string(time);
	}

	vector<int> distance = splitInts(file[1]);
	string realDistance;
	for (int distance : distance)
	{
		realDistance += to_string(distance);
	}

	int count = 0;
	unsigned long long distanceTraveled = 0;
	int currentWaysToWin = 0;
	for (unsigned long long holdButton = 0; holdButton < stoull(realTime); holdButton++)
	{
		distanceTraveled = holdButton * (stoull(realTime) - holdButton);
		if (distanceTraveled > stoull(realDistance))
		{
			currentWaysToWin++;
		}
		else if (currentWaysToWin > 0)
		{
			break;
		}
	}

	return (currentWaysToWin);
}

int main()
{
	ifstream fileToRead("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day6\\daySixInput.txt");
	vector<string> fileToVector;
	string currentLine;
	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}

	cout << part1(fileToVector) << endl;
	cout << part2(fileToVector);
}
