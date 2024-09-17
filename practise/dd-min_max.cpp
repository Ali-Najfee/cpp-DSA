#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

void insert(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    if (head == NULL || head->data > value)
    {
        node->next = head;
        if (head != NULL)
        {
            head->prev = node;
        }
        head = node;
    }
    // else
    // {
    //     Node *curr = head;
    //     while (curr->next && curr->next->data < value)
    //     {
    //         curr = curr->next;
    //     }
    //     node->next = curr->next;
    //     if (curr->next != NULL)
    //         curr->next->prev = node;
    //     curr->next = node;
    //     node->prev = curr;
    // }
}
void display()
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    insert(5);
    insert(4);
    insert(3);
    insert(2);
    insert(1);
    cout << "Original list: ";
    display();
    return 0;
}
