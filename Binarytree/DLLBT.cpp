#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int value;
    Node *right;
    Node *left;
};

Node *createBinaryTree()
{
    int value;
    cin >> value;
    if (value == -1)
    {
        return NULL;
    }
    Node *temp = new Node();
    temp->value = value;
    cout << "Enter left child of " << value << " :";
    temp->left = createBinaryTree(); // left
    cout << "Enter right child of " << value << " : ";
    temp->right = createBinaryTree(); // right
    return temp;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int size(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}

int sumOfNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return root->value + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void mirror(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirror(root->left);
    mirror(root->right);
}
int height(Node *root, bool &valid)
{
    if (root == NULL)
        return 0;
    int L = height(root->left, valid);
    if(valid)
        int R = height(root->right, valid);
        if (abs(L - R) > 1)
        valid = 0;
        return 1 + max(L, R);
    return-1;
    // return 1 + max(height(root->left), height(root->right));
}
int isBalanced(Node *root)
{
    bool valid = 1;
    height(root,valid);
    isBalanced(root, valid) return valid
}
int main()
{
    cout << "Enter root Node :";
    Node *root = createBinaryTree();
    cout << "Original binary tree:" << endl;
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << "\nSize of the binary tree: " << size(root) << endl;
    cout << "Total of the binary tree: " << sumOfNodes(root) << endl;
    cout << "Height of the binary tree: " << height(root) << endl;

    cout << "\nMirroring binary tree..." << endl;
    mirror(root);

    cout << "\nMirrored binary tree:" << endl;
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    isBalanced(root);

    return 0;
}
