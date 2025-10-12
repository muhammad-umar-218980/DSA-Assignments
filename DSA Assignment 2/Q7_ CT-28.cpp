#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Name : Muhammad Umar
    Roll no. : CT - 24028
    Class : CSIT Section A Batch 24
*/

int largestRectangleArea(vector<int>& heights);

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    if (n <= 0) {
        cout << "\nInvalid number of bars (must be positive)." << endl;
        return 0;
    }

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter height of bar " << i + 1 << " : ";
        cin >> heights[i];
    }

    int result = largestRectangleArea(heights);
    cout << "\nLargest Rectangle Area: " << result << endl;

    return 0;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;

    vector<int> right(n, 0);
    vector<int> left(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int largestArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currentArea = heights[i] * width;
        largestArea = max(largestArea, currentArea);
    }

    return largestArea;
}
