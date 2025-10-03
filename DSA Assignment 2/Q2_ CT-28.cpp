#include <iostream>
#include <stack>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

string reverse(string s){
	stack<char> st;
	for(int i = 0 ; i < s.size() ;i++) st.push(s[i]);
	
	for(int i = 0 ; i < s.size() ;i++) {
		s[i] = st.top();
		st.pop();
	}
	
	return s;
	
}

int main(){
	
	string s;
	cout << "\nEnter the string to reverse : ";
	getline(cin,s);
	
	s = reverse(s);
	
	cout << "\nReversed String : " << s;
	
	return 0;
}