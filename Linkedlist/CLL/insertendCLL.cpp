#include <iostream>
#include <stdlib.h>
using namespace std;

struct StdNode
{
    int RNO;
    StdNode *next;
};

StdNode *head = NULL;

void iinsert(StdNode **head, int RNO)
{
    StdNode *ptr = (StdNode *)malloc(sizeof(StdNode));
    ptr->RNO = RNO;

    if (*head == NULL)
    {
        *head = ptr;
        ptr->next = *head;
    }
    else
    {
        StdNode *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = *head;
    }
}

void display(StdNode *head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    StdNode *temp = head;
    do
    {
        cout << "Roll NO : " << temp->RNO << endl;
        temp = temp->next;
    } while (temp != head);
}

void search(StdNode *head, int tosearch)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    StdNode *temp = head;
    do
    {
        if (temp->RNO == tosearch)
        {
            cout << "Found! Roll NO : " << temp->RNO << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Value Not found!" << endl;
}

void update(StdNode *head, int toupdate)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    StdNode *temp = head;
    do
    {
        if (temp->RNO == toupdate)
        {
            int newvalue;
            cout << "New Value :";
            cin >> newvalue;
            temp->RNO = newvalue;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Value Not found!" << endl;
}

void del(StdNode **head, int todel)
{
    if (*head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    StdNode *temp = *head, *prev = NULL;
    while (temp->next != *head)
    {
        if (temp->RNO == todel)
        {
            if (prev == NULL)
            {
                StdNode *last = *head;
                while (last->next != *head)
                {
                    last = last->next;
                }
                last->next = (*head)->next;
                *head = (*head)->next;
                free(temp);
                return;
            }
            prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp->RNO == todel)
    {
        if (temp == *head)
        {
            (*head) = (*head)->next;
        }
        prev->next = temp->next;
        free(temp);
        return;
    }
    cout << "Value Not found!" << endl;
}

void alldel(StdNode **head)
{
    if (*head == NULL)
    {
        cout << "List is already empty!" << endl;
        return;
    }
    StdNode *current = *head;
    StdNode *next;
    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);
    *head = NULL;
}

void traverse(StdNode *head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    StdNode *temp = head;
    do
    {
        cout << temp->RNO << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    bool result = true;
    while (result)
    {
        int operat;
        cout << "Enter 0 for check empty or not\nEnter 1 for iinsert\nEnter 2 for print\nEnter 3 for update\nEnter 4 for searching\nEnter 5 for delete\nEnter 6 for delete all\nEnter 7 for continue\nEnter 8 for traverse\nDefault is Break\n-----------\n Enter Operator :" << endl;
        cin >> operat;
        cout << "-----------" << endl;
        switch (operat)
        {
        case 1:
            int RNO;
            cout << "Roll NO : ";
            cin >> RNO;
            iinsert(&head, RNO);
            break;
        case 2:
            display(head);
            break;
        case 3:
            int toupdate;
            cout << "Enter update " << endl;
            cin >> toupdate;
            update(head, toupdate);
            break;
        case 4:
            int tosearch;
            cout << "Enter search " << endl;
            cin >> tosearch;
            search(head, tosearch);
            break;
        case 5:
            int todel;
            cout << "Enter todel " << endl;
            cin >> todel;
            del(&head, todel);
            break;
        case 6:
            alldel(&head);
            break;
        case 7:
            result = true;
            break;
        case 8:
            traverse(head);
            break;
        default:
            result = false;
            break;
        }
        cout << "-----------" << endl;
    }
    return 0;
}
