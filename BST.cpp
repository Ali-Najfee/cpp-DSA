#include <iostream>
#include <cstdlib>
using namespace std;
struct Node
{
    int value;
    Node *right;
    Node *left;
};

Node *insert(Node *root, int target)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = target;
    temp->left=temp->right=NULL;
    if (!root)
        return temp;
    if (target < root->value)
        root->left = insert(root->left, target);
    else
    {
        root->right = insert(root->right, target);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}
int main()
{
    int arr[] = {3, 7, 4, 1, 6, 8};
    Node *root = NULL;
    for (int i = 0; i < 6; i++)
    {
        root = insert(root, arr[i]);
    }
    inorder(root);
    return 0;
}