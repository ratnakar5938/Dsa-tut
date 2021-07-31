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

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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

// iterative way

Node *merge(Node *&head1, Node *&head2)
{
    Node *ptr1 = head1;
    Node *ptr2 = head2;
    Node *dummyNode = new Node();
    Node *ptr3 = dummyNode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return dummyNode->next;
}

Node *mergeRec(Node *&head1, Node *&head2)
{
    Node *result;
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRec(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRec(head1, head2->next);
    }
    return result;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);
    display(head1);
    display(head2);
    // Node *newHead = merge(head1, head2);
    Node *newHead = mergeRec(head1, head2);
    display(newHead);
    return 0;
}