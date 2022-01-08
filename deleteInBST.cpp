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

Node *inorderSucc(Node *root)
{
    Node *current = root;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node *deleteNodeBST(Node *root, int key)
{
    if (root->data == key)
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteNodeBST(root->right, temp->data);
    }
    else if (root->data > key)
    {
        root->left = deleteNodeBST(root->left, key);
    }
    else
    {
        root->right = deleteNodeBST(root->right, key);
    }
    return root;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    inOrder(root);
    cout << endl;
    root = deleteNodeBST(root, 2);
    inOrder(root);
    return 0;
}