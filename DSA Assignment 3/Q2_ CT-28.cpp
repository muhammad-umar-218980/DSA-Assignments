#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

int sumOfDigits(int num){
	if (num <= 0) return 0;
	
	int lastDigit = num%10;
	return lastDigit + sumOfDigits(num/10);
}

int main() {
	
	int num;
	cout << "Enter a number: ";
	cin >> num;
	
	cout << "\nSum of digits is: " << sumOfDigits(num);
	
	return 0;
}
