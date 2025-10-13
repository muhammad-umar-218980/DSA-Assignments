#include <iostream>
#include <string>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

/*-------------------------------------------------------------
   Function A: factorial(n)
   Type: Non-Tail Recursion

   Explanation:
   - The recursive call to factorial(n - 1) is NOT the last step.
   - After returning from the recursive call, multiplication by 'n'
     is performed.
   - Hence, this is an example of Non-Tail Recursion.
-------------------------------------------------------------*/
int factorial(int n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1); // Work (multiplication) done after recursion
}

/*-------------------------------------------------------------
   Function B: is_even(n) and is_odd(n)
   Type: Indirect Recursion

   Explanation:
   - The function is_even() calls is_odd().
   - The function is_odd() calls is_even().
   - They call each other alternately until base condition is met.
   - Hence, this is Indirect Recursion.
-------------------------------------------------------------*/
bool is_even(int n);
bool is_odd(int n);

bool is_even(int n) {
	if (n == 0) return true;
	return is_odd(n - 1); // calls another function
}

bool is_odd(int n) {
	if (n == 0) return false;
	return is_even(n - 1); // calls back the first function
}

/*-------------------------------------------------------------
   Function C: reverseString()
   Type: Tail Recursion

   Explanation:
   - The recursive call is the LAST statement in the function.
   - No operation is performed after the recursive call returns.
   - Hence, it is Tail Recursion.
-------------------------------------------------------------*/
void reverseString(string s, int index) {
	if (index < 0) return;
	cout << s[index];
	reverseString(s, index - 1); // last statement ? Tail Recursion
}


int main() {
	
	int n;
	cout << "Enter a number for factorial: ";
	cin >> n;

	cout << "\nFunction A: factorial(" << n << ")\n";
	cout << "Result: " << factorial(n) << endl;
	cout << "Type: Non-Tail Recursion (work after recursive call)\n";

	cout << "\nFunction B: is_even() and is_odd()\n";
	cout << n << " is " << (is_even(n) ? "Even" : "Odd") << endl;
	cout << "Type: Indirect Recursion (mutual calling between two functions)\n";

	string str;
	cout << "\nEnter a string to reverse: ";
	cin.ignore();
	getline(cin,str);

	cout << "Reversed string: ";
	reverseString(str, str.length() - 1);
	cout << "\nType: Tail Recursion (recursive call is the last step)\n";

	return 0;
}
