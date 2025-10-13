#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

string reverse(string s, int start, int end) {
	if(start >= end) return s;
	
	swap(s[start], s[end]);
	return reverse(s, start + 1, end - 1);
}

int main() {
	
	string s;
	cout << "Enter the string to reverse : ";
	getline(cin, s);
	
	string reversedString = reverse(s, 0, s.size() - 1);

	cout << "\nReversed string : " << reversedString;
	
	return 0;
}
