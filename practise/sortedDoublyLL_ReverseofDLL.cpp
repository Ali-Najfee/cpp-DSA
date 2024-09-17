#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;


void sorted_insert(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if (head == NULL || data < head->data) {
        node->next = head;
        if (head != NULL)
            head->prev = node;
        head = node;
        return;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->data < data) {
        curr = curr->next;
    }
    if (curr->next != NULL)
        curr->next->prev = node;
        node->next = curr->next;

    curr->next = node;
    node->prev = curr;
}


void copy_reverse() {
    Node* new_head = NULL;
    Node* curr = head;
    while (curr != NULL) {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = curr->data;
        node->prev = NULL;
        node->next = NULL;

        if (new_head == NULL) {
            new_head = node;
        } else {
            node->next = new_head;
            new_head->prev = node;
            new_head = node;
        }
        curr = curr->next;
    }
    // Display the reversed list
    cout << "Reversed list:" << endl;
    Node* temp = new_head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to display the list
void display() {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Example usage:
int main() {
    // Insert elements in sorted order
    sorted_insert(15);
    sorted_insert(10);
    sorted_insert(18);
    sorted_insert(3);
    sorted_insert(8);
    sorted_insert(1);

    // Display the original list
    cout << "Original list:" << endl;
    display();

    // Create a new list with reverse elements
    copy_reverse();

    return 0;
}

