#include <iostream>
using namespace std;
const int size = 5;
int arr[size];
int front = -1;
int rear = -1;
void isEmpty()
{
    if (front == -1)
    {
        cout << "Empty Array" << endl;
    }
    else
    {
        cout << "Not Empty Array" << endl;
    }
}
void isFull()
{
    if (rear ==size -1)
    {
        cout << "full Array" << endl;
    }
    else
    {
        cout << "Not Full Array" << endl;
    }
}
void push(int value)
{
    if (rear == size - 1)
    {
        cout << "Overflow\n";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[front] = value;
        return;
    }
    else
    {
        rear++;
        arr[rear] = value;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "empty\n";
        return;
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
void pop()
{
    if (front == -1)
    {
        cout << "underflow" << endl;
        return;
    }
    else
    {
        front++;
    }
}
int main()
{
    push(1);
    isFull();
    push(21);
    push(31);
    push(41);
    push(51);
    display();
    pop();
    isEmpty();
    display();
    return 0;
}