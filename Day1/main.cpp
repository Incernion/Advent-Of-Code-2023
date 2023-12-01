#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int getFirstAndlast(string str)
{
	auto len = str.length();
	string numInStr;
	char temp = '\0';

	for (char ch : str)
	{
		if (isdigit(ch) != 0)
		{
			if (numInStr.empty())
				numInStr += ch;
			else
				temp = ch;
		}
	}

	if (temp != NULL)
		numInStr += temp;

	if (numInStr.length() == 1)
		numInStr += numInStr;
	return stoi(numInStr);
}

int WordsToInts(string& str)
{
	string numbersInStr[]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string RevnumbersInStr[]{ "orez", "eno", "owt", "eerht", "ruof", "evif", "xis", "neves", "thgie", "enin" };
	string strCopy = str;

	int firstValue = 0;
	int lastValue = 0;

	string addString;
	for (char ch : strCopy)
	{
		addString += ch;
		if (isdigit(ch) != 0)
		{
			firstValue = ch - '0';
			break;
		}
		for (size_t i = 0; i < 10; i++)
		{
			if (addString.find(numbersInStr[i]) != string::npos) // number word was found.
			{
				firstValue = i;
				goto second_part;
			}
		}
	}
second_part:
	addString.clear();
	for (size_t i = strCopy.length() - 1; i >= 0; i--)
	{
		char ch = str[i];

		addString += ch;
		if (isdigit(ch) != 0)
		{
			lastValue = ch - '0';
			goto third_part;
		}
		for (size_t i = 0; i < 10; i++)
		{
			if (addString.find(RevnumbersInStr[i]) != string::npos) // number word was found.
			{
				lastValue = i;
				goto third_part;
			}
		}
	}

	third_part:	

	//cout << firstValue << "  " << lastValue;
	return stoi(to_string(firstValue) + to_string(lastValue)) ;
}



int main()
{
	fstream file;
	file.open("controls.txt");
	string line;
	int sum = 0;
	int sum2 = 0;

	while (getline(file, line))
	{
		sum += getFirstAndlast(line);
		sum2 += WordsToInts(line);
	}
	cout << "Challenge 1:" << endl;
	cout << sum << endl;
	cout << "Challenge 2:" << endl;
	cout << sum2;
}