#include <iostream>
using namespace std;

#define MAX 100

class Stack_Implementation {
    int top;
    char st[MAX];

public:
    Stack_Implementation() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(char x) {
        if (!isFull()) {
            st[++top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return st[top--]; 
        }
        return '\0';  
    }

    char peek() {
        if (!isEmpty()) {
            return st[top];
        }
        return '\0';
    }
};

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(string str) {
    Stack_Implementation st;  

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) {
                return false;
            }
            char top = st.pop();
            if (!isMatching(top, ch)) {
                return false;
            }
        }
    }
    return st.isEmpty();
}

int main() {
    string str;
    cout << "Enter expression: ";
    cin >> str;

    if (isBalanced(str)) {
        cout << "Balanced\n";
    } else {
        cout << "Not Balanced\n";
    }

    return 0;
}