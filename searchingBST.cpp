#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        return root;
    }
    else if (root->data > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

int main()
{
    int numbers[8] = {3, 7, 2, 1, 8, 5, 4, 6};
    Node *root = NULL;
    for (int i = 0; i < 8; i++)
    {
        root = insertBST(root, numbers[i]);
    }

    // inOrder(root);
    if (searchBST(root, 10) == NULL)
    {
        cout << "Key doesn't exist\n";
    }
    else
    {
        cout << "Key exists in the given BST\n";
    }
    return 0;
}