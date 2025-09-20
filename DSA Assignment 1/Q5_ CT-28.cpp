#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
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


class LinkedList{
public:
	Node* head;
	Node* tail;
	
	LinkedList(){
		head = nullptr;
		tail = nullptr;
	}
	
	void push_back(int val){
		Node* n = new Node(val);
		if(head == nullptr){
			head = n ;
			tail = n;
			return;
		}
		
		tail->next = n;
		tail = n;
	}
	
	void print(Node* obj){
		if(obj == nullptr){
			cout << "List is empty";
			return;
		}
		
		while(obj != nullptr){
			cout << obj->data << " -> ";
			obj = obj->next;
		}
		
		cout << "nullptr\n\n";
	}
	
	Node* mergeLists(Node* l1head , Node* l2head){
		if(l1head == nullptr) return l2head;
		
		if(l2head == nullptr) return l1head;
		
		Node* temp = new Node(0);
		Node* prev = temp;
		
		while(l2head != nullptr && l1head != nullptr){
			if(l1head->data <= l2head->data){
				prev->next = l1head;
				l1head = l1head->next;
			}else {
				prev->next = l2head;
				l2head = l2head->next;
			}
			
			prev = prev->next;
		}
		
		if(l1head != nullptr) prev->next = l1head;
		
		if(l2head != nullptr) prev->next = l2head;
		
		Node* result = temp->next;
		delete temp;
		return result;
	}

};

int main(){
	
	LinkedList l1;
	// Adding even number nodes to linked list 1
	for(int i = 2 ; i <= 10 ;i+=2){
		l1.push_back(i);
	}
	
	cout << "\nList 1:\n\n";
	l1.print(l1.head);
	
	
	
	
	
	LinkedList l2;
	
	// Adding odd number nodes to linked list 2
	for(int i = 1 ; i <= 9 ; i+=2){
		l2.push_back(i);
	}
	
	cout << "\nList 2:\n\n";
	l2.print(l2.head);
	
	
	
	// Sorted Merged List for list 1 and list 2
	LinkedList MergedList;
	Node* result = MergedList.mergeLists(l1.head,l2.head);
	
	cout << "\n\nSorted Merged List : List1 + List2:\n\n";
	MergedList.print(result);
	
	
	
	return 0;
}