#include <iostream>

using namespace std;

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to insert a new node at the beginning of the doubly linked list
void insertAtHead(Node* &head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

// Function to delete a node from the doubly linked list
void deleteNode(Node* &head, Node* deleteNode) {
    if (head == nullptr || deleteNode == nullptr) {
        return;
    }
    if (head == deleteNode) {
        head = deleteNode->next;
    }
    if (deleteNode->next != nullptr) {
        deleteNode->next->prev = deleteNode->prev;
    }
    if (deleteNode->prev != nullptr) {
        deleteNode->prev->next = deleteNode->next;
    }
    delete deleteNode;
}

// Function to traverse and print the doubly linked list forward
void traverse(Node* head) {
    cout << "Forward traversal: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to search for a value in the doubly linked list
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
    Node* head = nullptr; // Initialize an empty doubly linked list

    // Insertion at head
    insertAtHead(head, 5);
    insertAtHead(head, 10);
    insertAtHead(head, 15);

    // Traversing the doubly linked list forward
 traverse
(head);

    // Traversing the doubly linked list backward
    // Node* tail = nullptr;
    // Node* temp = head;
    // while (temp->next != nullptr) {
    //     temp = temp->next;
    // }
    // tail = temp;
    // traverseBackward(tail);

    // Searching in the doubly linked list
    int key = 10;
    if (search(head, key)) {
        cout << key << " is present in the doubly linked list.\n";
    } else {
        cout << key << " is not present in the doubly linked list.\n";
    }

    // Deleting a node
    deleteNode(head, head->next); // Deleting the second node

    // Traversing after deletion
 traverse
(head);
    // traverseBackward(tail);

    return 0;
}
