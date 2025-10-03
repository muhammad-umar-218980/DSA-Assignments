#include <iostream>
#include <stack>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

void toBinary(int num){
	stack<int> st;
	
	while(num != 0){
		st.push(num%2);
		num/=2;
	}
	
	cout << endl;
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
}

int main(){
	int num ;
	cout << "Enter a number : ";
	cin >> num;
	
	if(num <0) cout << "\nCannot convert to binary";
	else if(num == 0) cout << 0;
	else toBinary(num);
	
	return 0;
}