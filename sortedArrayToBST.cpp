#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *sortedArrayToBST(int array[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(array[mid]);
    root->left = sortedArrayToBST(array, start, mid - 1);
    root->right = sortedArrayToBST(array, mid + 1, end);
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

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    Node *root = sortedArrayToBST(numbers, 0, 4);

    inOrder(root);
    cout << endl;
    preOrder(root);
    return 0;
}