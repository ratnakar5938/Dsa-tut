#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void calcPointer(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointer(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointer(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// case 1 : Swapped elements are not adjacent to each other
// Strategy =>
// First -> Previous node where 1st number < previous
// Mid -> number where 1st number < previous
// Last -> 2nd node where number < previous
// Swap First - Last

// case 2 : Swapped elements are adjacent to each other
// Strategy =>
// First -> Previous node where 1st number < previous
// Mid -> number where 1st number < previous
// Last -> NULL
// Swap First - Mid

void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointer(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
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

int main()
{
    // case 1
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    inOrder(root);
    cout << endl;
    restoreBST(root);
    inOrder(root);
    cout << endl;

    // case 2
    Node *root2 = new Node(6);
    root2->left = new Node(4);
    root2->right = new Node(9);
    root2->left->left = new Node(1);
    root2->left->right = new Node(3);
    root2->right->right = new Node(13);

    inOrder(root2);
    cout << endl;
    restoreBST(root2);
    inOrder(root2);
    cout << endl;

    return 0;
}