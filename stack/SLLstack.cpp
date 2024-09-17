#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int value;
    Node *next;
};
Node *top = NULL;
void push(int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = top;
    top = ptr;
}
void pop()
{
    if (top == NULL)
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    Node *curr = top;
    while (curr->next != NULL)
    {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}
void isEmpty()
{
    if (top == NULL)
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
    isEmpty();
    cout << endl;
    push(1);
    push(21);
    push(31);
    push(41);
    push(51);
    display();
    pop();
    display();
    isEmpty();

    return 0;
}