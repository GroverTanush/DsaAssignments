#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

Node* reverseInGroups(Node* head, int k) {
    if (!head) return nullptr;

    Node* current = head;
    Node* next = nullptr;
    Node* prevNode = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prevNode;
        current->prev = next;
        prevNode = current;
        current = next;
        count++;
    }

    if (next != nullptr) {
        head->next = reverseInGroups(next, k);
        if (head->next)
            head->next->prev = head;
    }

    return prevNode;
}

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 1; i <= 8; i++)
        insert(head, i);

    cout << "Original list: ";
    printList(head);

    int k = 3;
    head = reverseInGroups(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}