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

    void display(){
        Node * temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int countAndDeleteOccurrences(int key){
        int count = 0;
        while(head != nullptr && head->data == key){
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }
        Node* current = head;
        while(current != nullptr && current->next != nullptr){
            if(current->next->data == key){
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                count++;
            }
            else{
                current = current->next;
            }
        }
        return count;
    }
};

int main(){
    LinkedList list;
    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(5);
    list.insertAtEnd(20);
    list.insertAtEnd(5);
    cout << "Original list: ";
    list.display();

    int key = 5;
    int occurrences = list.countAndDeleteOccurrences(key);
    cout << "Deleted " << occurrences << " occurrences of " << key << endl;

    cout << "Updated list: ";
    list.display();

    return 0;
}