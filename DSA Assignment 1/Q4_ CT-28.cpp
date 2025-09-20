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
	Node* next;
	Node(int data){
		this->data = data;
		next = nullptr;
	}	
};

class List{
public:
	Node* head;
	Node* tail;
	List(){
		head = tail = nullptr;
	}
	
	void push_back(int val){
		Node* n = new Node(val);
		if(isEmpty()){
			head = tail = n;
			return;
		}
		tail->next = n;
		tail = n;
	}
	
	void reverse(){
		if(isEmpty()){
			cout << "List is Empty\n";
			return ;
		}
		
		Node* prev = nullptr;
		Node* current = head;
		Node* nextPtr = nullptr;
		
		while(current != nullptr){
			nextPtr = current->next;
			current->next = prev;
			
			prev = current;
			current = nextPtr;
		}
		
		this->tail = head;
		this->head = prev;
	}
	
	void print(){
		if(isEmpty()){
			cout << "List is empty\n";
			return;
		}
		Node* temp = head;
		while(temp != nullptr){
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr\n";
	}
	
	bool isEmpty(){
		return head == nullptr;
	}
};

int main(){
	
	List l1;
	for(int i = 1 ; i <= 9 ;i++) l1.push_back(i);
	
	l1.print();
	
	cout << "\n\nReverse of list 1  :\n\n";
	l1.reverse();
	l1.print();
	
	// Again adding nodes from 20-25 in list 1
	cout << "\n\nUpdated list 1 :\n\n";
	for(int i = 20 ; i <= 25 ;i++) l1.push_back(i);
	l1.print();
	
	
	cout << "\n\nReverse of updated list 1 :\n\n";
	l1.reverse();
	l1.print();
	return 0;
}
