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
        next = prev = nullptr;
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
		tail->next = n;
		n->prev = tail;
		tail = n;
	}

    void reverse() {
        if (head == nullptr || head->next == nullptr) return;

        Node* prevNode = nullptr;
        Node* currNode = head;

        while (currNode != nullptr) {
        	
            prevNode = currNode->prev;
            currNode->prev = currNode->next;
            currNode->next = prevNode;
            
            
            currNode = currNode->prev;
        }

        tail = head;
        head = prevNode->prev;
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

    dll.reverse();
    cout << "Reversed list: ";
    dll.print();

    return 0;
}
