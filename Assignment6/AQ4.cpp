#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* random;

    Node(int val) {
        data = val;
        next = prev = random = nullptr;
    }
};

void correctRandomPointer(Node* head) {
    Node* temp = head;
    while (temp) {
        if (temp->random && temp->random->next == temp) {
            temp->random = temp->next;
            break;
        }
        temp = temp->next;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->random)
            cout << " (Random -> " << temp->random->data << ")";
        cout << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    third->random = second;

    cout << "Before correction: ";
    printList(head);

    correctRandomPointer(head);

    cout << "After correction: ";
    printList(head);

    return 0;
}