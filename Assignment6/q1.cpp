#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next, *prev;

    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL_implementation{
private:
    Node *head;

public:
    DLL_implementation(){
        head = nullptr;
    }

    void insertatBeg(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertatEnd(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertatspecificvalue(int newValue, int existingValue){
        Node* newNode = new Node(newValue);
        Node* temp = head;
        while(temp != nullptr && temp->data != existingValue){
            temp = temp->next;
        }
        if(temp == nullptr){
            cout << "The given value is not present in the Linked list!";
        }
        else if(temp->next == nullptr){
            temp->next = newNode;
            newNode->prev = temp;
        }
        else{
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void delatSpecificNode(int existingvalue){
        Node* temp = head;
        while(temp != nullptr && temp->data != existingvalue){
            temp = temp->next;
        }
        if(temp == nullptr){
            cout << "Value not found!";
        }
        else if(temp == head && temp->next == nullptr){
            head = nullptr;
        }
        else if(temp->next == nullptr){
            temp->prev->next = nullptr;
        }
        
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete(temp);
    }

    void search(int value){
        if(head == nullptr){
            cout << "Linked list is empty!";
        }

        Node* temp = head;

        while(temp != nullptr && temp->data != value){
            temp = temp->next;
        }
        if(temp->data == value){
            cout << "Element found in the Linked list!";
        }
        else{
            cout << "Element not found in the Linked list!";
        }
    }

    int get_size(){
        int size = 0;
        if(head == nullptr){
            return 0;
        }
        else{
            Node* temp = head;
            while(temp!=nullptr){
                size++;
                temp = temp->next;
            }
            return size;
        }
    }
};

int main(){
    DLL_implementation DLL1;
    DLL1.insertatBeg(6);
    DLL1.insertatBeg(5);
    DLL1.insertatBeg(4);
    DLL1.insertatBeg(3);

    DLL1.search(4);
    cout << endl;
    cout << "The size of the Linked list is: "<< DLL1.get_size() << endl;
    
}