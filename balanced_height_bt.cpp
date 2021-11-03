#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

// time-complexity => O(n2)
bool isTreeBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (!isTreeBalanced(root->left))
    {
        return false;
    }
    if (!isTreeBalanced(root->right))
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// time complexity => O(n)
bool isBalanced(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (isBalanced(root->right, &rh) == false)
    {
        return false;
    }
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Building a tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->left->right = new Node(6);

    // if (isTreeBalanced(root1))
    // {
    //     cout << "Tree is balanced" << endl;
    // }
    // else
    // {
    //     cout << "Tree is not balanced" << endl;
    // }

    // if (isTreeBalanced(root2))
    // {
    //     cout << "Tree is balanced" << endl;
    // }
    // else
    // {
    //     cout << "Tree is not balanced" << endl;
    // }

    int height = 0;
    if (isBalanced(root2, &height))
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is unbalanced" << endl;
    }

    return 0;
}

// balanced height binary tree ==> binary tree whose absolute difference between heights of left subtree and right subtree is <= 1