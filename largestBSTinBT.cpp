#include <iostream>
#include <climits>
#include <algorithm>

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

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MAX, INT_MIN, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }

    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);
    if (leftInfo.size > 0 && rightInfo.size > 0)
    {

        Info current;
        current.size = (1 + leftInfo.size + rightInfo.size);

        if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
        {
            current.min = leftInfo.min;
            current.max = rightInfo.max;
            current.ans = current.size;
            current.isBST = true;

            return current;
        }

        current.ans = max(leftInfo.ans, rightInfo.ans);
        current.isBST = false;
        return current;
    }
    else
    {
        if (leftInfo.size == 0)
        {
            Info current;
            current.size = (1 + rightInfo.size);

            if (rightInfo.isBST && rightInfo.min > root->data)
            {
                current.min = root->data;
                current.max = rightInfo.max;
                current.ans = current.size;
                current.isBST = true;

                return current;
            }

            current.ans = rightInfo.ans;
            current.isBST = false;
            return current;
        }
        else
        {

            Info leftInfo = largestBST(root->left);

            Info current;
            current.size = (1 + leftInfo.size);

            if (leftInfo.isBST && leftInfo.max < root->data)
            {
                current.min = leftInfo.min;
                current.max = root->data;
                current.ans = current.size;
                current.isBST = true;

                return current;
            }

            current.ans = leftInfo.ans;
            current.isBST = false;
            return current;
        }
    }
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << "Largest BST in BT : " << largestBST(root).ans << endl;
    return 0;
}