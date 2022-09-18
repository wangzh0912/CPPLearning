#include <iostream>

using namespace std;

int main() {
	int		n10Dollar, n20Dollar, n50Dollar, n100Dollar, n500Dollar, bill;
	int		c10, c20, c50, c100, c500;

	// Original number of coins in pocket
	cout << "Original number of bills in wallet:" << endl;
	cout << "Number of 10-Dollar bills: "; cin >> n10Dollar;
	cout << "Number of 20-Dollar bills: "; cin >> n20Dollar;
	cout << "Number of 50-Dollar bills: "; cin >> n50Dollar;
	cout << "Number of 100-Dollar bills: "; cin >> n100Dollar;
	cout << "Number of 500-Dollar bills: "; cin >> n500Dollar;
	cout << endl;

	// Bill to pay.
	// Assume bill amount is a whole integer multiples of 10
	cout << "Bill Amount : "; cin >> bill;
	cout << endl;

	// Fill in the code to calculate payment in terms of number of x-Dollar bills.
	// If not enough money, number of x-Dollar bills in payment should all be 0s.
	// Bill should be settled in exact amount; otherwise, number of x-Dollar bills 
	// in payment should all be 0s. 

	c10 = 0; c20 = 0; c50 = 0; c100 = 0; c500 = 0;

	// TODO

	cout << "Payment:" << endl;
	cout << "Number of 10-Dollar bills: " << c10 << endl;
	cout << "Number of 20-Dollar bills: " << c20 << endl;
	cout << "Number of 50-Dollar bills: " << c50 << endl;
	cout << "Number of 100-Dollar bills: " << c100 << endl;
	cout << "Number of 500-Dollar bills: " << c500 << endl;
	return 0;
}