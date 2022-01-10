#include <iostream>
#include <vector>

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

vector<Node *> constructBSTs(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSub = constructBSTs(start, i - 1);
        vector<Node *> rightSub = constructBSTs(i + 1, end);

        for (int j = 0; j < leftSub.size(); j++)
        {
            Node *left = leftSub[j];
            for (int k = 0; k < rightSub.size(); k++)
            {
                Node *right = rightSub[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        }
    }
    return trees;
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<Node *> totalTrees = constructBSTs(1, n);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << i + 1 << " : ";
        preOrder(totalTrees[i]);
        cout << endl;
    }

    return 0;
}