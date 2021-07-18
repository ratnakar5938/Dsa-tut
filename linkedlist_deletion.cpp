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

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = new Node();
    ptr = head->next;
    free(head);
    return ptr;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node *deleteOfKey(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != data && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == data)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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

    // traversal of the linkedlist
    linkedlist_traversal(head);
    cout << endl;

    // deleting first element of the linkedlist
    // head = deleteFirst(head);
    // linkedlist_traversal(head);
    // cout << endl;

    // deleting the element at a given index
    // head = deleteAtIndex(head, 2);
    // linkedlist_traversal(head);
    // cout << endl;

    // deleting the last element
    // head = deleteEnd(head);
    // linkedlist_traversal(head);
    // cout << endl;

    // deleting the element with given key
    head = deleteOfKey(head, 12);
    linkedlist_traversal(head);
    cout << endl;
    return 0;
}