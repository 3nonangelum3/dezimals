#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;

bool findSequence(const string fraction, string &sequence) {
	if (fraction.length() >= 4) {
		for (int i = 0; i < fraction.length(); i++)
		{
			string currentSeq = "";
			for (int j = fraction.length() / 2 + i; j < fraction.length(); j++)
			{
				currentSeq += fraction[j];
			}
			sequence = currentSeq;
		}
		return false;
	}
	return false;
}// 2 3 2 5 
//3 5 5 4 7 8 9 9 
int main()
{
	int counter = 0, denominator = 1, currentRest = 0;
	string result = "", sequence = "", integerOfFraction = "";
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
	currentRest = counter % denominator;
	int currentInteration = 0;
	for (int i = 0; i < 501 && !findSequence(result, sequence); i++)
	{
		currentRest *= 10;
		result += std::to_string(currentRest / denominator);
		currentRest %= denominator;
		currentInteration++;
		sequence = "";
	}
	if (sequence == "2173913043478260869565") {
		cout << true;
	}
}
//"0.(2173913043478260869565)"
