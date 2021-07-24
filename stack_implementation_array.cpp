#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
};

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stack_traversal(Stack *ptr)
{
    int pos = ptr->top;
    while (pos >= 0)
    {
        cout << "the element is: " << ptr->arr[pos] << endl;
        pos--;
    }
}

void push(Stack *ptr, int data)
{
    if (!isFull(ptr))
    {
        ptr->arr[ptr->top + 1] = data;
        ptr->top++;
    }
    else
    {
        cout << "Stack is full"
             << "\n";
    }
}

int main()
{
    Stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = new int[s->size];

    // pushing element manually
    s->arr[0] = 4;
    s->top++;
    s->arr[1] = 44;
    s->top++;
    s->arr[2] = 444;
    s->top++;
    s->arr[3] = 4444;
    s->top++;

    if (isEmpty(s))
    {
        cout << "Stack is empty"
             << "\n";
    }
    else
    {
        cout << "stack is not empty"
             << "\n";
    }
    if (isFull(s))
    {
        cout << "stack is full\n";
    }
    else
    {
        cout << "stack is not full\n";
    }
    cout << "\n";
    // cout << endl;
    cout << "stack before adding\n";
    stack_traversal(s);
    cout << "\n";
    push(s, 44444);
    cout << "stack after adding\n";
    stack_traversal(s);
    return 0;
}