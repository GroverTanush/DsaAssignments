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

    int dequeue(){
        if(front > rear || front == -1){
            cout << "Queue is underflowed!";
            return -1;
        }
        else{
            int temp = qu[front];
            front++;
            return temp;
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

    int size(){
        return (rear - front + 1);
    }
};

void interleave(Queue_implementation &q1){
    Queue_implementation q2;

    int n = q1.size();
    for(int i = 0; i < n/2; i++){
        q2.enqueue(q1.dequeue());
    }

    while(!q2.isEmpty()){
        q1.enqueue(q2.dequeue());
        q1.enqueue(q1.dequeue());
    }
}

int main(){
    Queue_implementation q1;

    q1.enqueue(4);
    q1.enqueue(7);
    q1.enqueue(11);
    q1.enqueue(20);
    q1.enqueue(5);
    q1.enqueue(9);

    cout << "Original queue: ";
    q1.display();

    interleave(q1);

    cout << "Interleaved queue: ";
    q1.display();

    return 0;
}