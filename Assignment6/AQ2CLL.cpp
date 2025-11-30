#include <iostream>
using namespace std;

int get_parity(int n);

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

    void deleteSpecificNode(int existingvalue){
        if(head == nullptr){
            cout << "Linked list is empty! Nothing to delete!";
        }
        else{
            Node* temp = head;
            Node* prev = nullptr;
            while(temp->next != head && temp->data != existingvalue){
                prev = temp;
                temp = temp->next;
            }
            if(temp == head){
                deleteAtBegin();
            }
            else if(temp->next == head){
                deleteAtEnd();
            }
            else{
                prev->next = temp->next;
            }
            delete(temp);
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

    void deleteAtevenParity(){
        if(head == nullptr){
            cout << "Linked List is empty! Nothing to delete.";
        }
        else{
            Node* temp = head;
            while(temp->next != head){
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
    CircularLinkedList CLL1;
    CLL1.insertAtBegin(7);
    CLL1.insertAtBegin(5);
    CLL1.insertAtBegin(8);
    CLL1.insertAtBegin(13);
    CLL1.insertAtBegin(15);

    CLL1.display();

    CLL1.deleteAtevenParity();

    CLL1.display();
}