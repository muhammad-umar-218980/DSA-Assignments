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

class Stack {
private:
    Node* top;
    int minVal;

public:
    Stack() {
        top = nullptr;
        minVal = INT_MAX;
    }

    void push(int val) {
        Node* n = new Node(val);

        if (empty()) minVal = val;
        else minVal = min(val, minVal);

        n->next = top;
        top = n;
    }

    int pop() {
        if (empty()) return -1;

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        if (!empty()) {
            Node* current = top;
            minVal = current->data;
            while (current != nullptr) {
                minVal = min(minVal, current->data);
                current = current->next;
            }
        } else minVal = INT_MAX;

        return value;
    }

    bool empty() {
        return top == nullptr;
    }

    int get_min() {
        if (empty()) return -1;
        return minVal;
    }

    void print() {
        if (empty()) {
            cout << "\nStack is empty ";
            return;
        }

        Node* current = top;
        cout << "\nStack : \n";
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    Stack st;
    for (int i = 1; i <= 10; i++) st.push(i);

    st.print();
    cout << "\nMinimum value in stack is : " << st.get_min() << endl;

    st.push(-100);
    st.print();
    cout << "\nMinimum value in stack is : " << st.get_min() << endl;

    st.pop();
    st.print();
    cout << "\nMinimum value in stack is : " << st.get_min() << endl;

    return 0;
}
