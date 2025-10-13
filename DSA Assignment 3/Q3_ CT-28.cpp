#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

int fibonacci(int n){
	if (n==0||n==1) return n;
	
	return fibonacci(n-1)+fibonacci(n-2);
}


int main() {
	
	int n;
	cout << "Enter the position (n): ";
	cin >> n;
	
	cout << "\nThe " << n << "th Fibonacci number is: " << fibonacci(n);

	
	return 0;
}
