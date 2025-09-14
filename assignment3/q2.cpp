#include <iostream>
#include <string>
using namespace std;

class Stack_Implementation {
    
private:
    char st[100];
    int top = -1;

public:
    void push(char x) {
        if (top >= 99) { 
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            st[top] = x;
        }
    }

    char pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        } else {
            char val = st[top];
            top--;
            return val;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Stack_Implementation stack;

    for (int i = 0; i < str.length(); i++) {
        stack.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;

    return 0;
}