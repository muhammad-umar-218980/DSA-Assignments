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

class Queue{
private:
	Node* front;
	Node* rear;
	
public:
	Queue(){
		front = rear = nullptr;
	}
	
	void enqueue(int val){
		Node* n = new Node(val);
		if(isEmpty()) {
			front = rear = n;
			return;
		}
		
		rear->next = n;
		rear = n;
	}
	
	void dequeue(){
		if(isEmpty()){
			cout << "\nQueue is Empty\n";
			return;
		}
		
		Node* temp = front ;
		front=front->next;
		if (front == nullptr) rear = nullptr;
		temp->next = nullptr;
		delete temp;
	}
	
	bool isEmpty() {
		return front == nullptr;
	}
	
	int peek(){
		if(isEmpty()){
			cout << "\nQueue is empty ";
			return -1;
		}
		
		return this->front->data;
		
	}
	
	void print(){
		if(isEmpty()){
			cout << "\nQueue is empty ";
			return;
		}
		
		Node* current = front;
		cout << "\n\nQueue : ";
		while(current != nullptr){
			cout << current->data << " ";
			current = current->next;
		}
		
		cout << endl;
	}
};



int main(){
	Queue q;
	for(int i = 1 ; i <= 10;i++) q.enqueue(i);
	                                          
	q.print();
	
	for(int i=1 ; i <=3 ;i++) {
		cout << "\nPeek of Queue : " << q.peek();
		q.dequeue();
	}
	q.print();
	
	cout << "\nPeek of Queue : " << q.peek();
}
	
	                                          
