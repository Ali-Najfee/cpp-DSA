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

void sorted_insert(int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = value;
    ptr->prev = NULL;
    ptr->next = NULL;
    if (head == NULL || head->data > value)
    {
        ptr->next = head;
        if (head != NULL)
        {
            head->prev = ptr;
        }
        head = ptr;
        return;
    }
    Node *curr = head;
    while(curr->next!=NULL && curr->next->data < value){
        curr = curr->next;
    }
    if(curr->next != NULL){
        curr->next->prev=ptr;
        ptr->next=curr->next;

    }
    curr->next = ptr;
    ptr->prev = curr;
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
    sorted_insert(25);

    sorted_insert(15);
    sorted_insert(10);
    sorted_insert(18);
    sorted_insert(3);
    sorted_insert(8);
    sorted_insert(1);

    // Display the original list
    cout << "Original list:" << endl;
    display();
    return 0;
}