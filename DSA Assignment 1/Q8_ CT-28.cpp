#include <iostream>
using namespace std;

/*
	Name : Muhammad Umar
	Class : CSIT Section A Batch 24
	Roll no. : CT - 24028
*/

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = tail = nullptr;
    }

	void push_back(int val){
		Node* n = new Node(val);
		if(isEmpty()){
			head = tail = n;
			return;
		}
		
		tail->next = n ;
		n->prev = tail ;
		tail = n;
	}
	
	void deleteNode(Node* node){
		if(node == nullptr){
			cout << "Node is Null\n\n";
			return;
		}
		
		if(node == head){
			head = head->next;
		}
		
		if(node == tail){
			tail = tail->prev;
		}
		
		if(node->prev != nullptr){
			node->prev->next = node->next;
		}
		
		if(node->next != nullptr){
			node->next->prev = node->prev;
		}
		
		delete node;
	}

    void print() {
    	if(isEmpty()){
    		cout << "Doubly List is Empty\n";
    		return;
		}
		
        Node* temp = head;
        cout << "\n\nnullptr <-> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "nullptr\n\n";
    }
    
    bool isEmpty() {
		return head == nullptr;
	}
};

int main() {
    DoublyLinkedList dll;

    for(int i = 10 ; i <=100 ; i+=10) dll.push_back(i);

    cout << "Original list: ";
    dll.print();
    
    
    // Deleting head node
    cout << "\n\nAfter deleting head node : \n";
    dll.deleteNode(dll.head);
    dll.print();
    
    
    // Deleting tail node
    cout << "\n\nAfter deleting tail node : \n";
    dll.deleteNode(dll.tail);
    dll.print();
    
    
    // Deleting a random node from head
    cout << "\n\nAfter deleting a random node like the 3rd node from head: \n";
    dll.deleteNode(dll.head->next->next);
    dll.print();
    
    
    
    // Deleting a random node from tail
    cout << "\n\nAfter deleting a random node like the 3rd node from tail: \n";
    dll.deleteNode(dll.tail->prev->prev);
    dll.print();

	
    return 0;
}
