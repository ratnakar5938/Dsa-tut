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

bool isBSTsIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        if (root1->data != root2->data)
        {
            return false;
        }
        bool cond1 = isBSTsIdentical(root1->left, root2->left);
        bool cond2 = isBSTsIdentical(root1->right, root2->right);
        return cond1 && cond2;
    }
}

int main()
{
    Node *root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->left = new Node(2);
    root1->right->right = new Node(5);

    Node *root2 = new Node(1);
    root2->right = new Node(3);
    root2->right->left = new Node(2);
    root2->right->right = new Node(8);

    if (isBSTsIdentical(root1, root2))
    {
        cout << "Both BSTs are identical.\n";
    }
    else
    {
        cout << "BSTs are non-identical.\n";
    }

    return 0;
}