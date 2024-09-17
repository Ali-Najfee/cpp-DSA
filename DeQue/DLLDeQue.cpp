#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

Node *front = NULL;
Node *rear = NULL;

void push(int value)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->value = value;
    ptr->next = NULL;
    int oper;
    cout << "Enter where to place front or back: ";
    cin >> oper;
    if (oper == 1)
    {
        if (front == NULL)
        {
            cout << "Pushing front on NULL " << endl;
            front = rear = ptr;
            return;
        }
        else
        {
            cout << "Pushing on front " << endl;
            front->prev = ptr;
            ptr->next = front;
            front = ptr;
            return;
        }
    }
    else if (oper == 2)
    {
        if (front == NULL)
        {
            cout << "Pushing back on NULL " << endl;
            front = rear = ptr;
            return;
        }
        else
        {
            cout << "Pushing on back " << endl;
            rear->next = ptr;
            ptr->prev = rear;
            rear = ptr;
            return;
        }
    }
    else
    {
        cout << "Operation no exist!" << endl;
        push(value);
        cout << "\t---\nPut Carefully!" << endl;
        return;
    }
}
void pop()
{
    int oper;
    cout << "Enter where to place pop on front or back: ";
    cin >> oper;
    if (oper == 1)
    {
        if (front == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        else
        {

            cout << "Popping from front " << endl;
            Node *temp = front;
            front = front->next;
            free(temp);
            if (front)
            {
                front->prev = NULL;
            }
            else
            {
                rear = NULL;
            }
        }
    }
    else if (oper == 2)
    {
        if (front == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        else
        {
            cout << "Popping from back " << endl;
            if (front->next == NULL)
            {
                free(front);
                front = rear = NULL;
            }
            else
            {
                Node *temp = rear;
                rear = rear->prev;
                free(temp);
                if (rear)
                    rear->next = NULL;
                else
                    front = NULL;
            }
        }
    }
    else
    {
        cout << "Operation does not exist!" << endl;
    }
}

void display()
{
    Node *curr = front;
    while (curr != NULL)
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

int main()
{
    push(34);
    push(24);
    push(14);
    push(04);
    push(8);
    push(7);
    push(6);
    push(5);
    push(2);
    push(12);
    push(1);
    push(3);
    push(21);
    display();
    cout << "Press" << endl;
    pop();
    display();

    return 0;
}
