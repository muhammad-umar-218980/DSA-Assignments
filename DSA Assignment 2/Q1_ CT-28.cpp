#include <iostream>
#include <stack>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

bool isValidBracket(string s){
	stack<char> stringStack;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '{' || s[i] == '[' || s[i] == '(' ) stringStack.push(s[i]);
		else{
			if(stringStack.empty()) return false;
			
			if((s[i] == '}' && stringStack.top() != '{') ||
			(s[i] == ']' && stringStack.top() != '[')  ||
			(s[i] == ')' && stringStack.top() != '(') ) return false;
			else stringStack.pop();
		}
		
	}
	return stringStack.empty();
}

int main(){
	
	string s;
	cout << "\nEnter the string for brackets : ";
	getline(cin,s);
	
	isValidBracket(s) ? cout << "\nBrackets are valid" : cout << "\nBrackets are not valid";
	
	return 0;
}