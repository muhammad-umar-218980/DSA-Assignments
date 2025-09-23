#include <iostream>
using namespace std;

/*
    Name : Muhammad Umar
    Roll no. : CT - 24028
    Class : CSIT Section A Batch 24
*/

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class List {
public:
    Node* head;
    Node* tail;
    List() {
        head = tail = nullptr;
    }

    void push_back(int val) {
        Node* n = new Node(val);
        if (isEmpty()) {
            head = tail = n;
            return;
        }
        tail->next = n;
        tail = n;
    }

    void print() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n\n";
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void removeNodes(int n) {
    	
    	if (n <= 0) return;
    	
        for (int i = 0; i < n && head != nullptr; i++) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        if (head == nullptr) {
            tail = nullptr; 
        }
    }
};

int main() {
    List l;

    for(int i = 1 ; i <= 30 ;i++) l.push_back(i);

    cout << "\nOriginal list:\n";
    l.print();
    
    cout << "\n\nEnter the number of nodes you want to remove : ";
    int n; cin >>n;
    
    l.removeNodes(n);
    l.print();

    return 0;
}
