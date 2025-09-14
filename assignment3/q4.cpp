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
            top++;
            st[top] = x;
        }
    }

    char pop() {
        if (!isEmpty()) {
            char x = st[top];
            top--;
            return x;
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

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '^') {
        return 3;
    }
    return 0;
}

string infixToPostfix(string str) {
    Stack_Implementation st;
    string postfix = "";

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop();
        }
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix += st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}