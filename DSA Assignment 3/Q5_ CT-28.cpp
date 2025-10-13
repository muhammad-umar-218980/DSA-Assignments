#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

bool isPalindrome(string s, int start, int end) {
	if(start >= end) return true;
	
	if(s[start] != s[end]) return false;
	
	return isPalindrome(s, start + 1, end - 1);
}

int main() {
	
	string s;
	cout << "Enter a string: ";
	getline(cin, s);
	
	bool isPal = isPalindrome(s,0,s.size()-1);
	
	isPal ? cout << endl << s << " is a Palindrome string " : cout << endl << s << " is not a Palindrome string ";
	
	return 0;
}
