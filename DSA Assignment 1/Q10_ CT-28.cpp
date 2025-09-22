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
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class CircularList {
public:
    Node* head;
    Node* tail;
    int size;   

    CircularList() {
        head = tail = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        size++;
        if (isEmpty()) {
            head = tail = newNode;
            tail->next = head; 
            return;
        } 
        
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }


    void rotate(int k) {
        if (isEmpty() || head->next == head || k == 0) return;

        k = k % size;
        if (k == 0) return;


        Node* current = head;

        for (int i = 1; i < size-k; i++) {
            current = current->next;
        }

        head = current->next;
        tail = current;
    }

    void print() {
        if (isEmpty()) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        
        cout << "(back to head)" << endl;
    }
};

int main() {
    CircularList cl;
    
    int n , k;
    cout << "Enter the number of elements for linked list : ";
    cin >> n;
    
    cout << "\nEnter the kth position for rotation : ";
    cin >> k;

    for (int i = 1; i <= n; i++) {
        cl.push_back(i);
    }

    cout << "\nOriginal list: ";
    cl.print();

    cl.rotate(k);

    cout << "\nRotated list: ";
    cl.print();

    return 0;
}
