#include <iostream>
using namespace std;

int get_parity(int n);

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

    void deleteSpecificNode(int existingvalue){
        Node* temp = head;
        while(temp != nullptr && temp->data != existingvalue){
            temp = temp->next;
        }
        if(temp == nullptr){
            cout << "Value not found!";
        }
        else if(temp == head) { 
            head = head->next;
            head->prev = nullptr;
            temp->next = nullptr; 
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

    void display(){
        if(head == nullptr){
            cout << "Linked list is empty nothing to display!";
        }
        else{
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void deleteAtevenParity(){
        if(head == nullptr){
            cout << "Linked List is empty! Nothing to delete.";
        }
        else{
            Node* temp = head;
            while(temp != nullptr){
                Node* nextNode = temp->next;
                int parity = get_parity(temp->data);
                if(parity % 2 == 0){
                    deleteSpecificNode(temp->data);
                }
                temp = nextNode;
            }
        }
    }
};

int get_parity(int n){
    string binary = "";
    while(n > 0){
        binary = to_string(n % 2) + binary;
        n /= 2;
    }

    int count = 0;
    for(int i = 0; i < binary.length(); i++){
        if(binary[i] == '1'){
            count++;
        }
    }
    return count;
}

int main(){
    DLL_implementation DLL1;
    DLL1.insertatBeg(7);
    DLL1.insertatBeg(5);
    DLL1.insertatBeg(8);
    DLL1.insertatBeg(13);
    DLL1.insertatBeg(15);

    DLL1.display();

    DLL1.deleteAtevenParity();

    DLL1.display();

    
}