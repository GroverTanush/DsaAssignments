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
private:
    Node *head;

public:
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

    void check_LL(){
        Node* temp = head;
        while(temp->next != nullptr && temp->next != head){
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout << "The given Linked list is a singly linked list!";
        }
        else{
            cout << "The given Linked list is a Circular linked list!";
        }
    }

};
int main(){
    CircularLinkedList C;

    C.insertAtBegin(3);
    C.insertAtBegin(4);
    C.insertAtBegin(5);
    C.insertAtBegin(6);
    C.insertAtBegin(8);

    C.display();

    C.check_LL();

    return 0;
}