#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtHead(Node* &head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Function to delete the first node in the linked list
void deleteAtHead(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Function to traverse and print the linked list
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to search for a value in the linked list
bool search(Node* head, int key) {
    while (head != nullptr) {
        if (head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    // Insertion at head
    insertAtHead(head, 5);
    insertAtHead(head, 10);
    insertAtHead(head, 15);

    // Traversing the linked list
    traverse(head);

    // Searching in the linked list
    int key = 10;
    if (search(head, key)) {
        cout << key << " is present in the linked list.\n";
    } else {
        cout << key << " is not present in the linked list.\n";
    }

    // Deletion at head
    deleteAtHead(head);

    // Traversing after deletion
    traverse(head);

    return 0;
}
