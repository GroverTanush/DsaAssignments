#include <iostream>
using namespace std;

class Stack_implementation{

private:

    int st[50];
    int top = -1;

public:

    void push(int x){
        if (top >= 49){
            cout << "Element cannot be pushed as overflow condition has been reached!" << endl;
        }
        else{
            top++;
            st[top] = x;
        }
    }

    void pop(){
        if (top < 0){
            cout << "Element cannot be popped as underflow condition of the stack is reached!" << endl;
        }
        else{
            top--;
        }
    }

    int peek(){
        if (top < 0){
            cout << "There is no element in the stack!" << endl;
            return -1;
        }
        else{
            return st[top];
        }
    }

    void isEmpty(){
        if (top == -1){
            cout << "The stack is Empty!" << endl;
        }
        else{
            cout << "The stack is not Empty!" << endl;
        }
    }

    void isFull(){
        if (top == 49 ){
            cout << "The stack is Full!" << endl;
        }
        else{
            cout << "The stack is not Full!" << endl;
        }
    }

    void display(){
        int temp = top;
        while(temp != -1){
            cout << st[temp] << " ";
            temp--;
        }
        cout << endl;
    }
};

int main(){
    Stack_implementation stack;
    int choice = 0;
    while(choice != 7){
        cout << "Enter" << endl;
        cout << "1. to push an element to the stack" << endl;
        cout << "2. to pop an element from the stack" << endl;
        cout << "3. to check whether the stack is empty" << endl;
        cout << "4. to check whether the stack is full" << endl;
        cout << "5. to display the full stack" << endl;
        cout << "6. to see the top element of the stack" << endl;
        cout << "7. to exit" << endl;

    cin >> choice;
    
    switch(choice){
        case 1:
            int element;
            cout << "Enter the element you want to push:";
            cin >> element;
            stack.push(element);
            break;

        case 2:
            stack.pop();
            break;

        case 3:
            stack.isEmpty();
            break;

        case 4:
            stack.isFull();
            break;

        case 5:
            stack.display();
            break;

        case 6:
            cout << "Top element: " << stack.peek() << endl;
            break;
        }
    }
    return 0;
}