#include <iostream>
#include <cstdlib>
using namespace std;
int top = -1;
void push(int *arr, int size, int value)
{
    if (top == size)
    {
        cout << "Stack Overflow: " << endl;
    }
    else
    {
        top++;
        arr[top] = value;
        cout << value << " Successfully! Push into stack" << endl;
    }
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void pop(int *arr, int &size)
{
    if (top == -1)
    {
        cout << "Stack underflow: " << endl;
    }
    else
    {
        int newvalue=arr[size-1];
        arr[top] = newvalue ;
        top--;
        size--;
        cout << newvalue << " Delete! Pop from  stack" << endl;
    }
}

int main()
{
    int size;
    cout << "Enter how many size Arrays you want :";
    cin >> size;
    int arr[size];
    while (true)
    {
        int opera;
        cout << "Enter 1 for insertion \nEnter 2 for display:\nEnter 3 for delete last:\nEnter operator:";
        cin >> opera;
        switch (opera)
        {
        case 1:
            for (int i = 0; i < size; i++)
            {
                int value;
                cout << "Enter value : ";
                cin >> value;
                push(arr, size, value);
            }
            break;
        case 2:
            display(arr, size);
            break;
        case 3:
            pop(arr, size);
            break;
        default:
            false;
            break;
        }
        cout<<"--------------------------------"<<endl;
    }
    return 0;
}