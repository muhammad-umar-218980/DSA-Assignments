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
	
	
	List findMiddle(){
		
		List result;
		
		if(head == nullptr){
			return result;
		}
		
		if(head->next == nullptr){
			result.push_back(head->data);
			return result;
		}
		
		Node* fast = head;
		Node* slow = head;
		Node* prevSlow = nullptr;
		
		while(fast != nullptr && fast->next != nullptr){
			fast = fast->next->next;
			
			prevSlow = slow;
			slow = slow->next;
		}
		
		if(fast == nullptr){
			result.push_back(prevSlow->data);
		}
		
		result.push_back(slow->data);
		return result;
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
	
	void printMiddle(){
		if(isEmpty()){
			cout << "List is empty\n";
			return;
		}
		
		if(head->next != nullptr){
			cout << head->data << " and " << head->next->data;
		}else{
			cout << head->data;
		}
	}
	
	
	bool isEmpty(){
		return head == nullptr;
	}
};

int main(){
	
	// List with even number of nodes (has 2 middles)
	List l1;
	cout << "List 1 : \n";
	for(int i = 1 ; i <= 6 ; i++) l1.push_back(i);
	l1.print();
	
	List mids1 = l1.findMiddle();
	cout << "\nMiddle nodes are : ";
	mids1.printMiddle();
	cout << "\n";
	
	
	
	
	// List with odd number of nodes (has 1 middle)
	List l2;
	cout << "\n\nList 2 : \n";
	for(int i = 1 ; i <= 7 ; i++) l2.push_back(i);
	l2.print();
	
	List mids2 = l2.findMiddle();
	cout << "\nMiddle node is : ";
	mids2.printMiddle();
	return 0;
}
