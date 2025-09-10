#include <iostream>

using namespace std;

int factorial(int n);
int power(int base, int exponent);
int sum_digits(unsigned n);
int b_counter(char data[], int length, int i);
int string_length(char* data);
int main()
{
	int choice;
	cout << "Please choose an option: " << endl;
	cout << "1. Calculate Factorial" << endl;
	cout << "2. Calculate Power" << endl;
	cout << "3. Calculate sum_digits" << endl;
	cout << "4. return b_counter" << endl;
	cout << "5. string length" << endl;
	cout << "Please enter your choice (1-5): ";
	cin >> choice;
	int number;

	//Factorial calculation
	if (choice == 1) {
		cout << " Please enter a postive integer: " << endl;
		cin >> number;

		int result = factorial(number);
		if (result == -1)
		{
			cout << "Error! Factorial of a negative number doesn't exist." << endl;
		}
		else {
			cout << "Factorial of " << number << " is " << result << endl;
		}
	}  //Calculate Powers
	else if (choice == 2) {
		int base, exponent;
		cout << "Enter base: ";
		cin >> base;
		cout << "Please enter a random exponent: ";
		cin >> exponent;
		int result = power(base, exponent);
		cout << base << " is raised to the power of " << exponent << " is " << result << endl;

	}
	//returns the sum of the digits of a number that is inputed
	else if (choice == 3) {
		unsigned number;
		cout << " Please enter a postive integer and not a negative integer: " << endl;
		cin >> number;
		cout << "The sum of the digits in " << number << " is " << sum_digits(number) << endl;
	}
	// counts the number of b's in a character array
	else if (choice == 4) {
		char data[100];
		cout << "Please enter a character array (Max is 100) ";
		cin >> data;
		int length = 0;
		while (data[length] != '\0') {
			length++;
		}
		int result = b_counter(data, length, 0);
		cout << "Number of 'b' characters: " << result << endl;
	}
	//returns the lenght of a string that is inputed
	else if (choice == 5)
	{
		char data[100];
		cout << "Please enter a string; ";
		cin >> data;
		int result = string_length(data);
		cout << "The string length is: " << result << endl;
	}
	else { // used when an invalid choice is inputed
		cout << "You chose an invalid choice." << endl;
	}
	return 0;

}

int sum_digits(unsigned n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int power(int base, int exponent)
{
	if (exponent < 0) { //simplifies the code, also returns 0 for negative exponents
		return 0;
	}
	if (exponent == 0) {
		return 1;
	}
	return base * power(base, exponent - 1);
}

int factorial(int n)
{
	if (n < 0) {
		return -1; // This will indicate an error for a negative input if inputed
	}
	if (n == 0 || n == 1) {
		return 1;
	}
	return n * factorial(n - 1);
}
int b_counter(char data[], int length, int i)
{
	if (i >= length) {
		return 0;
	}
	int count = (data[i] == 'b') ? 1 : 0;
	return count + b_counter(data, length, i + 1);
}
int string_length(char* data)
{
	if (*data == '\0') {
		return 0;
	}
	return 1 + string_length(data + 1);
}