#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void binPacking(vector<int> numbers)
{
	vector<int> bins;
	bins.push_back(0);

	int numberToAdd = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		int min = 10;
		int binPlacement = 0;

		for (int j = 0; j < bins.size(); j++)
		{
			int temp = 10 - numbers[i] - bins[j];

			if (temp < min && temp >= 0)
			{
				min = temp;
				binPlacement = j;
				numberToAdd = numbers[i];
			}
		}
		if (min == 10)
		{
			bins.push_back(numbers[i]);
		}
		else
		{
			bins[binPlacement] = bins[binPlacement] + numberToAdd;
		}
	}
	for (int i = 0; i < bins.size(); i++)
	{
		cout << bins[i] << " ";
	}
}

int main()
{
	vector<int> numbers;
	string line;

	getline(cin, line);
	istringstream stream(line);

	int tempNum = 0;
	// Input a line of numbers through the terminal.
	while (stream >> line)
	{
		tempNum = stoi(line);
		numbers.push_back(tempNum);
	}
	// Or just push back a bunch of numbers into the vector.

	binPacking(numbers);

	return 0;
}