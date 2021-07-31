#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insertAtTail(Node *&head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    while (head == NULL)
    {
        head = ptr;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}

int length(Node *head)
{
    Node *ptr = head;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}

void linkedlist_traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node *kAppend(Node *head, int k)
{
    Node *newHead;
    Node *newTail;
    Node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    Node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head, arr[i]);
    }
    linkedlist_traversal(head);
    cout << endl;
    Node *newHead = kAppend(head, 3);
    linkedlist_traversal(newHead);
    return 0;
}