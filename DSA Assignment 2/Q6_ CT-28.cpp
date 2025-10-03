#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Roll no. : CT - 24028
	Class : CSIT Section A Batch 24
*/

class Node{
public: 
	int data;
	int minVal;
	Node* next;
	
	Node(int data){
		this->data = data;
		next = nullptr;
	}
};

class Stack{
private:
	Node* top;
	
public:
	Stack() {
		top = nullptr;
	}
	
	void push(int val){
		Node* n = new Node(val);
		if(empty()) {
			n->minVal = val;
			top = n;
			return;
		}
		
		if(val < top->minVal) n->minVal = val;
		else n->minVal = top->minVal;
		
		n->next = top;
		top = n;		
	}
	
	int pop(){
		if(empty()) return -1;
		
		int value = top->data;
		Node* temp = top;
		top = top->next;
		delete temp;
		return value;
	}
	
	bool empty(){
		return top == nullptr;
	}
	
	int getMin() {
		if(empty()) return -1;
		return top->minVal;
	}
	
	void print(){
		if(empty()){
			cout << "\nStack is empty ";
			return;
		}
		
		Node* current = top;
		cout << "\nStack : \n";
		while(current != nullptr){
			cout << current->data << endl;
			current = current->next;
		}
	}
};

int main(){
	Stack st;
	for(int i = 1 ; i <= 10 ;i++) st.push(i);
	
	st.print();
	
	cout << "\nMinimum value in stack is : " << st.getMin() <<endl;
	
	st.push(-100);
	st.print();
	cout << "\nMinimum value in stack is : " << st.getMin();
	
	st.pop();
	st.print();
	cout << "\nMinimum value in stack is : " << st.getMin();
	
	return 0;
}
