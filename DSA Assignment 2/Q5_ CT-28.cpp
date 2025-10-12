#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
    Name : Muhammad Umar
    Class : CSIT Section A Batch 24
    Roll no. : CT - 24028
*/

int evaluatePostfix(vector<string>& postfix) {
    stack<int> st;

    for(int i = 0; i < postfix.size(); i++) {
        string c = postfix[i];

        if(c == "+" || c == "-" || c == "*" || c == "/") {
            int b = st.top(); 
			st.pop();
			
            int a = st.top(); 
			st.pop();

            if(c == "+") st.push(a + b);
            else if(c == "-") st.push(a - b);
            else if(c == "*") st.push(a * b);
            else {
                if(b != 0) st.push(a / b);
                else {
                    cout << "Error: Division by zero" << endl;
                    return 0;
                }
            }
        }
        else st.push(stoi(c));
    }
    return st.top();
}

vector<string> splitPostfix(string expr);

int main() {
    string expr = "5 6 2 + * 12 4 / -";
    vector<string> postfix = splitPostfix(expr);
    cout << evaluatePostfix(postfix);
}

vector<string> splitPostfix(string expr) {
    vector<string> result;
    string temp = "";

    for(int i = 0; i < expr.size(); i++) {
        if(expr[i] == ' ') {
            if(temp != "") {
                result.push_back(temp);
                temp = "";
            }
            continue;
        }
        temp += expr[i];
    }
    if(temp != "") result.push_back(temp);

    return result;
}
