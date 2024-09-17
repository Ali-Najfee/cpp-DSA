
#include <iostream>
using namespace std;

const int size = 4;
int arr[size];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1)
    {
        cout << "Empty Array" << endl;
        return true;
    }
    else
    {
        cout << "Not Empty Array" << endl;
        cout<<"-------"<<endl;
        return false;
    }
}

bool isFull()
{
    if ((rear + 1) % size == front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int value)
{
    int oper;
    cout << "Enter where to place push on front or back: ";
    cin >> oper;
    if (oper == 1)
    {
        if (front == -1)
        {
            front = rear = 0;
            arr[0] = value;
            return;
        }
        else if (isFull())
        {
            cout << "Overflow!" << endl; // Inform user that queue is full
            return;
        }
        else
        {
            front = (front - 1 + size) % size;
            arr[front] = value;
            cout << "Push on front :" << endl;
            return;
        }
    }
    else if (oper == 2)
    {
        if (front == -1)
        {
            front = rear = 0;
            arr[0] = value;
            cout << "Null!Push on back :";
            return;
        }
        else if (isFull())
        {
            cout << "Overflow!" << endl; // Inform user that queue is full
            return;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = value;
            cout << "Push on back :" << endl;
            return;
        }
    }
    else
    {
        cout << "Wrong operator!" << endl;
        push(value);
    }
}

void display()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
}
void pop()
{
    int oper;
    cout << "Enter where to place pop on front or back: ";
    cin >> oper;
    if (oper == 1)
    {
        if (front ==rear)
        {
            front=rear=-1;
            return;
        }
        else if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }
        else
        {
            front=(front+1)%size;
            cout << "Pop on front :" << endl;
            return;
        }
    }
    else if (oper == 2)
    {
        if (front == -1)
        {
            cout << "Null!Pop on back :";
            return;
        }
        else if (isEmpty())
        {
            cout << "Underflow!" << endl;
            return;
        }
        else
        {
            rear=(rear-1+rear)%size;
            cout << "Pop on back :" << endl;
            return;
        }
    }
    else
    {
        cout << "Wrong operator!" << endl;
        pop();
    }
}
int main()
{
    push(1);
    push(91);
    push(19);
    push(41);
    display();
    pop();
    display();
    return 0;
}