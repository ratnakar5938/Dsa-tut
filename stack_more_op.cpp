#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
};

// time complexity -> O(1)
int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

// time complexity -> O(1)
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

// time complexity -> O(1)
void push(Stack *ptr, int data)
{
    if (!isFull(ptr))
    {
        ptr->arr[ptr->top + 1] = data;
        ptr->top++;
    }
    else
    {
        cout << "Stack overflow\n"
             << "\n";
    }
}

// time complexity -> O(1)
void pop(Stack *ptr)
{
    if (!isEmpty(ptr))
    {
        int val = ptr->arr[ptr->top];
        ptr->arr[ptr->top] = 0;
        ptr->top--;
        cout << "element poped: " << val << "\n\n";
    }
    else
    {
        cout << "Stack underflow" << endl;
    }
}

// time complexity -> O(1)
int peek(Stack *ptr, int position)
{
    int arrInd = ptr->top - position + 1;
    if (arrInd < 0)
    {
        cout << "Not a valid position"
             << "\n";
        return -1;
    }
    else
    {
        return ptr->arr[arrInd];
    }
}

// time complexity -> O(1)
int stackTop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

// time complexity -> O(1)
int stackBottom(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty\n";
        return -1;
    }
    else
    {
        return ptr->arr[0];
    }
}

int main()
{
    Stack *s;
    s->size = 15;
    s->top = -1;
    s->arr = new int[s->size];
    push(s, 444444);
    push(s, 44444);
    push(s, 4444);
    push(s, 444);
    push(s, 44);
    push(s, 4);
    // push(s, 3);

    for (int j = 1; j <= s->top + 1; j++)
    {
        cout << "Element at position " << j << " is: " << peek(s, j) << "\n";
    }

    cout << "\n";

    cout << "Topmost element: " << stackTop(s) << "\n";
    cout << "Bottommost element: " << stackBottom(s) << "\n";

    return 0;
}