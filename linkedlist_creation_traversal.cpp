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
    return 0;
}