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
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

struct Node *reverseK(struct Node *head, int k)
{
    struct Node *prevptr = NULL;
    struct Node *current = head;
    struct Node *nextptr;

    int count = 0;
    while (current != NULL && count < k)
    {
        nextptr = current->next;
        current->next = prevptr;
        prevptr = current;
        current = nextptr;
        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverseK(nextptr, k);
    }

    return prevptr;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    // Allocating the memory for nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

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
    fourth->next = fifth;

    fifth->data = 43;
    fifth->next = sixth;

    sixth->data = 8;
    sixth->next = NULL;

    linkedlist_traversal(head);
    cout << endl;

    struct Node *newhead;
    newhead = reverseK(head, 2);
    linkedlist_traversal(newhead);
    return 0;
}