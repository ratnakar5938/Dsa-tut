#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    int fill = 0;
    Node *top;
};

int isEmpty(Stack *ptr)
{
    if (ptr->top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(Stack *ptr)
{
    Node *n = new Node();
    if (n = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Node *push(Stack *ptr, int data)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "Stack overflow"
             << "\n";
        return ptr->top;
    }
    else
    {
        p->next = ptr->top;
        ptr->top = p;
        p->data = data;
        ptr->fill++;
        return ptr->top;
    }
}

Node *pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack underflow"
             << "\n";
        return ptr->top;
    }
    else
    {
        Node *p = ptr->top;
        cout << "Element poped: " << p->data << "\n";
        ptr->top = ptr->top->next;
        free(p);
        ptr->fill--;
        return ptr->top;
    }
}

void stack_traversal(Stack *ptr)
{
    Node *p = ptr->top;
    int i = 1;
    while (p != NULL)
    {
        cout << "Element at " << i << " is: " << p->data << endl;
        p = p->next;
        i++;
    }
}

void stackTop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "stack empty\n";
    }
    else
    {
        cout << "Topmost element: " << ptr->top->data << "\n";
    }
}

void stackBottom(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "stack empty\n";
    }
    else
    {
        Node *p = ptr->top;
        while (p->next != NULL)
        {
            p = p->next;
        }
        cout << "Bottom element: " << p->data << "\n";
    }
}

int peek(Stack *ptr, int pos)
{
    if (ptr->fill - pos < 0)
    {
        cout << "Invalid position\n";
        return -1;
    }
    else
    {
        Node *p = ptr->top;
        for (int i = 0; i < pos - 1 && p != NULL; i++)
        {
            p = p->next;
        }
        return p->data;
    }
}

int main()
{
    Stack *s;
    s->fill = 0;
    s->top = NULL;

    s->top = push(s, 13);
    s->top = push(s, 23);
    s->top = push(s, 24);
    s->top = push(s, 33);
    s->top = push(s, 43);

    stack_traversal(s);
    cout << "\n";

    pop(s);
    cout << "\n";

    stack_traversal(s);

    cout << "\n";

    stackTop(s);
    stackBottom(s);

    cout << "\n";
    for (int i = 1; i <= s->fill; i++)
    {
        cout << "element at " << i << ": " << peek(s, i) << "\n";
    }
    cout << "\n";
    // cout << "element at " << 3 << ": " << peek(s, 3) << "\n";
    return 0;
}