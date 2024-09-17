#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
void push(int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = NULL;
    if (front == NULL)
    {
        front = rear = ptr;
        return;
    }
    else
    {
        rear->next = ptr;
        rear = rear->next;
    }
}
void pop()
{
    if (front == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        front=front->next;
        
    }
}
void display()
{
    Node *curr = front;
    while (curr!= NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}
void isEmpty()
{
    if (front == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        cout << "List is not empty!" << endl;
    }
}
using namespace std;
int main()
{
    push(1);
    push(21);
    push(31);
    push(41);
    push(51);
    display();
    pop();
    display();
    return 0;
}