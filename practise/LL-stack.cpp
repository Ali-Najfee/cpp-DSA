#include <iostream>
#include <cstdlib>
using namespace std;

struct ptr
{
    int value;
    ptr *next;
};
ptr *top = NULL;
void push(int data)
{
    ptr *ptr = (ptr *)malloc(sizeof(ptr));
    ptr->value = data;
    ptr->next = top;
    top = ptr;
}
void display()
{
    ptr *curr = top;
    while (curr != NULL)
    {
        cout << curr->value << "  ";
        curr = curr->next;
    }
}
void pop(){
    ptr *curr=top;
    top=top->next;
    free(curr);   
}
int main()
{
    push(10);
    push(8);
    push(7);
    push(6);
    push(3);
    display();
    pop();
    cout<<endl;
    display();
    return 0;
}