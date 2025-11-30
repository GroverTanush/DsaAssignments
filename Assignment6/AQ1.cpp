#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList{
public:
    Node *head;

    CircularLinkedList(){
        head = nullptr;
    }

    void insertAtBegin(int num){
        Node *newNode = new Node(num);
        if(!head){
            head = newNode;
            newNode->next = head; 
        }
        else{
            Node *current = head;
            while(current->next != head){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int num){
        Node *newNode = new Node(num);
        if(!head){
            head = newNode;
            newNode->next = head;
        }
        else{
            Node *current = head;
            while(current->next != head){
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void deleteAtBegin(){
        if(!head){
            cout << "Linked list is empty, Nothing to delete!";
        }
        else{
            Node *temp = head;
            if(head->next == head){
                head = nullptr;
            }
            else{
                Node *current = head;
                while(current->next != head){
                    current = current->next;
                }
                head = head->next;
                current->next = head;
            }
            delete temp;
        }
    }

    void deleteAtEnd(){
        if(!head){
            cout << "Linked list is Empty, Nothing to delete!";
        }
        else{
            Node *temp = head;
            if(head->next == head){
                head = nullptr;
            }
            else{
                Node *current = head;
                Node *prev = nullptr;
                while(current->next != head){
                    prev = current;
                    current = current->next;
                }
                prev->next = head;
            }
            delete temp;
        }
    }

    bool search(int value){
        if(!head){
            cout << "Linked list is Empty, No element to search!";
            return false;
        }
        else{
            Node *temp = head;
            do{
                if(temp->data == value){
                    cout << "Element found!" << endl;
                    return true;
                }
                temp = temp->next;
            }while(temp != head);

            cout << "Element not found!";
            return false;
        }
    }

    void display(){
        if(!head){
            cout << "Linked list is empty, No elements to display!";
        }
        else{
            Node *temp = head;
            do{
                cout << temp->data << " ";
                temp = temp->next;
            }while(temp != head);
            cout << endl;
        }
    }

    int get_size(){
        int size = 1;
        if(head == nullptr){
            return 0;
        }
        else{
            Node* temp = head;
            while(temp->next != head){
                size++;
                temp = temp->next;
            }
            return size;
        }
    }
};

void splitLinkedList(CircularLinkedList &C, CircularLinkedList &C1, CircularLinkedList &C2){
        int size = C.get_size();
        if (size % 2 == 0 ){
            Node* temp = C.head;
            for(int i = 1; i <= size / 2; i++){
                C1.insertAtEnd(temp->data);
                temp = temp->next;
            }
            for(int i = 1; i <= size / 2; i++){
                C2.insertAtEnd(temp->data);
                temp = temp->next;
            }
        }
        else{
            Node* temp1 = C.head;
            for(int i = 1; i <= (size / 2) + 1; i++){
                C1.insertAtEnd(temp1->data);
                temp1 = temp1->next;
            }
            for(int i = (size / 2) + 1; i < size; i++){
                C2.insertAtEnd(temp1->data);
                temp1 = temp1->next;
            }
        }    
}

int main(){
    CircularLinkedList C,C1,C2;

    C.insertAtBegin(3);
    C.insertAtBegin(4);
    C.insertAtBegin(6);
    C.insertAtBegin(7);
    C.insertAtBegin(8);

    C.display();

    splitLinkedList(C, C1, C2);
    
    C1.display();
    C2.display();
    return 0;
}