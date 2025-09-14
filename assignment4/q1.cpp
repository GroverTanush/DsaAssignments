#include <iostream>
using namespace std;
#define SIZE 100 

class Queue_implementation{
private:
    int qu[SIZE];
    int front, rear;

public:
    Queue_implementation(){
        front = -1;
        rear = -1;
    }

    void enqueue(int element){
        if(rear == SIZE - 1){
            cout << "Queue is Overflowed!";
        }
        else{
            if(front == rear && rear == -1){
                front = 0;
                rear = 0;
                qu[rear] = element;
            }
            else{
                rear++;
                qu[rear] = element;
            }
        }
    }

    void dequeue(){
        if(front > rear || front == -1){
            cout << "Queue is underflowed!";
        }
        else{
            front++;
        }
    }

    bool isEmpty(){
        return (front == -1 || front > rear);
    }

    bool isFull(){
        return (rear == SIZE - 1);
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue is empty!";
            return -1;
        }
        else{
            return qu[front];
        }
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty!";
        }
        else{
            cout << "Queue elements: ";
            for(int i = front; i <= rear; i++){
                cout << qu[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Queue_implementation q1;

    int choice = 0;
    while(choice != 7){
        cout << "Enter" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. is Empty" << endl;
        cout << "4. is Full" << endl;
        cout << "5. display" << endl;
        cout << "6. peek" << endl;
        cout << "7. to exit" << endl;

    cin >> choice;
    
    switch(choice){
        case 1:
            int element;
            cout << "Enter the element you want for enqueue:";
            cin >> element;
            q1.enqueue(element);
            break;

        case 2:
            q1.dequeue();
            break;

        case 3:
            cout << (q1.isEmpty() ? "Queue is EMPTY" : "Queue is NOT empty") << endl;
            break;

        case 4:
            cout << (q1.isFull() ? "Queue is FULL" : "Queue is NOT full") << endl;
            break;

        case 5:
            q1.display();
            break;

        case 6:
            cout << "Front element: " << q1.peek() << endl;
            break;
        }
    }
    return 0;
}