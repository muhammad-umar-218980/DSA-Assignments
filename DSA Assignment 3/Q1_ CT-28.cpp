#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/


long long int factorial(int n){
	if(n <= 1) return 1;
	
	return n * factorial(n-1);
}


int main(){
	
	int num;
	cout << "Enter the number to find the factorial of : ";
	cin >> num;
	
	cout << "\nFactorial of " << num << " is : " << factorial(num);
	
	return 0;
}