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
private:
	Node* head;
	Node* tail;
	
public:
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
		
		cout << "nullptr\n\n";
	}
	
	bool isEmpty(){
		return head == nullptr;
	}
	
	friend bool hasDuplicate(List& l1);
};

bool hasDuplicate(List& l1){
	for(Node* i = l1.head ; i != nullptr ; i = i->next){
		for(Node* j = i->next ; j != nullptr ;  j = j->next){
			if(i->data == j->data){
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	List l1;
	
	// Adding elements in list1 from 1-10
	for(int i = 1 ; i <= 10 ; i++) l1.push_back(i);
	l1.print();
	
	// Adding elements in the list1 from 10-15 so that 10 is duplicate
	for(int i = 10 ; i <= 15 ; i++) l1.push_back(i);
	l1.print();
	
	if(hasDuplicate(l1)){
		cout << "Duplicate found in list1\n\n";
	}else{
		cout << "No Duplicates found in list1\n\n";
	}
	
	
	
	
	
	
	List l2;
	// Adding elements in list2 from 50-56
	cout<< "List 2:\n";
	for(int i = 50 ; i <= 56 ; i++) l2.push_back(i); 
	l2.print();
	
	// No duplicate 
	if(hasDuplicate(l2)){
		cout << "Duplicate found in list2\n";
	}else{
		cout << "No Duplicates found in list2\n";
	}
	
	
	return 0;
}