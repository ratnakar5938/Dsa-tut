#include <iostream>

using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
public:
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

Node *push(Stack *ptr, char data)
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
        ptr->top = ptr->top->next;
        free(p);
        return ptr->top;
    }
}

int parenthesisMatch(string exp)
{
    int n = exp.size();
    Stack *s;
    s->top = NULL;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(')
        {
            s->top = push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (!isEmpty(s))
            {
                s->top = pop(s);
            }
            else
            {
                return 0;
            }
        }
    }
    if (isEmpty(s))
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
    string exp = "(((8*)9($$$$--+++)))";

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