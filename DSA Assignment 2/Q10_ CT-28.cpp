#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
    Name : Muhammad Umar
    Roll no. : CT - 24028
    Class : CSIT Section A Batch 24
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k);

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cout << "\nEnter element " << i + 1 << " : ";
        cin >> nums[i];
    }

    cout << "\nEnter window size k: ";
    cin >> k;

    if (k <= 0) {
        cout << "\nInvalid window size (k must be positive)." << endl;
        return 0;
    }

    if (k > n) {
        cout << "\nWindow size "<< k << " cannot be greater than array size " << n << "." << endl;
        return 0;
    }

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "\nMaximum elements in each window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    int n = nums.size();

    for (int i = 0; i < k; i++) {
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
    }

    for (int i = k; i < n; i++) {
        result.push_back(nums[dq.front()]);

        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

        dq.push_back(i);
    }

    result.push_back(nums[dq.front()]);
    return result;
}
