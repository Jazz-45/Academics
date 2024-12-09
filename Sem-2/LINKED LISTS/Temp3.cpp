#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node* &head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    if (head == nullptr) {
        newNode->next = newNode;
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    head = newNode;
}

// Function to delete the node following a given node in the circular linked list
void deleteNextNode(Node* &head, Node* prevNode) {
    if (head == nullptr || prevNode == nullptr || prevNode->next == head) {
        return;
    }
    Node* temp = prevNode->next;
    prevNode->next = temp->next;
    if (temp == head) {
        head = prevNode; // Update head if the deleted node was the head
    }
    delete temp;
}

// Function to traverse and print the circular linked list
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "Circular linked list is empty.\n";
        return;
    }
    cout << "Circular linked list: ";
    Node* temp = head->next;
    cout << head->data << " ";
    while (temp != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to search for a value in the circular linked list
bool search(Node* head, int key) {
    if (head == nullptr) {
        return false;
    }
    Node* temp = head->next;
    if (head->data == key) {
        return true;
    }
    while (temp != head) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr; // Initialize an empty circular linked list

    // Insertion at head
    insertAtHead(head, 5);
    insertAtHead(head, 10);
    insertAtHead(head, 15);

    // Traversing the circular linked list
    traverse(head);

    // Searching in the circular linked list
    int key = 10;
    if (search(head, key)) {
        cout << key << " is present in the list.\n";
    } else {
        cout << key << " is not present in the list.\n";
    }

    // Deleting a node
    deleteNextNode(head, head); // Deleting the node following the head

    // Traversing after deletion
    traverse(head);

    return 0;
}
