#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> minS;

public:
    void push(int x) {
        s.push(x);
        if (minS.empty() || x <= minS.top()) {
            minS.push(x);
        }
    }

    void pop() {
        if (s.empty()) return;
        int val = s.top();
        s.pop();
        if (val == minS.top()) {
            minS.pop();
        }
    }

    int top() {
        if (s.empty()) return -1;
        return s.top();
    }

    int getMin() {
        if (minS.empty()) return -1;
        return minS.top();
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    MinStack ms;
    ms.push(5);
    ms.push(2);
    ms.push(10);
    ms.push(1);

    cout << "Current Min: " << ms.getMin() << endl; 
    ms.pop();
    cout << "Current Min: " << ms.getMin() << endl; 

    return 0;
}