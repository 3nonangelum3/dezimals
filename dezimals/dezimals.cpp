#include <iostream>
using std::string;
using std::cout;
using std::cin;

bool findSequence(string fraction, string $sequence) {
	
}

int main()
{
	int counter = 0, denominator = 0;
	string result = "", sequence;
	do {
		cout << "Zahler/Counter: ";
		cin >> counter;
		cin.clear();
		cin.ignore(2e5, '\n');
	} while (counter && counter > 0 && !cin.fail());
	do {
		cout << "Nenner/Denominator: ";
		cin >> denominator;
		cin.clear();
		cin.ignore(2e5, '\n');
	} while (denominator && denominator > 0 && !cin.fail());
	while (!findSequence(result, sequence)) {

	}
}
