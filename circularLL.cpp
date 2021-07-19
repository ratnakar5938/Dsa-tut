#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void circularLL_traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        cout << "The element is " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = new Node();
    ptr->next = head;
    ptr->data = data;

    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    // p is at last node of circular linkedlist
    p->next = ptr;
    head = ptr;
    return head;
};

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = new Node();
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    ptr->data = data;
    p->next = ptr;
    return head;
}

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

    // link fourth to head
    fourth->data = 66;
    fourth->next = head;

    circularLL_traversal(head);
    cout << endl;

    head = insertAtFirst(head, 13);
    circularLL_traversal(head);
    cout << endl;

    head = insertAtEnd(head, 34);
    circularLL_traversal(head);
    cout << endl;

    head = insertAtIndex(head, 67, 3);
    circularLL_traversal(head);
    cout << endl;

    head = insertAfterNode(head, second, 39);
    circularLL_traversal(head);
    cout << endl;
    return 0;
}