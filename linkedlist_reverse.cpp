#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedlist_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// iterative way
struct Node *linkedlist_reverse_iter(struct Node *head)
{
    struct Node *p = NULL;
    struct Node *q = head;
    struct Node *r;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}

// recursive way
struct Node *linkedlist_reverse_recur(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node *newHead = linkedlist_reverse_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating the memory for nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    // link first and second node
    head->data = 7;
    head->next = second;

    // link second to the third
    second->data = 12;
    second->next = third;

    // link third to forth
    third->data = 32;
    third->next = fourth;

    // link fourth to null
    fourth->data = 66;
    fourth->next = NULL;

    linkedlist_traversal(head);
    cout << endl;

    // head = linkedlist_reverse_iter(head);
    // linkedlist_traversal(head);
    // cout << endl;

    head = linkedlist_reverse_recur(head);
    linkedlist_traversal(head);
    cout << endl;
    return 0;
}