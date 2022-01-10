#include <iostream>
#include <stack>

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

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    stack<Node *> currentLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;
    currentLevel.push(root);
    while (!currentLevel.empty())
    {
        Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    zigzagTraversal(root);
    return 0;
}

//  given bst
//       1
//      / \
//     2   3
//      \   \
//       4   5
//      / \
//     6   7
//
// zig zag traversal => 1, 2, 3, 5, 4, 6 ,7