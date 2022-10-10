#include <iostream>
using std::string;
using std::cout;
using std::cin;

bool findSequence(const string fraction, string $sequence) {
	if (fraction.length() >= 2) {
		for (int i = 0; i < fraction.length() / 2; i++)
		{
			string currentSeq = "";
			for (int j = fraction.length() - 1; j > fraction.length() - i - 1; j--)
			{
				currentSeq += fraction[j];
			}
			$sequence = currentSeq;
		}
	}
	return false;
}

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
	while (!findSequence(result, sequence) && currentInteration <= 500) {
		currentRest *= 10;
		result += currentRest / denominator;//fuck
		currentRest %= denominator;
		currentInteration++;
		sequence = "";
	}
}
