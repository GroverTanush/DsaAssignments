#include <iostream>
using namespace std;
#define SIZE 100 

class Queue_implementation {
private:
    char qu[SIZE];
    int front, rear;

public:
    Queue_implementation() {
        front = -1;
        rear = -1;
    }

    void enqueue(char element) {
        if(rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
        } else {
            if(front == -1 && rear == -1) {
                front = 0;
                rear = 0;
            } else {
                rear++;
            }
            qu[rear] = element;
        }
    }

    char dequeue() {
        if(front > rear || front == -1) {
            return '\0';
        } else {
            char temp = qu[front];
            front++;
            return temp;
        }
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    char peek() {
        if(isEmpty()) return '\0';
        return qu[front];
    }

 
    bool contains(char x) {
        for(int i = front; i <= rear; i++) {
            if(qu[i] == x) return true;
        }
        return false;
    }
};

void non_repeating(string str) {
    Queue_implementation q1;

    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];

        
        if(q1.contains(ch)) {
            while(!q1.isEmpty() && q1.peek() == ch) {
                q1.dequeue();
            }
        } else {
            q1.enqueue(ch);
        }

        
        if(q1.isEmpty()){
            cout << -1 << " ";
        }
        else{ 
            cout << q1.peek() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    non_repeating(str);
    return 0;
}