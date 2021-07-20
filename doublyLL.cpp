#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void doublyLL_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *doublyLL_reverse(struct Node *head)
{

    struct Node *ptr = head;
    struct Node *q = new Node();
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    head = ptr;
    while (ptr != NULL)
    {
        q = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = q;
        ptr = ptr->next;
    }

    return head;
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = new Node();
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 5;
    head->prev = NULL;
    head->next = second;

    second->data = 53;
    second->prev = head;
    second->next = third;

    third->data = 32;
    third->prev = second;
    third->next = fourth;

    fourth->data = 73;
    fourth->prev = third;
    fourth->next = NULL;

    doublyLL_traversal(head);
    cout << endl;

    head = insertAtFirst(head, 77);
    doublyLL_traversal(head);
    cout << endl;

    head = doublyLL_reverse(head);
    doublyLL_traversal(head);
    cout << endl;

    return 0;
}