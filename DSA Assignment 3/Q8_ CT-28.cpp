#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

/*-------------------------------------------------------------
   1. DIRECT RECURSION
   - The function calls itself directly.
   - Example: Printing numbers from n down to 1.
-------------------------------------------------------------*/
void directRecursion(int n) {
	if (n == 0) return;
	cout << n << " ";
	directRecursion(n - 1); // Function calls itself directly
}

/*-------------------------------------------------------------
   2. INDIRECT RECURSION
   - Function A calls Function B, and Function B calls Function A.
   - Example: Two functions calling each other alternately.
-------------------------------------------------------------*/
void functionB(int n); // forward declaration

void functionA(int n) {
	if (n <= 0) return;
	cout << n << " ";
	functionB(n - 1); // functionA calls functionB
}

void functionB(int n) {
	if (n <= 0) return;
	cout << n << " ";
	functionA(n - 1); // functionB calls functionA (indirect recursion)
}

/*-------------------------------------------------------------
   3. TAIL RECURSION
   - Recursive call is the last operation in the function.
   - No pending operations after the recursive call.
   - Example: Printing numbers from 1 to n.
-------------------------------------------------------------*/
void tailRecursion(int n, int i = 1) {
	if (i > n) return;
	cout << i << " ";
	tailRecursion(n, i + 1); // Recursive call is last (tail recursion)
}

/*-------------------------------------------------------------
   4. NON-TAIL RECURSION
   - Recursive call is not the last operation.
   - Some work is done after the recursive call returns.
   - Example: Printing numbers from 1 to n using recursion.
-------------------------------------------------------------*/
void nonTailRecursion(int n) {
	if (n == 0) return;
	nonTailRecursion(n - 1); // Recursive call first
	cout << n << " ";        // Work after recursion (non-tail recursion)
}

int main() {

	int n;
	cout << "Enter a number: ";
	cin >> n;

	cout << "\n1. Direct Recursion (n to 1):\n";
	directRecursion(n);

	cout << "\n\n2. Indirect Recursion (A and B alternate calls):\n";
	functionA(n);

	cout << "\n\n3. Tail Recursion (1 to n):\n";
	tailRecursion(n);

	cout << "\n\n4. Non-Tail Recursion (1 to n):\n";
	nonTailRecursion(n);

	cout << endl;
	return 0;
}
