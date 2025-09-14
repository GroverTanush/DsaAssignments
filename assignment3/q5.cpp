#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class IntStack {
    int top;
    int st[MAX];

public:
    IntStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(int x) {
        if (!isFull()) {
            top++;
            st[top] = x;
        }
    }

    int pop() {
        if (!isEmpty()) {
            int x = st[top];
            top--;
            return x;
        }
        return -1;
    }

    int peek() {
        if (!isEmpty()) {
            return st[top];
        }
        return -1;
    }
};

int applyOp(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else if (op == '*') {
        return a * b;
    }
    else if (op == '/') {
        return a / b;
    }
    else if (op == '^') {
        return pow(a, b);
    }
    return 0;
}

int evaluatePostfix(string exp) {
    IntStack st;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            st.push(ch - '0');  // convert char digit to int
        }
        else {
            int b = st.pop();
            int a = st.pop();
            int result = applyOp(a, b, ch);
            st.push(result);
        }
    }

    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}