// Day5.cpp : Defines the entry point for the application.
//

#include "Day5.h"

using namespace std;
vector<string> split(string str, char delimiter);

struct inputMap
{
	vector<long long> destinations;
	vector<long long> sources;
	vector<long long> ranges;
};

int part1(vector<string> fileToVector)
{
	vector<inputMap> maps;
	vector<long long> seeds;
	for (string currentLine : fileToVector)
	{
		if (currentLine.find("seeds") != string::npos)
		{
			string trimmedLine = currentLine.substr(currentLine.find(" ") + 1);
			for (string seed : split(trimmedLine, ' '))
			{
				seeds.push_back(strtoll(seed.c_str(), NULL, 10));
			}
			continue;
		}

		if ((currentLine.find("map") != string::npos))
		{
			inputMap newMap;
			maps.push_back(newMap);
		}
		else if (currentLine.size() == 0)
		{
			continue;
		}
		else
		{
			vector<string> lineOfMappings = split(currentLine, ' ');
			maps[maps.size() - 1].destinations.push_back(strtoll(lineOfMappings[0].c_str(), NULL, 10));
			maps[maps.size() - 1].sources.push_back(strtoll(lineOfMappings[1].c_str(), NULL, 10));
			maps[maps.size() - 1].ranges.push_back(strtoll(lineOfMappings[2].c_str(), NULL, 10));
		}
	}

	return seeds[0];

}

vector<string> split(string str, char delimiter)
{
	vector<string> strings;
	string currentString;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == delimiter)
		{
			strings.push_back(currentString);
			currentString.clear();
			continue;
		}
		else if (i == str.size() - 1)
		{
			currentString += str[i];
			strings.push_back(currentString);
		}
		currentString += str[i];
	}

	return strings;
}

int main()
{
	ifstream fileToRead("C:\\Users\\devin\\source\\repos\\Advent-Of-Code-2023\\AdventOfCode\\Day5\\dayFiveInput.txt");
	vector<string> fileToVector;
	string currentLine;
	while (getline(fileToRead, currentLine))
	{
		fileToVector.push_back(currentLine);
	}

	cout << part1(fileToVector);
}
