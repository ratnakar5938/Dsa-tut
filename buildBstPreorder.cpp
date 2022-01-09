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

Node *constructBST(int preorder[], int *preorderIndex, int key, int min, int max, int n)
{
    if (*preorderIndex >= n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIndex = *preorderIndex + 1;
        if (*preorderIndex < n)
        {
            root->left = constructBST(preorder, preorderIndex, preorder[*preorderIndex], min, key, n);
        }
        if (*preorderIndex < n)
        {
            root->right = constructBST(preorder, preorderIndex, preorder[*preorderIndex], key, max, n);
        }
    }
    return root;
}
// time complexity -> O(n)

void printPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int preOrder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preOrderIndex = 0;
    Node *root = constructBST(preOrder, &preOrderIndex, preOrder[0], INT_MIN, INT_MAX, n);
    printPreOrder(root);
    return 0;
}