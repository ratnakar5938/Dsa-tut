#include <iostream>

using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;
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

void push(Stack *ptr, char data)
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

char pop(Stack *ptr)
{
    if (!isEmpty(ptr))
    {
        char val = ptr->arr[ptr->top];
        ptr->arr[ptr->top] = 0;
        ptr->top--;
        return val;
    }
    else
    {
        cout << "Stack underflow" << endl;
        return 'd';
    }
}

char stackTop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty\n";
        return 'd';
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char(sp->size);
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *exp = "{([8])+9}";

    if (parenthesisMatch(exp))
    {
        cout << "parenthesis balanced in the given expression\n";
    }
    else
    {
        cout << "parenthesis not balanced in the given expression\n";
    }
    return 0;
}