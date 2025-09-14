#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nearestSmallerElement(vector<int> &arr) {
    stack<int> st;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            result.push_back(-1);
        } 
        else {
            result.push_back(st.top());
        }

        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ans = nearestSmallerElement(arr);

    cout << "Nearest smaller elements: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}