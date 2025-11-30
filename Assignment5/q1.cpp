#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node *head;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(int value){
        Node * newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value){
        Node * newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node * current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtValue(int existingValue, int newValue){
        Node * newNode = new Node(newValue);

        if (head == nullptr){
            head = newNode;
        }
        else{
            Node * current = head;
            while(current != nullptr && current->data != existingValue){
                current = current->next;
            }

            if(current == nullptr){
                cout << "Value not found, node not created!";
                delete newNode;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void insertAtPosition(int value, int position){
        Node * newNode = new Node(value);

        if(position < 0){
            cout << "Please enter a valid Position!";
        }
        else if(position == 0){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node * current = head;
            int currentPosition = 0;

            while(current != nullptr && currentPosition < position - 1){
                current = current->next;
                currentPosition++;
            }

            if(current == nullptr){
                cout << "No given Position found, No node created!";
                delete newNode;
            }
            else{
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
    
    void deleteAtBeginning(){
        if(head == nullptr){
            cout << "Linked list is empty, Nothing to delete!";
        }
        else{
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteAtEnd(){
        if(head == nullptr){
            cout << "Linked list is empty, Nothing to delete!";
        }
        else if(head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node * current = head;
            while(current->next->next != nullptr){
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

    void deleteAtValue(int value){
        if(head == nullptr){
            cout << "Linked List is empty, Nothing to Delete!";
        }
        else{
            Node * temp = head;
            Node * pre = nullptr;

            while(temp != nullptr && temp->data != value){
                pre = temp;
                temp = temp->next;
            }

            if(temp == nullptr){
                cout << "Element not found!";
            }
            else{
                if(temp == head){
                    head = head->next;
                }
                else if(temp->next == nullptr){
                    pre->next = nullptr;
                }
                else{
                    pre->next = temp->next;
                }
                delete temp;
            }
        }
    }

    void deleteAtPosition(int position){
        if(position < 0){
            cout << "Please enter a valid position!";
        }
        else if(position == 0){
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node * current = head;
            int currentPosition = 0;

            while(current != nullptr && currentPosition < position - 1){
                current = current->next;
                currentPosition++;
            }

            if(current == nullptr || current->next == nullptr){
                cout << "Position out of range!";
                return;
            }

            Node * temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    bool searchValue(int value){
        if(head == nullptr){
            cout << "Linked list is empty, No element to search!";
        }
        else{
            Node * temp = head;
            while(temp != nullptr){
                if(temp->data == value){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }
    }

    void display(){
        if(head == nullptr){
            cout << "Linked list is empty, No element to display!";
        }
        else{
            Node * temp = head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            } 
        }
    }
};  


int main() {
    LinkedList list;

    cout << "=== Insertion Tests ===" << endl;
    list.insertAtBeginning(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtValue(20, 25);    
    cout << "List after insertions: ";
    list.display();   

    cout << "\n=== Deletion Tests ===" << endl;
    list.deleteAtBeginning();
    cout << "After deleting beginning: " << endl;
    list.display(); 

    list.deleteAtEnd();
    cout << "After deleting end: ";
    list.display();  

    list.deleteAtValue(20);
    cout << "After deleting value 20: ";
    list.display();   

    list.deleteAtPosition(1); 
    cout << "After deleting position 1: ";
    list.display();   

    cout << "\n=== Search Tests ===" << endl;
    cout << "Searching for 25: " << (list.searchValue(25) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (list.searchValue(100) ? "Found" : "Not Found") << endl;

    cout << "\n=== Final List ===" << endl;
    list.display();   

    return 0;
}