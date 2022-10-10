#include <iostream>
using std::string;
using std::cout;
using std::cin;

bool findSequence(string fraction) {
	return true;
}

int main()
{
	/*int counter = 0, denominator = 0;
	string result = "";
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
	while (!findSequence(result)) {

	}*/
	for (int i = 1; i < 1898; i++)
	{
		if (!(1898 % i))
		{
			cout << i << " ";
		}
	}
	cout << '\n';
	for (int i = 1; i < 925; i++)
	{
		if (!(925 % i))
		{
			cout << i << ' ';
		}
	}
}
