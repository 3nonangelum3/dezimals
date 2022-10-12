#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

bool compareStrings(string s1, string s2) {
	if (s1.length() == s2.length())
	{
		for (int i = 0; i < s1.length(); i++)
		{
			if (s1[i] != s2[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

bool findSequence(const string fraction, string &sequence) {
	if (fraction.length() >= 4) {
		for (int i = 0; i < fraction.length(); i++)
		{
			string currentSeq = "";
			for (int j = fraction.length() / 2 + i; j < fraction.length(); j++)
				currentSeq += fraction[j];
			for (int i = 0; i < fraction.length(); i++)
			{
				if (currentSeq.length() == 1) {
					if (compareStrings(std::to_string(fraction[fraction.length() - 2]), currentSeq) &&
						compareStrings(std::to_string(fraction[fraction.length() - 3]), currentSeq))
					{
						sequence = currentSeq;
						return true;
					}
				}
				else {
					if (fraction[i] == currentSeq[0]) {
						string fractionPart = "";
						int index = fraction.length() - 2 * (currentSeq.length());
						if (index < 0) index = 0;
						for (int g = 0; g < currentSeq.length(); g++)
							fractionPart += fraction[index + g];
						if (compareStrings(currentSeq, fractionPart))
						{
							sequence = currentSeq;
							return true;
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
		return false;
	}
	return false;
}

string deleteStringInString(string s1, string s2) {
	string result = "";
	int seqStartIndex = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[seqStartIndex])
		{
			if (seqStartIndex >= s2.length())
				return result;
			else
				seqStartIndex++;
		}
		else
		{
			if (seqStartIndex == 0)
			{
				for (int j = 0; j <= seqStartIndex; j++)
					result += s2[j];
				seqStartIndex = 0;
			}
			else {
				result += s1[i];
			}
		}
	}
}

int main()
{
	int counter = 0, denominator = 1, currentRest = 0;
	string result = "", sequence = "", integerOfFraction = "0";
	do {
		cout << "Zahler/Counter: ";
		cin >> counter;
		cin.clear();
		cin.ignore(2e5, '\n');
	} while (counter > 0 && cin.fail());
	do {
		cout << "Nenner/Denominator: ";
		cin >> denominator;
		cin.clear();
		cin.ignore(2e5, '\n');
	} while (denominator > 0 && cin.fail());
	integerOfFraction = "" + (counter / denominator);
	if (integerOfFraction == "") {
		integerOfFraction = "0";
	}
	currentRest = counter % denominator;
	for (int i = 0; i < 501; i++)
	{
		currentRest *= 10;
		result += std::to_string(currentRest / denominator);
		currentRest %= denominator;
		sequence = "";
		if (findSequence(result, sequence))
			break;
		else
			sequence = "";
	}
	while (result.find(sequence) >= 0 && result.length() >= sequence.length())
	{
		int index = result.find(sequence);
		result = result.replace(index, index + sequence.length(), "");
	}
	cout << "result: " << integerOfFraction << "," << result <<
		"(" << sequence << ")";
}
//"0.(2173913043478260869565)"