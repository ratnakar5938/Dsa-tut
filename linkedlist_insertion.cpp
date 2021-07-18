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

// case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = new Node();
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// case 2
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = new Node();
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
    return head;
};

// case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = new Node();
    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    ptr->data = data;
    p->next = ptr;
    return head;
}

// case 4
struct Node *insertAfterNode(struct Node *head, struct Node *previous, int data)
{
    struct Node *ptr = new Node();
    ptr->next = previous->next;
    ptr->data = data;
    previous->next = ptr;
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

    // head = insertAtFirst(head, 56);
    // linkedlist_traversal(head);
    // cout << endl;

    // head = insertAtIndex(head, 77, 2);
    // linkedlist_traversal(head);
    // cout << endl;

    // head = insertAtEnd(head, 343);
    // linkedlist_traversal(head);
    // cout << endl;

    head = insertAfterNode(head, third, 44);
    linkedlist_traversal(head);
    return 0;
}