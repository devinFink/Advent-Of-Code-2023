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

void populateVectors(vector<string> fileToVector, vector<inputMap>* maps, vector<long long>* seeds)
{
	for (string currentLine : fileToVector)
	{
		if (currentLine.find("seeds") != string::npos)
		{
			string trimmedLine = currentLine.substr(currentLine.find(" ") + 1);
			for (string seed : split(trimmedLine, ' '))
			{
				seeds->push_back(strtoll(seed.c_str(), NULL, 10));
			}
			continue;
		}

		if ((currentLine.find("map") != string::npos))
		{
			inputMap newMap;
			maps->push_back(newMap);
		}
		else if (currentLine.size() == 0)
		{
			continue;
		}
		else
		{
			vector<string> lineOfMappings = split(currentLine, ' ');
			(*maps)[maps->size() - 1].destinations.push_back(strtoll(lineOfMappings[0].c_str(), NULL, 10));
			(*maps)[maps->size() - 1].sources.push_back(strtoll(lineOfMappings[1].c_str(), NULL, 10));
			(*maps)[maps->size() - 1].ranges.push_back(strtoll(lineOfMappings[2].c_str(), NULL, 10));
		}
	}
}

int part1(vector<string> fileToVector)
{
	vector<inputMap> maps;
	vector<long long> seeds;

	populateVectors(fileToVector, &maps, &seeds);

	for(inputMap map : maps)
	{
		for (int seed = 0; seed < seeds.size(); seed++)
		{
			for (int i = 0; i < map.destinations.size(); i++)
			{
				bool seedInRange;
				if ((seeds[seed] >= map.sources[i]) && seeds[seed] < (map.sources[i] + map.ranges[i]))
					seedInRange = true;
				else
					seedInRange = false;

				if (seedInRange)
				{
					seeds[seed] = map.destinations[i] + (seeds[seed] - map.sources[i]);
					break;
				}
			}
		}
	}

	long long min = seeds[0];
	for (long long seed : seeds)
	{
		if (seed < min)
		{
			min = seed;
		}
	}
	return min;
}

int part2(vector<string> fileToVector)
{
	vector<inputMap> maps;
	vector<long long> seeds;

	populateVectors(fileToVector, &maps, &seeds);

	vector<long long> newSeeds;
	for (int i = 0; i < seeds.size(); i += 2)
	{
		for (int j = 0; j <  seeds[i + 1]; j++)
		{
			newSeeds.push_back(seeds[i] + j);
		}
	}

	for (inputMap map : maps)
	{
		for (int seed = 0; seed < newSeeds.size(); seed++)
		{
			for (int i = 0; i < map.destinations.size(); i++)
			{
				bool seedInRange;
				if ((newSeeds[seed] >= map.sources[i]) && newSeeds[seed] < (map.sources[i] + map.ranges[i]))
					seedInRange = true;
				else
					seedInRange = false;

				if (seedInRange)
				{
					newSeeds[seed] = map.destinations[i] + (newSeeds[seed] - map.sources[i]);
					break;
				}
			}
		}
	}

	long long min = newSeeds[0];
	for (long long seed : newSeeds)
	{
		if (seed < min)
		{
			min = seed;
		}
	}
	return min;

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

	cout << part1(fileToVector) << endl;
	cout << part2(fileToVector);
}
