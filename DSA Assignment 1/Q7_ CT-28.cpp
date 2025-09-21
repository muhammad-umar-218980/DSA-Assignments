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

class CircularList{
private:
	Node* head;
	Node* tail;
	
public:
	CircularList(){
		head = tail = nullptr;
	}
	
	void push_front(int val){
		Node* n = new Node(val);
		if(isEmpty()){
			head = tail = n;
			tail->next = head;
			return;
		}
		
		n->next = head;
		head = n;
		tail->next = head;
	}
	
	
	void push_back(int val){
		Node* n = new Node(val);
		if(isEmpty()){
			head = tail = n;
			tail->next = head;
			return;
		}
		
		n->next = head;
		tail->next = n;
		tail = n;
	}
	
	void insertByPosition(int pos , int val){
		
		if(pos <= 0){
			cout << "\nInvalid Position\n";
			return ;
		}
		
		if(pos == 1){
			this->push_front(val);
			return;
		}
		
		int idx = 1;
		Node* current = head;
		while(current->next != head && idx < pos-1){
			current = current->next;
			idx++;
		}
		
		if(idx != pos - 1){
			cout << endl << pos << " is an Invalid position\n";
			return;
		}
		
		if(current == tail){
			this->push_back(val);
			return;
		}
		
		Node* n = new Node(val);
		n->next = current->next;
		current->next = n;
	}	
	
	void insertAfterNode(int key , int val){
		if(isEmpty()){
			cout << "Circular List is Empty\n";
			return;
		}
		
		Node* temp = head;
		int position = 1;
		bool found = false;
		
		do{
			if(temp->data == key){
				found = true;
				break;
			}
			temp = temp->next;
			position++;
		}while(temp != head);
		
		if(found != true){
			cout << endl << key << "not found in the list\n\n";
			return;
		}
		
		
		this->insertByPosition(position+1,val);
	}
	
	void print(){
		if(isEmpty()){
			cout << "Circular List is empty\n\n";
			return;
		}
		
		Node* temp = head;
		do{
			cout << temp->data << " -> ";
			temp = temp->next;
		}while(temp != head);
		
		cout <<"(back to head)\n\n";
	}
	
	bool isEmpty(){
		return head == nullptr;
	}
};


int main(){
	
	// Printing Empty Linked List
	CircularList cl;
	cl.print();
	
	// Inserting Nodes from 5-1 from start
	for(int i = 5 ; i >= 1 ; i--) cl.push_front(i);
	cl.print();
	
	
	// Inserting Nodes from 6-10 from end
	for(int i = 6 ; i <= 10 ;i++) cl.push_back(i);
	cl.print();
	
	
	int value , position , key;
	
	// Inserting 100 at invalid position like 20
	
	value = 100; position = 20;
	
	cl.insertByPosition(position,value);
	cout << "\n\n";
	
	
	
	
	// Inserting 100 at a valid position like 4
	
	value = 100; position = 4;
	
	cl.insertByPosition(position,value);
	cout << "\nList After inserting " << value << " at position " << position << " : \n";
	cl.print();
	
	
	// Inserting 65 at position 1
	
	value = 65; position = 1;
	
	cl.insertByPosition(position,value);
	cout << "\nList After inserting " << value << " at position " << position << " (head) : \n\n";
	cl.print();
	
	
	// Inserting 50 at position 2
	
	value = 50; position = 2;
	
	cl.insertByPosition(position,value);
	cout << "\nList After inserting " << value << " at position " << position << " : \n\n";
	cl.print();
	
	
	// Inserting 200 at tail
	
	value = 200; position = 14;
	
	cl.insertByPosition(position,value);
	cout << "\nList After inserting " << value << " at position " << position << " (tail) : \n\n";
	cl.print();
	
	
	
	
	// Inserting after a specific node like 3
	
	value = 1000; key = 3;
	
	cl.insertAfterNode(key,value);
	cout << "\nList After inserting " << value << " after a node whose key is " << key << " : \n\n";
	cl.print();
	
	
	// Inserting after a specific node like head
	
	value = 700; key = 65;
	
	cl.insertAfterNode(key,value);
	cout << "\nList After inserting " << value << " after head node whose key is " << key << " : \n\n";
	cl.print();
	
	
	// Inserting after a specific node like tail
	
	value = 2500; key = 200;
	
	cl.insertAfterNode(key,value);
	cout << "\nList After inserting " << value << " after tail node whose key is " << key << " : \n\n";
	cl.print();
	
	
	return 0;
}

